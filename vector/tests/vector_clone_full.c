#include <stdlib.h>

#include "vector.h"

int main(void)
{
    struct vector *vector = vector_new(4);
    if (vector == NULL || vector->size || vector->capacity != 4)
        return EXIT_FAILURE;

    size_t a = 42;
    size_t b = 43;
    size_t c = 44;
    size_t d = 45;

    if (!vector_push_back(vector, &a))
        return EXIT_FAILURE;
    if (!vector_push_back(vector, &b))
        return EXIT_FAILURE;
    if (!vector_push_back(vector, &c))
        return EXIT_FAILURE;
    if (!vector_push_back(vector, &d))
        return EXIT_FAILURE;

    if (vector->size != 4)
        return EXIT_FAILURE;

    struct vector *clone = vector_clone(vector);
    if (clone == NULL || clone->size != 4 || clone->capacity != 4)
        return EXIT_FAILURE;

    for (size_t i = 0; i < vector->size; ++i)
        if (vector->data[i] != clone->data[i])
            return EXIT_FAILURE;

    vector_destroy(vector, NULL);
    vector_destroy(clone, NULL);
    return EXIT_SUCCESS;
}

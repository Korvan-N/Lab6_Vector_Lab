#ifndef VECTORS_H
#define VECTORS_H
typedef struct Vect
{
    char varname[100];
    float x, y, z;
} Vect;
extern Vect vectors[10];
/**
 * print vector info
 */
void print_info(Vect vect);

/**
 * handle a new vector entry
 */
int assign(Vect vect);

/**
 * return the index of the vector.
 */
int locate_vector(char* name);

/**
 * return vector at an index
 */
Vect get_vector(int index);

/**
 * clear the vector array
 */
void clear();

/**
 * list each vector in the vector array
 */
void list();
#endif // VECTORS_H
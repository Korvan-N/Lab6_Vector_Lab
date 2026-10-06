#include "mathfuncs.h"

Vect add(Vect a, Vect b)
{
    Vect returnval;
    returnval.x = a.x + b.x;
    returnval.y = a.y + b.y;
    returnval.z = a.z + b.z;
    return returnval;
}

Vect sub(Vect a, Vect b)
{
    Vect returnval;
    returnval.x = a.x - b.x;
    returnval.y = a.y - b.y;
    returnval.z = a.z - b.z;
    return returnval;
}

/**
 * Scalar multiplication
 * return vector
 */
Vect mul(float b, Vect a)
{
    Vect returnval;
    returnval.x = a.x * b;
    returnval.y = a.y * b;
    returnval.z = a.z * b;
    return returnval;
}

void dot(){

}
void cross(){

}
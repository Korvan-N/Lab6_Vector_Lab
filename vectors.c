#include "vectors.h"
#include <stdio.h>
#include <string.h>


Vect vectors[10];
static int vector_count = 0;
/**
 * print vector info
 */
void print_info(Vect vect){
    int i = locate_vector(vect.varname);
    if (i >= 0){ //print existing vector
        printf("vector: %s x: %.2f y: %.2fz: %.2f\n", vectors[i].varname, vectors[i].x, vectors[i].y, vectors[i].z);
    }
    else{ //print non-existing vector
        printf("x:%.2f y:%.2f z: %.2f\n", vect.x, vect.y, vect.z);
    }
}
/**
 * handle a new vector entry
 * return return status code
 */
int assign(Vect vect){
    int i = locate_vector(vect.varname);
    if(vector_count >= 10 && i == -1){ //if array is full and new vector created, return -1.
            return -1;
    }
    else if(i == -1){ // if no vector is in the array, create new entry.
        vectors[vector_count] = vect;
        vector_count += 1;
        return 0;
    }
    else{
        vectors[locate_vector(vect.varname)] = vect; //if vector name already exists, replace vector with the input.
    }
    return 1;
}
/**
 * return the index of the vector.
 */
int locate_vector(char* name){
    int i = vector_count - 1;
    while(i >= 0){
        if(strcmp(vectors[i].varname, name) == 0){
            return i;
        }
        i--;
    }
    return -1;
}

/**
 * vector getter
 */
Vect get_vector(int index){
    return vectors[index];
}

/**
 * clear the vector array
 */
void clear(){
    memset(vectors, 0, sizeof(vectors));
    vector_count = 0;
}

/**
 * list each vector in the vector array
 */
void list(){
    if(vector_count == 0){
        printf("empty list. \n");
    }
    else{
        int i = 0;
        for(; i < vector_count; i++){
            print_info(vectors[i]);
        }
        // for(; i < 10; i++){
        //     printf("<empty>\n");
        // }
    }
    
}
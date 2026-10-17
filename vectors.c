#include "vectors.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Vect *vectors;
static int vector_count = 0;
/**
 * print vector info
 */
void print_info(Vect vect){
    int i = locate_vector(vect.varname);
    if (i >= 0){ //print existing vector
        printf("vector: %s x: %.2f y: %.2f z: %.2f\n", vectors[i].varname, vectors[i].x, vectors[i].y, vectors[i].z);
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
    if(i == -1){ //if array is full and new vector created, reallocate.
        vectors = realloc(vectors, sizeof(Vect)*(vector_count+1));
        if(vectors == NULL){ // if reallocation fails then exit
            printf("failed to reallocate.\n");
            return -1;
        }
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
    free(vectors);
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

/**
 * free memory
 */
void quit(){
    free(vectors);
    exit(0);
}

/**
 * load parameters from .csv
 */
void load(char* name){
    FILE *file_ptr;
    file_ptr = fopen(name, "r");
    if(file_ptr == NULL){
        printf("File not found: '%s'\n", name);
    }
    else{
        char buf[100];
        Vect vect;
        float value1;
        float value2;
        float value3;
        while(fgets(buf, sizeof(buf), file_ptr) != NULL){
            if(strcmp(buf, "\n") && strcmp(buf, "\r\n")){
                char* tok = strtok(buf, ",");
                strcpy(vect.varname, tok);
                char* rest = strtok(NULL, "");
                sscanf(rest, "%f,%f,%f", &value1, &value2, &value3);
                vect.x = value1;
                vect.y = value2;
                vect.z = value3;
                assign(vect);
            }
        }
        printf("file loaded from '%s'\n", name);
        fclose(file_ptr);
        list();
    }
}

/**
 * save parameters to .csv
 */
void save(char* name){
    FILE *file_ptr = fopen(name, "w");
    if(file_ptr != NULL){
        for(int i = 0; i < vector_count; i++){
            fprintf(file_ptr, "%s,%.02f,%.02f,%.02f\n", vectors[i].varname, vectors[i].x, vectors[i].y, vectors[i].z);
        }
        fclose(file_ptr);
        printf("saved vectors to '%s'\n", name);
    }
    else{
        printf("file failed to save.\n");
    }
}
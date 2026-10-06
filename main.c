#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"
#include "mathfuncs.h"
#include <string.h>

char input[100];
char name1[100];
char name2[100];
char name3[100];
int index1, index2, index3, index4;
float value1, value2, value3;
char op;
Vect vect;

void clear_inputs();
int main(int argc, char* argv[]){
    
    printf("MINILAB\n");
    if(argc == 2 && (strcmp(argv[1], "-h") == 0)){
        printf("valid commands:\n");
        printf("▪ vector = float, float, float\n");
        printf("▪ vector + vector\n");
        printf("▪ vector - vector\n");
        printf("▪ vector * float\n");
        printf("▪ float * vector\n");
        printf("▪ vector = vector (+ -) vector\n");
        printf("▪ vector = vector * float\n");
        printf("▪ clear\n▪ list\n▪ quit\n");
        printf("▪ note: spaces are REQUIRED around equal signs.\n");
        printf("▪ note: max 100 characters per line.\n");
    }

    while(1){
        printf("minimat >");
        fgets(input, sizeof(input), stdin);
        clear_inputs();
        //operation assignment (*)
        if(sscanf(input, "%s = %s * %f", name1, name2, &value1) == 3 ||
            sscanf(input, "%s = %f * %s", name1, &value1, name2) == 3){
            int index1 = locate_vector(name1);
            int index2 = locate_vector(name2);
            if(index1 > -1 && index2 > -1){
                vect = mul(value1, get_vector(index2));
                strcpy(vect.varname, name1);
                assign(vect);
                printf("output ");
                print_info(vect);
            }
            else{
                printf("INVALID input.\n"); 
            }
        }
        //operation assignment (+, -)
        if(sscanf(input, "%s = %s %c %s", name1, name2, &op, name3) == 4 && (op == '+' || op == '-')){
            int index1 = locate_vector(name1);
            int index2 = locate_vector(name2);
            int index3 = locate_vector(name3);
            if(index1 > -1 && index2 > -1 && index3 > -1){
                if(op == '+'){
                    vect = add(get_vector(index2), get_vector(index3));
                    strcpy(vect.varname, name1);
                    assign(vect);
                    printf("%s: ", name1);
                    print_info(vect);
                }
                else if(op == '-'){
                    vect = add(get_vector(index2), get_vector(index3));
                    strcpy(vect.varname, name1);
                    assign(vect);
                    printf("%s: ", name1);
                    print_info(vect);
                }
            }
            else{
                printf("INVALID input.\n"); 
            }
        }
        //assignment
        else if(sscanf(input, "%s = %f %f %f", name1, &value1, &value2, &value3) == 4 ||
                sscanf(input, "%s = %f, %f, %f", name1, &value1, &value2, &value3) == 4){
            strcpy(vect.varname, name1);
            vect.x = value1;
            vect.y = value2;
            vect.z = value3;
            index1 = assign(vect);
            if(index1 == -1){
                printf("array is full.\n");
            }
            else if(index1 == 0){
                printf("new entry created.\n");
            }
            else{
                printf("vector exists; values updated.\n");
            }
        }
        //operation
        else if(sscanf(input, "%f %c %s", &value1, &op, name1) == 3||
                sscanf(input, "%s %c %f", name1, &op, &value1) == 3 ||
                sscanf(input, "%s %c %s", name1, &op, name2) == 3){
            index1 = locate_vector(name1);
            index2 = locate_vector(name2);
            if(index1 > -1){
                if(op == '*'){
                    vect = mul(value1, get_vector(index1));
                    printf("%s * %.2f = ", get_vector(index1).varname, value1);
                    print_info(vect);
                }
                else if(index2 > -1){
                    if(op == '+'){
                        vect = add(get_vector(index1), get_vector(index2));
                        printf("%s + %s = ", get_vector(index1).varname, get_vector(index2).varname);
                        print_info(vect);
                    }
                    if(op == '-'){
                        vect = sub(get_vector(index1), get_vector(index2));
                        printf("%s - %s = ", get_vector(index1).varname, get_vector(index2).varname);
                        print_info(vect);
                    }
                }
                else{
                    printf("INVALID command.\n");
                }
            }
        }
        else if(sscanf(input, "%s", name1) == 1){
            if(!strcmp(name1, "clear")){
                clear();
            }
            else if(!strcmp(name1, "quit")){
                printf("program exited.\n");
                break;
            }
            else if(!strcmp(name1, "list")){
                list();
            }
            else{
                printf("INVALID command.\n");
            }
        }

    }
    return 0;
}

void clear_inputs(){
    memset(name1, 0, sizeof(name1));
    memset(name2, 0, sizeof(name2));
    memset(name3, 0, sizeof(name3));
    index1 = 0;
    index2 = 0;
    index3 = 0;
    value1 = 0;
    value2 = 0;
    value3 = 0;
}
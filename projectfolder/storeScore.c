#include<stdio.h>
#include<stdlib.h>
void main(){
    char file_name= "score.txt";
    FILE* file = fopen(file_name,'a');
    fprintf(file,"%s",file_name);


}
/*
** Copyright (c) 2018 Arm Limited. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char c[1000];
    FILE *fout;
    FILE *fptr;

    printf("argc: %d argv: %s\n",argc,argv[0]);
    if (argc != 1)
    {
        printf("enter input file as command line argument\n");
        exit(-1);
    }

    fout = fopen("logfile", "w+");
    fprintf(fout, "This is the test logfile: \n");

    if ((fptr = fopen(argv[0], "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }

    // reads text until newline 
    fscanf(fptr,"%[^\n]", c);

    printf("Data from the file:\n%s", c);
    fclose(fptr);
    
    fputs("program complete", fout);
    fclose(fout);

    printf("\nprogram complete\n");
    exit(0);
}

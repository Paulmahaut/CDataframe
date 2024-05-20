//
// Created by abdel
//
#include "column.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define REALOC_SIZE 256


COLUMN *create_column(char *titre)
{

    COLUMN *p = (COLUMN*)malloc(sizeof (COLUMN));
    // Title
    strcpy(p->title,titre);
    // Logical size
    p->LS = 0;
    // Physical size
    p->PS = 0;
    // Sets the pointer to int array
    p->data = NULL;

    return p;

}

int insert_value(COLUMN *col, int value)
{
    // If physical size is 0
    if (col->PS == 0)
    {
        // Reserve the memory
        col->data = (int *) malloc(REALOC_SIZE * sizeof(int));

        if (col->data == NULL)
        {
            // Memory allocation failed
            return 0;
        }

        // Update physical size
        col->PS = REALOC_SIZE;
    }

    // Check if logical size is bigger than physical size
    else if (col->LS >= col->PS)
    {
        // Realloc memory for int array
        int new_PS = col->PS + REALOC_SIZE;

        int *new_data = (int *)realloc(col->data, new_PS * sizeof(int));

        if (new_data == NULL)
        {
            // Realloc failed
            return 0;
        }

        // Update the changes

        col->data = new_data;
        col->PS = new_PS;
    }
    // Insert value into array
    col->data[col->LS] = value;
    col->LS = col ->LS + 1;
    //realloc success
    return 1;
}


void delete_column(COLUMN **col)
{

    // Free the array
    free((*col)->data);

    // Free the instance of the COLUMN structure col


    free(*col);

    // Set col pointer to NULL so we don't have hanging pointers
    *col = NULL;
}

void print_col(COLUMN *col)
{
//    printf("Data incoming");
    printf("Column title: %s\n", col->title);
    for (int i = 0; i < col->LS; i++)
    {
        printf("[%d]: %d\n", i, col->data[i]);
    }
}

int occurence_x(COLUMN* col, int x)
{
    int occu = 0;
    int i = 0;

    // We search for x in the elements of the array
    for (i;i<col->LS;i++)
    {
        if(col->data[i] == x)
        {
            occu++;
        }
    }
    return occu;
}

int return_value(COLUMN* col,int x)
{
    int value = 0;
    // We check for valid index
    if (x < 0 || x>=col->LS)
    {
        return -1;
    }
    else
    {
        value = col->data[x];
    }
    return value;
}

int occurences_greater_x (COLUMN* col,int x)
{
    int occu = 0;
    int i = 0;

    // We search for values greater than x in the elements of the array
    for (i;i<col->LS;i++)
    {
        if(col->data[i] > x)
        {
            occu++;
        }
    }
    return occu;
}


int occurences_lower_x (COLUMN* col,int x)
{
    int occu = 0;
    int i = 0;

    // We search for values greater than x in the elements of the array
    for (i;i<col->LS;i++)
    {
        if(col->data[i] < x)
        {
            occu++;
        }
    }
    return occu;
}

int* index_equal_x(COLUMN * col, int x)
{
    int* index;
    int occu=0;
    index = (int*) malloc(col->LS * sizeof(int));
    int i = 0;

    // We search for values equal to x in the elements of the array
    for (i;i<col->LS;i++)
    {
        if(col->data[i] == x)
        {
            index[occu++] =i;
        }
    }
    return index;
}

int* index_greater_x (COLUMN* col,int x)
{
    int* index;
    int occu=0;
    index = (int*) malloc(col->LS * sizeof(int));
    int i = 0;

    // We search for values greater than x in the elements of the array
    for (i;i<col->LS;i++)
    {
        if(col->data[i] > x)
        {
            index[occu++] = i;
        }
    }
    return index;
}


int* index_lower_x (COLUMN* col,int x)
{
    int* index;
    int occu=0;
    index = (int*) malloc(col->LS * sizeof(int));
    int i = 0;

    // We search for values lower than x in the elements of the array
    for (i;i<col->LS;i++)
    {
        if(col->data[i] > x)
        {
            index[occu++] = i;
        }
    }
    return index;
}

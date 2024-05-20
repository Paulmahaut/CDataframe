#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

CDataframe* create_cdataframe(int capacity) {
    CDataframe* df = (CDataframe*)malloc(sizeof(CDataframe));
    if (df == NULL) {
        return NULL;  // Gestion d'erreur de l'allocation mémoire
    }
    df->columns = malloc(sizeof(COLUMN*) * capacity);
    if (df->columns == NULL) {
        free(df);
        return NULL;
    }
    df->num_columns = 0;
    df->capacity = capacity;
    return df;
}

void add_column(CDataframe* df, COLUMN* col) {
    if (df->num_columns >= df->capacity) {
        // Réallocation pour agrandir le tableau de colonnes
        int new_capacity = df->capacity * 2;
        COLUMN** new_columns = realloc(df->columns, sizeof(COLUMN*) * new_capacity);
        if (new_columns == NULL) {
            return;  // Gestion d'erreur ici
        }
        df->columns = new_columns;
        df->capacity = new_capacity;
    }
    df->columns[df->num_columns++] = col;
}

int delete_row_CD(CDataframe* df, int index)
{
    //Check if index is invalid (negative or greater or equal than the logical size of all columns)

    for(int i=0; i<index;i++)
    {
        if (df->columns[0]->LS <= index)
            return 0;
    }
    if (index < 0 || (df->num_columns < 0))
    {
        return 0;
    }

    for (int i = 0; i < df->num_columns; ++i) {
        COLUMN* column = df->columns[i];

        // Shift elements up to overwrite the deleted row
        for (int j = index; j < column->LS - 1; ++j) {
            column->data[j] = column->data[j + 1];
        }

        // Decrement size of column
        column->LS--;
    }
    return 1;
}

int delete_column_CD(CDataframe* df, int index)
{
    // Check if the index is good
    if (index < 0 || index >= df->num_columns)
    {
        return 0;
    }

    // Free the memory to delete the column
    free(df->columns[index]->data);
    free(df->columns[index]);

    // Fill the gap in the array
    for (int i = index; i < df->num_columns - 1; i++)
    {
        df->columns[i] = df->columns[i + 1];
    }

    // Decrement the number of columns
    df->num_columns--;
    return 1;
}

void print_cdataframe(CDataframe* df) {
    printf("CDataframe with %d columns:\n", df->num_columns);
    for (int i = 0; i < df->num_columns; i++) {
        print_col(df->columns[i]);
    }
}

void free_cdataframe(CDataframe* df) {
    for (int i = 0; i < df->num_columns; i++) {
        delete_column(&(df->columns[i]));
    }
    free(df->columns);
    free(df);
}

void print_column_by_index(CDataframe* df, int index) {
    if (index < 0 || index >= df->num_columns) {
        printf("Invalid column index.\n");
        return;
    }

    COLUMN* col = df->columns[index];
    printf("Column '%s':\n", col->title);
    for (int i = 0; i < col->LS; i++) {
        printf("%d\n", col->data[i]);
    }
}


void display_the_numbers_of_rows(CDataframe* df) {
    int max = 0;
    for (int i = 0; i < df->num_columns; i++) {
        if (df->columns[i]->LS > max) {
            max = df->columns[i]->LS;
        }
    }
    printf("The number of rows is %d\n", max);
}

void display_the_numbers_of_columns(CDataframe* df) {
    printf("The number of columns is %d\n", df->num_columns);
}


void display_the_numbers_of_cells_equal_to_x(CDataframe* df, int x) {
    int count = 0;
    for (int i = 0; i < df->num_columns; i++) {
        for (int j = 0; j < df->columns[i]->LS; j++) {
            if (df->columns[i]->data[j] == x) {
                count++;
            }
        }
    }
    printf("The number of cells equal to %d is %d\n", x, count);
}

void display_the_numbers_of_cells_greater_than_x(CDataframe* df, int x) {
    int count = 0;
    for (int i = 0; i < df->num_columns; i++) {
        for (int j = 0; j < df->columns[i]->LS; j++) {
            if (df->columns[i]->data[j] > x) {
                count++;
            }
        }
    }
    printf("The number of cells greater than %d is %d\n", x, count);
}

void display_the_numbers_of_cells_less_than_x(CDataframe* df, int x) {
    int count = 0;
    for (int i = 0; i < df->num_columns; i++) {
        for (int j = 0; j < df->columns[i]->LS; j++) {
            if (df->columns[i]->data[j] < x) {
                count++;
            }
        }
    }
    printf("The number of cells less than %d is %d\n", x, count);
}
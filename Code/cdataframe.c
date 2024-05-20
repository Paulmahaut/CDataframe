#include "cdataframe.h"
#include "column.h"
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
    if (index < 0 || (df->num_columns < 0))
    {
        return 0;
    }

    for(int i=0; i<index;i++)
    {
        if (df->columns[i]->LS <= index)
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

        count += occurence_x(df->columns[i], x);
    }
    printf("The number of cells equal to %d is %d\n", x, count);
}

void display_the_numbers_of_cells_greater_than_x(CDataframe* df, int x) {
    int count = 0;
    for (int i = 0; i < df->num_columns; i++) {
        // We can use the function that we previously created
        count += occurences_greater_x(df->columns[i], x);
    }
    printf("The number of cells greater than %d is %d\n", x, count);
}

void display_the_numbers_of_cells_less_than_x(CDataframe* df, int x) {
    int count = 0;
    for (int i = 0; i < df->num_columns; i++) {
            count += occurences_lower_x(df->columns[i], x);

    }
    printf("The number of cells less than %d is %d\n", x, count);
}

int existence_of_x(CDataframe* df, int x)
{
    int count = 0;
    for (int i = 0; i < df->num_columns; i++) {
            count += occurence_x(df->columns[i], x);

    }
    if (!count)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int replace_value_CD(CDataframe* df, int row, int col, int x) {

    if (x < 0 || (df->num_columns < 0)) {
        return 0;
    }
    for (int i = 0; i < row; i++) {
        if (df->columns[i]->LS < row)
            return 0;
    }

    df->columns[row]->data[col] = x;
    return 1;
}


void hard_fill(CDataframe* df)
{
    COLUMN* col1= create_column("COL1");
    COLUMN* col2 = create_column("COL2");
    COLUMN * col3 = create_column("COL3");
    COLUMN* col4 = create_column("COL4");
    for (int i=0; i<5; i++)
    {
        insert_value(col1, i);
        insert_value(col2, 4+i);
        insert_value(col3, 9+i);
        insert_value(col4, 14+i);
    }
    add_column(df, col1);
    add_column(df,col2);
    add_column(df,col3);
    add_column(df, col4);
}
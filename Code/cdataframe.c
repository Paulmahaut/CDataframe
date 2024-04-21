#include "cdataframe.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
CDataframe* create_cdataframe(int capacity) {
    CDataframe* df = (CDataframe*)malloc(sizeof(CDataframe));
    if (df == NULL) {
        return NULL;
    }
    return df;
}

void print_cdataframe(CDataframe* df) {
    if (df == NULL || df->num_columns == 0) {
        printf("Le dataframe est vide ou nul.\n");
        return;
    }

    // Print column headers
    for (int i = 0; i < df->num_columns; ++i) {
        printf("%s\t", df->columns[i]->title);  // Use \t for tabular display
    }
    printf("\n");

    // Get the number of rows using the logical size of the first column
    int num_rows = df->columns[0]->LS;

    // Print the content of each row
    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < df->num_columns; ++col) {
            // Make sure the column has enough data for this row
            if (row < df->columns[col]->LS) {
                printf("%d\t", df->columns[col]->data[row]);
            } else {
                printf("NULL\t");  // If there is no data for this row in the column
            }
        }
        printf ("\n");  // New line after each data row
    }
}



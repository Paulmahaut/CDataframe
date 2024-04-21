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

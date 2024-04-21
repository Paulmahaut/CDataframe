#include <stdio.h>
#include "column.c"
#include "cdataframe.c"
int main()
{
    int o;
    COLUMN *mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 66);
    insert_value(mycol, 1);
    insert_value(mycol, 2);
    insert_value(mycol, 3);
    insert_value(mycol, 4);
    insert_value(mycol, 5);
    insert_value(mycol, 6);
    print_col(mycol);
//////////////////////////////////////////////////////////////

    int initial_capacity = 10;
    CDataframe* df = create_cdataframe(initial_capacity);

    if (df != NULL) {
        printf("CDataframe a été créé avec succès.\n");

        for (int i = 0; i < initial_capacity; i++) {
            char column_name[30];
            sprintf(column_name, "Colonne %d", i + 1);
            COLUMN* col = create_column(column_name);
        }

        print_cdataframe(df);

    } else {
        printf("Échec de la création du CDataframe.\n");
    }

    return 0;
}
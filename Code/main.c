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

    int initial_capacity = 10; // Capacité initiale pour le nombre de colonnes
    CDataframe* df = create_cdataframe(initial_capacity);

    if (df != NULL) {
        printf("CDataframe a été créé avec succès.\n");

        // Test d'ajout de colonnes (exemple)
        for (int i = 0; i < initial_capacity; i++) {
            // Supposons que vous avez une fonction add_column.
            char column_name[30];
            sprintf(column_name, "Colonne %d", i + 1);
            COLUMN* col = create_column(column_name);
        }

        // Test d'affichage des informations du dataframe
        // Supposons que vous avez une fonction qui imprime les informations du dataframe.
        print_cdataframe(df); // Vous devrez implémenter cette fonction.

    } else {
        printf("Échec de la création du CDataframe.\n");
    }

    return 0;

}

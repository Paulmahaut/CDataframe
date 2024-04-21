#include <stdio.h>
#include "column.c"

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
    return 0;
}

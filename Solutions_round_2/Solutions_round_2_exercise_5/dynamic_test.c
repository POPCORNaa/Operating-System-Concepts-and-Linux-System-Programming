#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 10;
    int *table;

    table = (int * )malloc(n * sizeof(int));

    if (table == NULL){
        printf("Memory allocation faild!\n");
        return 1;

    }

    for (int i = 0; i < n; i++){
        table[i] = i + 1;
    }

    printf("Contents of the dynamic table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");

    free(table);
    table = NULL;

    return 0;

}
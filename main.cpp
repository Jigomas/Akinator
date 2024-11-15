#include <stdio.h>



#include "tree.h"
#include "deciding_alg.h"


int main(int argc, char* argv[]) {
    tree_t *tree = NULL;

    //tree = TreeAddNoAsking(tree, 5, LeftIsSmaller); //where to add, what to add, function of choosing how to add
    //tree = TreeAddNoAsking(tree, 3, LeftIsSmaller);
    //tree = TreeAddNoAsking(tree, 6, LeftIsSmaller);
    //tree = TreeAddNoAsking(tree, 1, LeftIsSmaller);
    tree = TreeAddWithAsking(tree, 5, YesOrNo);
    tree = TreeAddWithAsking(tree, 3, YesOrNo);
    tree = TreeAddWithAsking(tree, 6, YesOrNo);
    tree = TreeAddWithAsking(tree, 7, YesOrNo);
    tree = TreeAddWithAsking(tree, 9, YesOrNo);
/*
    int max_depth = 10;

    int *list_of_levels = ListOfLevelsCtor(max_depth);

    TreePrint(tree, 0, &list_of_levels); //what to print, and where to start

    for (int i = 0; i < max_depth; i++)
        printf("%d\n", list_of_levels[i]);
    printf("***************\n");
*/
    TreeDtor(tree);
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"
#include "verificator.h"


tree_t *TreeCtor(int value) {
    tree_t *tree = (tree_t *)calloc(1, sizeof(tree_t));

    tree->data   = value;
    tree->left   = NULL;
    tree->right  = NULL;

    tree->code_of_program = ALL_GOOD;
    return tree;
}



void TreeDtor(tree_t *tree) {
    if (tree) {
        TreeDtor(tree->left);
        TreeDtor(tree->right);
    }

    free(tree);
}



tree_t *TreeAddNoAsking(tree_t *tree, int value, comparing_is_smaller_t *comparing_alg) {
    if (!tree)
        return TreeCtor(value);

    Verificator(tree);

    int result_of_comparement = ERROR;

    result_of_comparement = comparing_alg(value, tree->data);

    if (result_of_comparement == LEFT)
        tree->left  = TreeAddNoAsking(tree->left, value, comparing_alg);

    else if (result_of_comparement == RIGHT)
        tree->right = TreeAddNoAsking(tree->right, value, comparing_alg);

    else tree->code_of_program = ERROR;

    return tree;
}

tree_t *TreeAddWithAsking(tree_t *tree, int value, comaring_with_asking_t *comparing_alg) {
    if (!tree)
        return TreeCtor(value);

    Verificator(tree);

    int result_of_comparement = ERROR;

    result_of_comparement = comparing_alg(tree, value);

    if (result_of_comparement == LEFT)
        tree->left  = TreeAddWithAsking(tree->left, value, comparing_alg);

    else if (result_of_comparement == RIGHT)
        tree->right = TreeAddWithAsking(tree->right, value, comparing_alg);

    else tree->code_of_program = ERROR;

    return tree;
}


tree_t *TreePrint(tree_t *tree, int level, int **list_of_levels) {

    if (!tree)
        return tree;

    if (!list_of_levels) {
        assert(0);
        return 0;
    }

    Verificator(tree);
    //todo fixit
    //*(list_of_levels[level]) ++;


    printf("tree[%p] %*stree.data = %d tree.left[%p] tree.right[%p]\n",
                 tree, 9 * level, "", tree->data, tree->left, tree->right);


    TreePrint(tree->left,  level + 1, list_of_levels);
    TreePrint(tree->right, level + 1, list_of_levels);

    return tree;
}



tree_t *TheBracketPrinting(tree_t *tree, int order) {
    if (!tree)
        return tree;

    Verificator(tree);

    printf("( ");

    if (order == PRE_ORDER)
        printf("%d ", tree->data);

    TheBracketPrinting(tree->left, order);

    if (order == IN_ORDER)
        printf("%d ", tree->data);

    TheBracketPrinting(tree->right, order);

    if (order == POST_ORDER)
        printf("%d ", tree->data);

    printf(") ");

    return tree;
}



tree_t *SearchInTheTree(tree_t *tree, int value) {
    if (!tree)
        return NULL;

    Verificator(tree);

    if (tree->data == value)
        return tree;

    tree_t *left = SearchInTheTree(tree->left, value);

    if (left)
        return left;

    tree_t *right = SearchInTheTree(tree->right, value);

    if (right)
        return right;

    return NULL;
}



int *ListOfLevelsCtor(int max_depth) {
    int *list_of_levels = (int *)calloc(max_depth, sizeof(int));

    for (int i = 0; i < max_depth; i++)
        list_of_levels[i] = 0;

    return list_of_levels;
}







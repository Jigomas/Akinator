#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"
#include "verificator.h"


tree_t *TreeCtor(char value[LEN_OF_DATA], int depth, int history[MAX_DEPTH]) {
    tree_t *tree = (tree_t *)calloc(1, sizeof(tree_t));

    tree->data   = (char *)calloc(1, LEN_OF_DATA);
    for (int i = 0; i < LEN_OF_DATA; i++)
        tree->data[i] = value[i];

    tree->left   = NULL;
    tree->right  = NULL;

    tree->depth   = depth;

    tree->history = (int *)calloc(1, MAX_DEPTH);
    for (int i = 0; i < MAX_DEPTH; i++)
        tree->history[i] = history[i];

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


/*
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
*/



tree_t *TreeAddNoAsking(tree_t *tree, char value[LEN_OF_DATA], comaring_no_asking_t *comparing_alg, int depth, int history[MAX_DEPTH]) {
    if (!tree)
        return TreeCtor(value, depth, history);

    Verificator(tree);

    int result_of_comparement = ERROR;

    result_of_comparement = comparing_alg(tree, depth);

    if (result_of_comparement == LEFT) {
        TreeAddNoAsking(tree->left, value, comparing_alg, depth + 1, history);
    }

    else if (result_of_comparement == RIGHT) {
        printf("234\n");
        tree->right = TreeAddNoAsking(tree->right, value, comparing_alg, depth + 1, history);
    }

    else tree->code_of_program = ERROR;

    return tree;
}



tree_t *TreeAddWithAsking(tree_t *tree, char value[LEN_OF_DATA], comaring_with_asking_t *comparing_alg, int depth, int history[MAX_DEPTH]) {
    if (!tree)
        return TreeCtor(value, depth, history);

    Verificator(tree);

    int result_of_comparement = ERROR;

    result_of_comparement = comparing_alg(tree, value);

    if (result_of_comparement == LEFT) {
        history[depth] = 1;
        tree->left  = TreeAddWithAsking(tree->left, value, comparing_alg, depth + 1, history);
    }

    else if (result_of_comparement == RIGHT) {
        history[depth] = 0;
        tree->right = TreeAddWithAsking(tree->right, value, comparing_alg, depth + 1, history);
    }

    else tree->code_of_program = ERROR;

    return tree;
}



tree_t *TreeAsking(tree_t *tree, char ancestor[LEN_OF_DATA], comaring_with_asking_t *comparing_alg, int depth, int history[MAX_DEPTH]) {
    if (!tree) {
        if (ancestor[0] != 'I' && ancestor[1] != 'T')
            printf("%s\n", ancestor);

        else {
            printf("%s\n", "IM STUPID");

            fprintf(stderr, "Please print What is IT\n");

            int read_sth   = 0;
            char  value[LEN_OF_DATA] = {};

            read_sth = scanf("%s", value);
            return TreeCtor(value, depth, history);

        }
        return tree;
    }

    Verificator(tree);

    int result_of_comparement = ERROR;

    char value[LEN_OF_DATA] = "IT";

    result_of_comparement = comparing_alg(tree, value);

    if (result_of_comparement == LEFT) {
        history[depth] = 1;
        tree->left = TreeAsking(tree->left, tree->data, comparing_alg, depth + 1, history);
    }

    else if (result_of_comparement == RIGHT) {
        history[depth] = 0;
        tree->right = TreeAsking(tree->right, value, comparing_alg, depth + 1, history);
    }

    else {
        tree->code_of_program = ERROR;
        printf("%s\n", "FUCK YOU!");
    }

    return tree;
}







tree_t *TreePrint(tree_t *tree) {

    if (!tree)
        return tree;

    Verificator(tree);
    //todo fixit
    //*(list_of_levels[tree->depth]) ++;


    printf("tree[%p] %*stree.data = %s tree.left[%p] tree.right[%p]",
                 tree, 9 * tree->depth, "", tree->data, tree->left, tree->right);

    for (int i = 0; i < MAX_DEPTH; i++)
        printf("%d", tree->history[i]);
    printf("\n");

    TreePrint(tree->left);
    TreePrint(tree->right);

    return tree;
}



tree_t *TheBracketPrinting(tree_t *tree, int order) {
    if (!tree)
        return tree;

    Verificator(tree);

    printf("( ");

    if (order == PRE_ORDER)
        printf("%s ", tree->data);

    TheBracketPrinting(tree->left, order);

    if (order == IN_ORDER)
        printf("%s ", tree->data);

    TheBracketPrinting(tree->right, order);

    if (order == POST_ORDER)
        printf("%s ", tree->data);

    printf(") ");

    return tree;
}



tree_t *SearchInTheTree(tree_t *tree, char value[LEN_OF_DATA]) {
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


/*
int *ListOfLevelsCtor(int max_depth) {
    int *list_of_levels = (int *)calloc(max_depth, sizeof(int));

    for (int i = 0; i < max_depth; i++)
        list_of_levels[i] = 0;

    return list_of_levels;
}
*/






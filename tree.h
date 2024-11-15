#ifndef TREE
#define TREE



typedef int comparing_is_smaller_t(const int a, const int b);

typedef int comaring_with_asking_t(struct tree_t *tree, int value);

struct tree_t
{
    int data;
    tree_t *left;
    tree_t *right;

    int code_of_program;
};



enum order_of_writing
{
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER
};



enum results_of_comparement
{
    LEFT  =  1,
    RIGHT =  0,
    ERROR_COMPAREMENT = -1,
};



enum all_exit_codes {
    ALL_GOOD = 1,
    ERROR    = 0,
};



tree_t *TreeCtor(int value);

void TreeDtor(tree_t *tree);

tree_t   *TreeAddNoAsking(tree_t *tree, int value, comparing_is_smaller_t *comparing_alg);

tree_t *TreeAddWithAsking(tree_t *tree, int value, comaring_with_asking_t *comparing_alg);

tree_t *SearchInTheTree(tree_t *tree, int value);

tree_t *TreePrint(tree_t *tree, int level, int **list_of_levels);

tree_t *TheBracketPrinting(tree_t *tree, int level);

int *ListOfLevelsCtor(int max_depth);

int LeftIsSmaller(int first_number, int second_number);



#endif //TREE

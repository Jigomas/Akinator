#ifndef TREE
#define TREE



enum all_constsants{
    LEN_OF_DATA = 30,
    MAX_DEPTH = 5,
};



typedef int comparing_is_smaller_t(const int a, const int b);

typedef int comaring_with_asking_t(struct tree_t *tree, char value[LEN_OF_DATA]);

typedef int comaring_no_asking_t(struct tree_t *tree, int depth);

struct tree_t
{
    char *data;
    tree_t *left;
    tree_t *right;

    int depth;
    int *history;

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



tree_t *TreeCtor(int value, int depth, int history[MAX_DEPTH]);

void TreeDtor(tree_t *tree);

tree_t *TreeAddWithAsking(tree_t *tree, char value[LEN_OF_DATA], comaring_with_asking_t *comparing_alg, int depth, int history[MAX_DEPTH]);

tree_t *TreeAddNoAsking(tree_t *tree, char value[LEN_OF_DATA], comaring_no_asking_t *comparing_alg, int depth, int history[MAX_DEPTH]);

tree_t *TreeAsking(tree_t *tree, char ancestor[LEN_OF_DATA], comaring_with_asking_t *comparing_alg, int depth, int history[MAX_DEPTH]);

tree_t *SearchInTheTree(tree_t *tree, int value);

tree_t *TreePrint(tree_t *tree);

tree_t *TheBracketPrinting(tree_t *tree, int level);

int *ListOfLevelsCtor(int max_depth);

int LeftIsSmaller(int first_number, int second_number);



#endif //TREE

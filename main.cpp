#include <stdio.h>



#include "tree.h"
#include "deciding_alg.h"


int main(int argc, char* argv[]) {
    tree_t *tree = NULL;
    int history[5] = {0, 0, 0, 0, 0};

    tree = TreeAddWithAsking(tree, "of yours smaller than 15 cm", YesOrNo, 0, history) ;
    tree = TreeAddWithAsking(tree, "it is hui", YesOrNo, 0, history);
    tree = TreeAddWithAsking(tree, "it is leg", YesOrNo, 0, history);
    tree = TreeAddNoAsking(tree, "it is arm", DecidingOnHistory, 0, history);

    //tree = TreeAsking(tree, "", YesOrNo, 0, history);

    TreePrint(tree); //what to print
    TreeDtor(tree);
}

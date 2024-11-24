#include "deciding_alg.h"



int LeftIsSmaller(int first_number, int second_number) {
    return first_number < second_number;
}


int YesOrNo(tree_t *tree, char value[LEN_OF_DATA]) {
    fprintf(stderr, "%s %s\n", value, tree->data);
    fprintf(stderr, "Please print Yes or No\n");

    int read_sth   = 0;
    char  answer[3] = {};

    read_sth = scanf("%s", answer);

    if (!read_sth)
        return ERROR_COMPAREMENT;

    else if (answer[0] == 'Y' || answer[0] == 'y') {
        return LEFT;
    }

    else if (answer[0] == 'N' || answer[0] == 'n') {
        return RIGHT;
    }

    fprintf(stderr, "Cant understand your answer %d %d\n", answer[0], answer[1]);

    return ERROR_COMPAREMENT;
}


int DecidingOnHistory(tree_t *tree, int depth) {


    if (tree->history[depth] == 1) {
        return LEFT;
    }

    else if (tree->history[depth] == 0) {
        return RIGHT;
    }

    fprintf(stderr, "Cant make comparement");

    return ERROR_COMPAREMENT;
}

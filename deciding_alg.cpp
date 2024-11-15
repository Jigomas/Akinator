#include "deciding_alg.h"



int LeftIsSmaller(int first_number, int second_number) {
    return first_number < second_number;
}


int YesOrNo(tree_t *tree, int value) {
    fprintf(stderr, "Is the number %d is smaller shan %d\n", value, tree->data);
    fprintf(stderr, "Please print Yes or No\n");

    int read_sth   = 0;
    char  answer[3] = {};
    char yes_ans[3] = {'Y', 'e', 's'};
    char  no_ans[2] = {'N', 'o'};


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

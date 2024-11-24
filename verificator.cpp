#include "verificator.h"

void Verificator (struct tree_t *tree) {
    if (tree->code_of_program == ERROR) {
        fprintf(stderr, "(code_of_program) is equal to 0\n");
        tree->code_of_program = ERROR;

        assert(0);
        return;
    }

    if (tree == NULL) {
        fprintf(stderr, "(tree) adress is equal to NULL\n");
        tree->code_of_program = ERROR;

        assert(0);
        return;
    }

    if (tree->data == NULL) {
        fprintf(stderr, "(data) adress is equal to NULL\n");
        tree->code_of_program = ERROR;

        assert(0);
        return;
    }

    

    tree->code_of_program = ALL_GOOD;
}

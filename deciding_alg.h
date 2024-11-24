#ifndef DECIDING_ALG
#define DECIDING_ALG

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>


#include "tree.h"



int LeftIsSmaller(int first_number, int second_number);

int YesOrNo(tree_t *tree, char value[LEN_OF_DATA]);

int DecidingOnHistory(tree_t *tree, int depth);

#endif //DECIDING_ALG

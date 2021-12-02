//
// Created by P7XXTM1-G on 2021/12/2.
//

#ifndef HELLO_C_SEQUENCESEARCH_H
#define HELLO_C_SEQUENCESEARCH_H

#include <stdio.h>
#include <stdlib.h>

#include "RecordList/RecordList.h"

typedef int KeyType;

int SeqSearch(RecordList list, KeyType value);

int sortBySequential(RecordList list, KeyType value);

#endif //HELLO_C_SEQUENCESEARCH_H

//
// Created by P7XXTM1-G on 2021/11/15.
//

#include "SqQueue-In-Use.h"

void Arrange(SqQueue sqQueueA, SqQueue *sqQueueB, SqQueue *sqQueueC) {
    char e;
    InitQueue_Sq(sqQueueB, sqQueueA.size);
    InitQueue_Sq(sqQueueC, sqQueueA.size);

    while (FALSE == QueueEmpty_Sq(sqQueueA)) {
        DeQueue_Sq(&sqQueueA, &e);
        if (e == 'H') { EnQueue_Sq(sqQueueB, e); }
        else { EnQueue_Sq(sqQueueC, e); }
    }
};
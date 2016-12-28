//
//  jkCircularBuffer.h
//  NeuralNet
//
//  Created by JeiKei on 2016. 12. 8..
//  Copyright © 2016년 JeiKei. All rights reserved.
//

#ifndef jkCircularBuffer_h
#define jkCircularBuffer_h

#include <stdio.h>
#include <stdlib.h>

#define D_TYPE double

typedef struct jkCircularBuffer {
    int buffer_size;
    
    int consumer_idx;
    int producer_idx;
    
    int left_space;
    
    D_TYPE *buffer;
    
} jkCircularBuffer;

jkCircularBuffer* jkCircularBuffer_init(int size);
void jkCircularBuffer_free(jkCircularBuffer *buffer);
int get_next_idx(int current_idx, int step, int buffer_size);
void jkCircularBuffer_putData(jkCircularBuffer *buffer, D_TYPE data);
D_TYPE jkCircularBuffer_getNextData(jkCircularBuffer *buffer);
void jkCircularBuffer_getWholeData(jkCircularBuffer *buffer, D_TYPE *dest);
D_TYPE jkCircularBuffer_peakData(jkCircularBuffer *buffer);


#endif /* jkCircularBuffer_h */

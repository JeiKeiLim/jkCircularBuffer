//
//  jkCircularBuffer.c
//  NeuralNet
//
//  Created by JeiKei on 2016. 12. 8..
//  Copyright © 2016년 JeiKei. All rights reserved.
//

#include "jkCircularBuffer.h"


jkCircularBuffer* jkCircularBuffer_init(int size)
{
    jkCircularBuffer *c_buffer = (jkCircularBuffer *)malloc(sizeof(jkCircularBuffer));
    double *_buffer = (double *)malloc(size*sizeof(double));
    
    c_buffer->buffer_size = size;
    c_buffer->left_space = size;
    c_buffer->buffer = _buffer;
    c_buffer->consumer_idx = 0;
    c_buffer->producer_idx = -1;
    
    return c_buffer;
}


void jkCircularBuffer_free(jkCircularBuffer *buffer)
{
    free(buffer->buffer);
    free(buffer);
}


int get_next_idx(int current_idx, int step, int buffer_size)
{
    return (current_idx+step) % buffer_size;
}

void jkCircularBuffer_putData(jkCircularBuffer *buffer, D_TYPE data)
{
    int n_idx = get_next_idx(buffer->producer_idx, 1, buffer->buffer_size);
    buffer->producer_idx = n_idx;
    buffer->buffer[n_idx] = data;
    
    buffer->left_space--;
    
    if(buffer->left_space < 0)
    {
        buffer->left_space = 0;
        buffer->consumer_idx = get_next_idx(buffer->consumer_idx, 1, buffer->buffer_size);
    }
}

double jkCircularBuffer_getNextData(jkCircularBuffer *buffer)
{
    double result = buffer->buffer[buffer->consumer_idx];
    
    buffer->consumer_idx = get_next_idx(buffer->consumer_idx, 1, buffer->buffer_size);
    buffer->left_space++;
    
    return result;
}

void jkCircularBuffer_getWholeData(jkCircularBuffer *buffer, D_TYPE *dest)
{
    int i, j;
    
    for(i=0; i<(buffer->buffer_size-buffer->left_space); i++)
    {
        j = get_next_idx(buffer->consumer_idx, i, buffer->buffer_size);
        
        dest[i] = buffer->buffer[j];
    }
}

D_TYPE jkCircularBuffer_peakData(jkCircularBuffer *buffer)
{
    return buffer->buffer[buffer->consumer_idx];
}

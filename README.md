# jkCircularBuffer
Implementation of circular buffer for C

## Structure definition
<B>jkCircularBuffer</B> offers all information for circular buffer
- buffer_size : Size of buffer. It is defined with <B>jkCircularBuffer_init</B>
- consumer_idx : Index of consumer. It is always behind <B>producer_idx</B>. You don't really need to know this.
- producer_idx : Index of producer. It is always in front of <B>consumer_idx</B>. You don't really need to know this neither.
- left_space : Left space of buffer. This indicates data size that you have not look into yet.
- buffer : Actual buffer space

###### D_TYPE : It is <B>NOT</B> in the structure however, it is data type of the buffer. You can change this type as your project desire.


## Function definition

jkCircularBuffer* <B>jkCircularBuffer_init</B>(int <B>size</B>)
- Initialise the buffer. Its size will be determined by <B>size</B> argument

void <B>jkCircularBuffer_free</B>(jkCircularBuffer <B>*buffer</B>)
- Free memory allocation.

void <B>jkCircularBuffer_putData</B>(jkCircularBuffer <B>*buffer</B>, D_TYPE <B>data</B>)
- Add some data into the buffer

D_TYPE <B>jkCircularBuffer_getNextData</B>(jkCircularBuffer <B>*buffer</B>)
- Get some data from the buffer

void <B>jkCircularBuffer_getWholeData</B>(jkCircularBuffer <B>*buffer</B>, D_TYPE <B>*dest</B>)
- Get whole buffer data

D_TYPE <B>jkCircularBuffer_peakData</B>(jkCircularBuffer *<B>buffer</B>)
- Peak the head data from the buffer. It won't change any index from the buffer.

int <B>get_next_idx</B>(int <B>current_idx</B>, int <B>step</B>, int <B>buffer_size</B>)
- Get next index considering it is circular shape. You do not really need to know this function.


# Usage example
```C
int DATA_LENGTH = 200;
jkCircularBuffer *buf;
double *data = (double *)malloc(sizeof(double)*DATA_LENGTH);
int i;

for(i=0; i<DATA_LENGTH+2016; i++)
{
  jkCircularBuffer_putData(buf, i*0.302);
}

jkCircularBuffer_getWholeData(buf, data);

 for(i=0; i<DATA_LENGTH; i++)
{
    printf("%f\n", data[i]);
}

free(buf);
free(data);
```

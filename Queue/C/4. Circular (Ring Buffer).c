// Implement Circular Buffer 

# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 5

int circularBuffer[BUFFER_SIZE];
int writePointer = 0;
int readPointer = 0;
int count = 0; // Keeping track of elements in buffer

void addToBuffer(int num)
{
    if(count == BUFFER_SIZE) // Checking if the buffer is full or not 
    {
        printf("Buffer is full! Cannot add %d to the buffer.\n", num);
        return;
    }
    else{
        circularBuffer[writePointer] = num;
        writePointer = (writePointer + 1) % BUFFER_SIZE; // Move the writePointer, but stay in the range of 0 to 4 (circular!)
        count++; // increment count
    }
}

int removeFromBuffer()
{
    if(count == 0)   // Checking if buffer is empty or not
    {
        printf("Buffer is empty!");
        return -1;
    }
    else{
        int num = circularBuffer[readPointer];
        readPointer = (readPointer + 1) % BUFFER_SIZE; // Move the readPointer, but stay in the range of 0 to 4 (circular!)
        count--; // decrement count
        return num;
    }
}

void printBuffer()
{
    if(count == 0)
    {
        printf("Buffer is empty.");
        return;
    }
    int i = readPointer; // i is for reading
    for(int j = 0; j < count; j++) // j is for traversing
    {
        printf("%d ", circularBuffer[i]);
        i = (i + 1) % BUFFER_SIZE;
    }
    printf("\n");
}

int main()
{
    addToBuffer(10);
    addToBuffer(20);
    addToBuffer(30);
    addToBuffer(40);
    
    printBuffer();
    
    int num = removeFromBuffer();
    printf("Removed %d from the buffer ", num);
    
    printf("\n");
    printBuffer();
    
    addToBuffer(50);
    printBuffer();
    addToBuffer(60);
    
    printBuffer();
    
    return 0;
}

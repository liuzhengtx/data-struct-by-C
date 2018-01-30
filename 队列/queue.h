    #include <stdbool.h> 
	#ifndef __QUEUE_H_  
    #define __QUEUE_H_  
    typedef struct queue   
    {  
        int *pBase;  
        int front;    //指向队列第一个元素  
        int rear;    //指向队列最后一个元素的下一个元素  
        int maxsize; //循环队列的最大存储空间  
    }QUEUE,*PQUEUE;  
      
    void CreateQueue(PQUEUE Q,int maxsize);  
    void TraverseQueue(PQUEUE Q);  
    bool FullQueue(PQUEUE Q);  
    bool EmptyQueue(PQUEUE Q);  
    bool Enqueue(PQUEUE Q, int val);  
    bool Dequeue(PQUEUE Q, int *val);  
    #endif  

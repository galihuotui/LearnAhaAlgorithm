//
//  main.c
//  啊哈算法c2
//
//  Created by Tim on 16/5/27.
//  Copyright © 2016年 cky. All rights reserved.
//

#include <stdio.h>

struct queue
{
    int data[100]; //队列的主体,用来存储内容
    int head; //队首
    int tail; //队尾
};

int main(int argc, const char * argv[]) {

    
    /*
     1.队列1.0
     
    int q[102] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4}, head, tail;
    int i;
    //初始化队列
    head = 1;
    tail = 10;//队列中9个元素，tail指向队尾后一个位置
    
    //队列不为空的时候执行循环
    while (head < tail)
    {
        //打印队首并将队首出队
        printf("%d ", q[head]);
        head++;
        
        //先将新队首的数字添加到队尾
        q[tail] = q[head];
        tail++;
        
        //再将队首出队
        head++;
    }
    */
    /*
     2.队列2.0
     */
    struct queue q;
    int i;
    //初始化 队列
    q.head = 1;
    q.tail = 1;
    
    for(i=1; i<=9; i++)
    {
        //依次向队列插入9个数字
        scanf("%d", &q.data[q.tail]);
        q.tail++;
    }
    
    while (q.head < q.tail)
    {
        //打印队首并将队首出队
        printf("%d ", q.data[q.head]);
        q.head++;
        
        //先将新队首的数添加到队尾
        q.data[q.tail] = q.data[q.head];
        q.tail++;
        //再将队首出队
        q.head++;
    }
    
    getchar();
    getchar();
    return 0;
}

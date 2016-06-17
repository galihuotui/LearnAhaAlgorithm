//
//  main.c
//  纸牌游戏小猫钓鱼
//
//  Created by Tim on 16/5/31.
//  Copyright © 2016年 cky. All rights reserved.
//

#include <stdio.h>

struct queue
{
    int data[1000];
    int head;
    int tail;
};

struct stack
{
    int data[10];
    int top;
};

int main(int argc, const char * argv[]) {
    
    int i, t, flag;
    
    struct queue q1, q2;
    struct stack s;
    //初始化队列q1和q2为空, 此时两人手中都还没有牌
    q1.head=1; q1.tail=1;
    q2.head=1; q2.tail=1;
    //初始化栈为空，表示最开始桌上也没有牌
    s.top=0;
    
    //先读入6张牌 放入 A 手中
    for (i=1; i<=6; i++)
    {
        scanf("%d", &q1.data[q1.tail]);//读入一个数到队尾
        q1.tail++;//队尾向后移动一位
    }
    //再读入6张牌 放入 B 手中
    for (i=1; i<=6; i++)
    {
        scanf("%d", &q2.data[q2.tail]);//读入一个数到队尾
        q2.tail++;//队尾向后移动一位
    }
    
    //当队列不为空的时候执行循环
    while (q1.head<q1.tail && q2.head<q2.tail)
    {
        //1--------------A 出牌回合-------------------------------
        t = q1.data[q1.head];//A 先出一张牌
        
        flag = 0;
        //与桌上的牌比较
        for (i=1; i<=s.top; i++)
        {
            if (s.data[i] == t)
            {
                flag = 1;
                break;
            }
        }
        //A 此轮没有赢牌
        if (flag == 0)
        {
            q1.head++;//A 打出一张牌 所以要出队
            s.top++;
            s.data[s.top] = t;//把A打出的牌入栈
        }
        //A 此轮赢牌
        if (flag == 1)
        {
            q1.head++;//A 打出一张牌 所以要出队
            q1.data[q1.tail] = t;//因为此轮赢牌，所以先把打出的牌放到手中牌的末尾
            q1.tail++;
            
            while (s.data[s.top] != t)//从桌上第一张牌开始取，直到取到与打出的牌相同位置，依次放到手牌的末尾
            {
                q1.data[q1.tail] = s.data[s.top];//依次放入队尾
                q1.tail++;
                s.top--;//栈中少一张牌，栈顶要减1
            }
        }
        //2--------------B 出牌回合-------------------------------
        t = q2.data[q2.head]; //B出一张牌
        
        flag = 0;
        
        for (i=1; i<=s.top; i++)
        {
            if (s.data[i] == t)
            {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0)
        {
            q2.head++;
            s.top++;
            s.data[s.top] = t;
        }
        
        if (flag == 1)
        {
            q2.head++;
            q2.data[q2.tail] = t;
            q2.tail++;
            
            while (s.data[s.top] != t)
            {
                q2.data[q2.tail] = s.data[s.top];
                q2.tail++;
                s.top--;
            }
        }
        
    }
    
    if (q1.head == q1.tail)
    {
        printf("B获胜\n");
        printf("B当前手牌是 ");
        for (i=q2.head; i<=q2.tail-1; i++)
        {
            printf(" %d", q2.data[i]);
        }
        
        //桌上有牌的话则输出桌上的牌
        if (s.top > 0)
        {
            printf("\n桌上的牌是 ");
            for (i=1; i<=s.top; i++)
            {
                printf(" %d", s.data[i]);
            }
            
        }
        else
        {
            printf("\n桌上已经没有牌了");
        }
    }
    else
    {
        printf("A获胜\n");
        printf("A当前手牌是 ");
        for (i=q1.head; i<=q1.tail-1; i++)
        {
            printf(" %d", q1.data[i]);
        }
        
        //桌上有牌的话则输出桌上的牌
        if (s.top > 0)
        {
            printf("\n桌上的牌是 ");
            for (i=1; i<=s.top; i++)
            {
                printf(" %d", s.data[i]);
            }
            
        }
        else
        {
            printf("\n桌上已经没有牌了");
        }
    }
    
    
    getchar();
    getchar();
    return 0;
}

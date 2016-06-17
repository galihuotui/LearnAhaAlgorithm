//
//  main.c
//  链表
//
//  Created by Tim on 16/6/1.
//  Copyright © 2016年 cky. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//创建一个结构体表示链表的结点类型
struct node
{
    int data;
    struct node *next;
};

int main(int argc, const char * argv[])
{
    struct node *head, *p, *q, *t;
    int i, n, a;
    scanf("%d", &n);
    
    head = NULL;//头指针初始化为空
    //循环读入n数字
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a);
        //动态申请一个空间，用来存储一个结点，并用临时指针p指向新生成的结点
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a;//将输入的数字存储在当前结点的data中
        p->next = NULL;//设置当前结点的后继指针指向空，表示当前结点的下一个结点为空
        if (head == NULL)
        {
            head = p;//这是第一个创建的结点，因此将头指针指向这个结点
        }
        else
        {
            q->next = p;//如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
        }
        
        q = p;//指针q也指向当前结点
    }
    
    scanf("%d", &a);//读入要插入的数字
    
    t = head;//链表从头开始遍历
    while (t != NULL)//没有到达链表尾部的时候就执行循环
    {
        //插入到链表最后位置
        if (t->next == NULL)
        {
            //动态申请一个空间，用来存放要新增的结点
            p = (struct node *)malloc(sizeof(struct node));
            p->data = a;
            //新增的结点的后继指针指向当前结点后继指针所指向的结点
            p->next = t->next;
            //当前结点的后继指针指向新增的结点
            t->next = p;
            //插入完毕 退出循环
            break;
        }
    
        //找到要插入的位置
        if (t->next->data > a)
        {
            //动态申请一个空间，用来存放要新增的结点
            p = (struct node *)malloc(sizeof(struct node));
            p->data = a;
            //新增的结点的后继指针指向当前结点后继指针所指向的结点
            p->next = t->next;
            //当前结点的后继指针指向新增的结点
            t->next = p;
            //插入完毕 退出循环
            break;
        }
        //继续下一个结点
        t = t->next;
    }
    
    
    //输出链表中的所有元素
    t = head;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    
    getchar();
    getchar();
    return 0;
}

//
//  main.c
//  模拟链表
//
//  Created by Tim on 16/6/2.
//  Copyright © 2016年 cky. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
   
    int data[101], right[101];
    int i,n,t,len;
    
    scanf("%d", &n);
    //读入数字
    for (i=1; i<=n; i++)
    {
        scanf("%d", &data[i]);
    }
    
    len = n;
    //初始化数组right
    for (i=1; i<=n; i++)
    {
        if (i != n)
        {
            right[i] = i+1;
        }
        else
        {
            right[i] = 0;
        }
        
    }
    //增加数字的话 直接在data数组的末尾添加即可
    len++;
    scanf("%d", &data[len]);
    
    //从链表的头部开始遍历
    t = 1;
    while (t != 0)
    {
        //如果当前结点下一个结点的值大于待插入的值 找到要插入的位置
        if (data[right[t]] > data[len])
        {
            //新插入的结点下一个结点标号等于当前结点的下一个结点的标号
            right[len] = right[t];
            //当前结点的下一个结点标号就是新插入结点的编号
            right[t] = len;
            break;//插入完成跳出循环
        }
        t = right[t];
    }
    
    //输出链表中的数字
    t =1;
    while (t != 0)
    {
        printf("%d ", data[t]);
        
        t = right[t];
    }
    getchar();
    getchar();
    return 0;
}

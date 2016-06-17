//
//  main.c
//  啊哈算法
//
//  Created by Tim on 16/5/24.
//  Copyright © 2016年 cky. All rights reserved.
//

#include <stdio.h>

struct student
{
    char name[21];
    int score;
};

//int a[101], n; //全局变量

/*
 
    4.快速排序
 
void quicksort(int left, int right)
{
    int i, j, t, temp;
    if (left > right)
    {
        return;
    }
    
    temp = a[left]; //temp存的是基准数
    i = left;
    j = right;
    
    while (i != j)
    {
        //先从右向左找
        while (a[j] >= temp && i < j)
        {
            j--;
        }
        //从左往右找
        while (a[i] <= temp && i < j)
        {
            i++;
        }
        
        //交换两个数在数组中的位置
        if (i < j)
        {
            //i , j 没有相遇时
            t = a[i];
            a[i] = a[j];
            a[j] = t;

        }
        
    }
    //将基准数归位
    a[left] = a[i];
    a[i] = temp;
    
    quicksort(left, i-1);//继续处理左边的数字序列
    quicksort(i+1, right);//继续处理右边的数字序列
    
}
*/
int main(int argc, const char * argv[]) {
   
    /*
    //1.桶排序
     
    int a[11], i, j, t;
    
    for (i=0; i<=10; i++) 
    {
        a[i] = 0; //初始化为0
    }
    
    for (i=1; i<=5; i++) 
    {
        scanf("%d", &t);//把每一个数读到变量t中
        a[t]++;//进行计数
    }
    
    for (i=0; i<=10; i++) 
    {   
        //依次判断a[0]-a[10]
        for (j=1; j<=a[i]; j++) 
        {   
            //出现几次就打印几次
            printf("%d ", i);
        }
    }
    */
    
    /*
     //2.冒泡排序 1.0
     
    int a[100], i, j, t, n;
    
    scanf("%d", &n);//表示接下来将输入n个数字
    
    for (i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);//循环读入n个数到数组中
    }
    
    //冒泡排序核心部分
    for (i=1; i<=n-1; i++) //n个数排序只需要进行n-1趟
    {
        for (j=1; j<=n-i; j++) //从第一位开始比较直到最后一个尚未归位的数
        {
            if (a[j] < a[j+1])
            {
                //比较大小 并交换 实现从大到小排序
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    
    for (i=1; i<=n; i++) {
        printf("%d ", a[i]);
    }
    */
    
    /*
     //3.冒泡排序 2.0
     
    
    struct student a[100], t;
    int i, j, n;
    
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%s %d", a[i].name, &a[i].score);
    }
    
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n-i; j++)
        {
            if (a[j].score < a[j+1].score)
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    
    for (i=1; i<=n; i++)
    {
        printf("%s %d\n", a[i].name, a[i].score);
    }
    */
    /*
    int i, j, t;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    quicksort(1, n);//调用快速排序
    
    for (i = 1 ; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    */
    
    int a[1001], n, i, j, t;
    for (i = 1; i <= 1000; i++)
    {
        a[i] = 0;//初始化
    }
    
    scanf("%d", &n);
    
    /*
    for (i = 1; i <= n; i++)
    {
        //循环读入ISBN号
        scanf("%d", &t);
        a[t] = 1; //标记出现过的ISBN号
    }
    
    for (i = 1; i <= 1000; i++)
    {
        if (a[i] == 1)
        {
            //如果出现过这个ISBN号则打印出来
            printf("%d ", i);
        }
    }
    */
    
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    //开始冒泡排序
    for (i = 1; i <= n-1; i++)
    {
        for (j = 1; j <= n-i; j++)
        {
            if (a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    
    printf("%d ", a[1]);//输出第一个数
    
    for (i = 2; i <= n; i++)
    {
        //如果这个数是第一次出现则输出
        if (a[i] != a[i-1])
        {
            printf("%d ", a[i]);
        }
    }
    
    getchar();
    getchar();
    return 0;
}

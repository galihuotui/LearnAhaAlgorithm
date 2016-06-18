//
//  main.c
//  深度优先搜索
//
//  Created by Tim on 16/6/18.
//  Copyright © 2016年 cky. All rights reserved.
//

#include <stdio.h>

int a[10], book[10], n;

void dfs(int step)//step 表示现在站在第几个盒子面前
{
    int i;
    //如果站在第n+1个盒子面前，咋表示前n个盒子都已经放好了扑克牌
    if(step == n+1)
    {
        //输出一种排列(1-n号盒子中的扑克牌编号)
        for (i=1; i<=n; i++)
        {
            printf("%d", a[i]);
        }
        printf("\n");
        return;//返回之前的一步(最近一次调用dfs函数的地方)
    }
    
    for (i=1; i<=n; i++)
    {
        //判断扑克牌i是否还在手上
        if (book[i] == 0)
        {
            a[step] = i;//将i号扑克牌放到第step个盒子中
            book[i] = 1;//book[i]设置为1，表示扑克牌i已经不在手中
            
            dfs(step+1);
            book[i] = 0; //将刚才尝试的牌收回，才能进行下一次尝试
        }
    }
    
    return;
}
int main(int argc, const char * argv[])
{
    scanf("%d", &n);//输入1-9之间的整数
    dfs(1);//首先站在1号盒子面前
    getchar();
    getchar();
    return 0;
}

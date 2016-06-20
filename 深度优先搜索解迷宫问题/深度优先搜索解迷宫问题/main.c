//
//  main.c
//  深度优先搜索解迷宫问题
//
//  Created by Tim on 16/6/20.
//  Copyright © 2016年 cky. All rights reserved.
//

/*
 5 4
 0 0 1 0
 0 0 0 0
 0 0 1 0
 0 1 0 0
 0 0 0 1
 1 1 4 3
 7
 */
#include <stdio.h>
int a[51][51], book[51][51];

int n, m, p, q, min = 99999999;

void dfs(int x, int y, int step)
{
    int next[4][2] =
    {
        {0, 1},//向右走
        {1, 0},//向下走
        {0, -1},//向左走
        {-1, 0}//向上走
    };
    
    int tx, ty, k;
    //判断是否到达目的地
    if (x == p && y == q)
    {
        //更新最小值
        if (step < min)
        {
            min = step;
        }
        
        return;//返回
    }
    
    //枚举四种走法
    for (k = 0; k <= 3; k++)
    {
        //计算下一个点的坐标
        tx = x + next[k][0];
        ty = y + next[k][1];
        //判断是否越界
        if (tx < 1 || tx > n || ty <1 || ty > m)
        {
            continue;
        }
        //判断该点是否为障碍物或已经在路径中
        if (a[tx][ty] == 0 && book[tx][ty] == 0)
        {
            book[tx][ty] = 1;// 标记这个点已经走过
            dfs(tx, ty, step+1);//开始尝试下一个点
            book[tx][ty] = 0;//尝试结束，取消这个点的标记
        }
        
    }
    return;
    
}
int main(int argc, const char * argv[])
{
    
    int i, j, startx, starty;
    scanf("%d %d", &n, &m);
    
    //读入迷宫
    //0 表示空地 1 表示障碍物
    for(i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    //读入起点和终点
    scanf("%d %d %d %d", &startx, &starty, &p, &q);
    
    //从起点开始搜索
    book[startx][starty] = 1;//标记起点已经在路径中
    dfs(startx, starty, 0);//初始步数为0
    
    //输出最短步数
    printf("%d", min);
    getchar();
    getchar();
    return 0;
}

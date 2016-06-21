//
//  main.c
//  广度优先搜索解迷宫问题
//
//  Created by Tim on 16/6/21.
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

struct note
{
    int x;//横坐标
    int y;//纵坐标
    int f;//父亲在队列中的编号
    int s;//步数
};

int main(int argc, const char * argv[])
{
  
    //地图大小不超过50 * 50 因此队列扩展不超过2500 个
    struct note que[2501];
    
    int a[51][51] = {0}, book[51][51] = {0};
    //表示走的方向的数组
    int next[4][2] =
    {
        {0, 1},//向右走
        {1, 0},//向下走
        {0, -1},//向左走
        {-1, 0}//向上走
    };
    
    int head, tail;
    int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;
    
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    scanf("%d %d %d %d", &startx, &starty, &p, &q);
    
    //队列初始化
    head = 1;
    tail = 1;
    //向队列插入迷宫的入口坐标
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    
    book[startx][starty] = 1;
    flag = 0;//用来标记是否到达目标点, 0表示暂未到达 1表示到达
    while (head < tail)
    {
        //枚举4个方向
        for (k=0; k<=3; k++)
        {
            //计算下一个点的坐标
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            //判断是否越界
            if (tx < 1 || tx > n || ty < 1 || ty > m)
            {
                continue;
            }
            //判断是否为障碍物 或已经在路径中
            if (a[tx][ty] == 0 && book[tx][ty] == 0)
            {
                //标记该点已走过
                //每个点只入队一次
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                //这个点是从head扩展来的 所以它的父亲是head
                que[tail].f = head;
                //步数是父亲步数+1
                que[tail].s = que[head].s + 1;
                tail++;
            }
            //如果目标点到了 停止扩展 任务结束 退出循环
            if (tx == p && ty == q)
            {
                flag = 1;
                break;
            }
        }
        
        if (flag == 1)
        {
            break;
        }
        //当一个点扩展完毕后 head++对后面的点再进行扩展
        head++;
    }
    
    //打印队列中末尾最后一个点(目标点)的步数
    //tail 指向队列队尾下一个位置 所以需要-1
    printf("%d", que[tail-1].s);
    getchar();
    getchar();
    return 0;
}

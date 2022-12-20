/*
 * @Author: 23japhone
 * @Date: 2022-11-30 11:37:04
 * @LastEditors: 23japhone
 * @LastEditTime: 2022-12-03 21:38:59
 * @description: 
 */
#if !defined(TICKETS_H_)
#define TICKETS_H_


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "gui.h"
#include "function.h"


typedef struct ticket
{
    char company[20], // 公司
         num[8], // 航班号
         starting[20], // 起点
         ending[20], // 终点
         takeoff[20], // 起飞时间
         landing[20], // 降落时间
         period[10], // 飞行时间
         price[20], // 价格
         all[20], // 座位容量
         purchaseTotal[20], // 买入数量
         reserved[20]; // 已订座位数
}ticket;



ticket t[100];


void book();
void cancel();
int readFile(char *fname, ticket TICKET[]);
void writeFile(char *fname, ticket TICKET[], int result);

#endif // TICKETS_H_

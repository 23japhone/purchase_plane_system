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
    char company[20], // ��˾
         num[8], // �����
         starting[20], // ���
         ending[20], // �յ�
         takeoff[20], // ���ʱ��
         landing[20], // ����ʱ��
         period[10], // ����ʱ��
         price[20], // �۸�
         all[20], // ��λ����
         purchaseTotal[20], // ��������
         reserved[20]; // �Ѷ���λ��
}ticket;



ticket t[100];


void book();
void cancel();
int readFile(char *fname, ticket TICKET[]);
void writeFile(char *fname, ticket TICKET[], int result);

#endif // TICKETS_H_

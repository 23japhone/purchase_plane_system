/*
 * @Author: 23japhone
 * @Date: 2022-12-01 18:27:42
 * @LastEditors: 23japhone
 * @LastEditTime: 2022-12-01 20:22:18
 * @description: 
 */
#include "function.h"


int rapidInput(int low, int high)
{
    int choice = 0, // 选择
		result = 0, // 每一轮的结果
		flagNum = 0, // 是否输入数字
		total = 0, // 循环次数
		flagChar = 0; // 是否输入字符
	char ch;
	do
	{
		result = 0;
		flagChar = 0;
		flagNum = 0;
		total++;
		if(total >= 2)
			printf("\t您的输入有误，请重新输入： ");
		ch = getchar();
		while (ch != '\n')
		{
			if(ch >= '0' && ch <= '9')
			{
				flagNum = 1;
				if(flagChar == 0)
				{
					result = result * 10 + ch - '0';
					choice = result;
				}
			}
			else
			{
				if((ch < '0' || ch > '9') && ch != '\n')
					flagChar = 1;
			}
			ch = getchar();
		}		
	} while (((choice < low || choice > high) && flagChar == 0) || flagChar == 1);
    return choice;
}



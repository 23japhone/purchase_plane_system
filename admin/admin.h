#if !defined(ADMIN_H_)
#define ADMIN_H_


#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "gui.h"
#include "function.h"


#define nodeLen sizeof(node) // node的内存长度


// 飞机票链表
typedef struct node
{
    char company[11], // 航空公司
        planeNum[11], // 航空号
        startPlace[11], // 起点
        finalPlace[11], // 终点
        startTime[25], // 起飞时间
        finalTime[25], // 降落时间
        intervalTime[15], // 飞行时间
        price[8], // 票价
        totalSeat[5], // 座位容量
        occupiedSeat[5]; // 已订座位数
    int dataLen, // 总飞机票数量
        dataIndex; // 第几张机票
    struct node *next; // 后一个节点
}node;


/**
 * @description:  链表初始化表头
 * @return {*}
 * @Author: 23japhone
 */
node *init(); 
/**
 * @description:  飞机票链表建立
 * @return {*}
 * @Author: 23japhone
 */
node *creatPlane();
/**
 * @description:  输出链表
 * @param {node} *head
 * @return {*}
 * @Author: 23japhone
 */
void printNode(node *head);
/**
 * @description:  管理员账户注册函数
 * @return {*}
 * @Author: 23japhone
 */
void adminSetting();
/**
 * @description:  管理员账户登录
 * @return {*}
 * @Author: 23japhone
 */
void adminEntry();
/**
 * @description:  添加飞机票数据
 * @return {*}
 * @Author: 23japhone
 */
void addPlaneData();
/**
 * @description:  查找飞机票数据
 * @return {*}
 * @Author: 23japhone
 */
void findPlaneData(int nextStep);
/**
 * @description:  删除飞机票
 * @param {int} total
 * @return {*}
 * @Author: 23japhone
 */
void delData(int total, int num, char *findName, int change);
/**
 * @description:  排序
 * @return {*}
 * @Author: 23japhone
 */
void sortData();

#endif // ADMIN_H_

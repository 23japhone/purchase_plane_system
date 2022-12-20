#if !defined(ADMIN_H_)
#define ADMIN_H_


#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "gui.h"
#include "function.h"


#define nodeLen sizeof(node) // node���ڴ泤��


// �ɻ�Ʊ����
typedef struct node
{
    char company[11], // ���չ�˾
        planeNum[11], // ���պ�
        startPlace[11], // ���
        finalPlace[11], // �յ�
        startTime[25], // ���ʱ��
        finalTime[25], // ����ʱ��
        intervalTime[15], // ����ʱ��
        price[8], // Ʊ��
        totalSeat[5], // ��λ����
        occupiedSeat[5]; // �Ѷ���λ��
    int dataLen, // �ܷɻ�Ʊ����
        dataIndex; // �ڼ��Ż�Ʊ
    struct node *next; // ��һ���ڵ�
}node;


/**
 * @description:  �����ʼ����ͷ
 * @return {*}
 * @Author: 23japhone
 */
node *init(); 
/**
 * @description:  �ɻ�Ʊ������
 * @return {*}
 * @Author: 23japhone
 */
node *creatPlane();
/**
 * @description:  �������
 * @param {node} *head
 * @return {*}
 * @Author: 23japhone
 */
void printNode(node *head);
/**
 * @description:  ����Ա�˻�ע�ắ��
 * @return {*}
 * @Author: 23japhone
 */
void adminSetting();
/**
 * @description:  ����Ա�˻���¼
 * @return {*}
 * @Author: 23japhone
 */
void adminEntry();
/**
 * @description:  ��ӷɻ�Ʊ����
 * @return {*}
 * @Author: 23japhone
 */
void addPlaneData();
/**
 * @description:  ���ҷɻ�Ʊ����
 * @return {*}
 * @Author: 23japhone
 */
void findPlaneData(int nextStep);
/**
 * @description:  ɾ���ɻ�Ʊ
 * @param {int} total
 * @return {*}
 * @Author: 23japhone
 */
void delData(int total, int num, char *findName, int change);
/**
 * @description:  ����
 * @return {*}
 * @Author: 23japhone
 */
void sortData();

#endif // ADMIN_H_

/*
 * @Author: 23japhone
 * @Date: 2022-11-29 22:06:07
 * @LastEditors: 23japhone
 * @LastEditTime: 2022-12-03 21:08:24
 * @description: 
 */
#if !defined(GUI_H_)
#define GUI_H_


#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "user.h"
#include "TICKETS.h"
#include "function.h"


int menu(); //�˵�
void menuRes(); // ��ʼ������Ӧ
int adminGui(); //  ����Ա����
void adminRes(); // ����Ա������Ӧ
int findDataGui(); // �������ݽ���
int sortDataGui(); // �������ݽ���
int userGui(); // �û�����
void userRes(); // �û�������Ӧ
int changeDataGui(); // �޸����ݽ���
void settingGui(char *adminName, char *password, char *confirmPassword); // ע���������
void entryGui(char *inputName, char *inputPassWord); // ��¼�������
int adminMenu(); // ����Ա�˵�
void adminMenuRes(); // ����Ա�˵���Ӧ
int userMenu(); // �û��˵�
void userMenuRes(); // �û��˵���Ӧ


#endif // GUI_H_

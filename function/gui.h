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


int menu(); //菜单
void menuRes(); // 初始界面响应
int adminGui(); //  管理员界面
void adminRes(); // 管理员界面响应
int findDataGui(); // 查找数据界面
int sortDataGui(); // 排序数据界面
int userGui(); // 用户界面
void userRes(); // 用户界面响应
int changeDataGui(); // 修改数据界面
void settingGui(char *adminName, char *password, char *confirmPassword); // 注册输入界面
void entryGui(char *inputName, char *inputPassWord); // 登录输入界面
int adminMenu(); // 管理员菜单
void adminMenuRes(); // 管理员菜单响应
int userMenu(); // 用户菜单
void userMenuRes(); // 用户菜单响应


#endif // GUI_H_

#include "gui.h"


int adminMenu() // 管理员菜单
{
	int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	    ***************欢迎来到管理员的操作界面*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );	
	printf ( "	|----> 1: 管理员登录                                                     <----|\n" );
	printf ( "	|----> 2：管理员注册                                                     <----|\n" );	
    printf ( "	|----> 3：返回上一级                                                     <----|\n" );
    printf ( "	|----> 4：退出程序                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = rapidInput(1, 4);
	return choice;
}


void adminMenuRes()
{
	int choice = adminMenu();
	// 先给新用户注册
	printf("\n\t----> 		程序在进行		<----|\n");	
	switch (choice)
	{
		case 1:
			adminEntry();
			break;
		case 2:
			adminSetting();
			break;
		case 3:
			printf("\n\t将于3秒后跳转到初始界面......");
            Sleep(3000);
            system("cls");
            menuRes();
            break;	
		case 4:
			printf("\n\t程序结束，感谢您的使用谢谢！\n");	
			break;				
		default:
			break;
	}
	return ;
}


int userMenu()
{
	int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	      ***************欢迎来到用户的操作界面*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );	
	printf ( "	|----> 1: 用户登录                                                       <----|\n" );
	printf ( "	|----> 2：用户注册                                                       <----|\n" );	
    printf ( "	|----> 3：返回上一级                                                     <----|\n" );
    printf ( "	|----> 4：退出程序                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = rapidInput(1, 4);
	return choice;	
}


void userMenuRes()
{
	int choice = userMenu();
	// 先给新用户注册
	printf("\n\t----> 		程序在进行		<----|\n");	
	switch (choice)
	{
		case 1:
			userEntry();
			break;
		case 2:
			userSetting();
			break;
		case 3:
			printf("\n\t将于3秒后跳转到初始界面......");
            Sleep(3000);
            system("cls");
            menuRes();
            break;	
		case 4:
			printf("\n\t程序结束，感谢您的使用谢谢！\n");	
			break;				
		default:
			break;
	}
	return ;	
}


int menu() // 菜单
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	    ***************欢迎来到飞机票的订购系统*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );
	printf ( "	|----> 1: 管理员                                                         <----|\n" );
	printf ( "	|----> 2：用户                                                           <----|\n" );
    printf ( "	|----> 3：退出程序                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = rapidInput(1, 3);
	return choice;
}


void menuRes()
{
	int choice = menu();
	// 先给新用户注册
	printf("\n\t----> 		程序在进行		<----|\n");
	switch (choice)
	{
		case 1:
			printf("\n\t系统将于3秒后跳转到管理员菜单界面......");
			Sleep(3000);
			system("cls");
			adminMenuRes();
			break;
		case 2:
			printf("\n\t系统将于3秒后跳转到用户菜单界面......");
			Sleep(3000);
			system("cls");
			userMenuRes();
			break;	
		case 3:
			printf("\n\t程序结束，感谢您的使用谢谢！\n");
		default:
			break;
	}
	return ;
}


int adminGui()
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	   ***************欢迎来到管理员操作界面*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );
	printf ( "	|----> 1: 新增机票数据                                                   <----|\n" );
	printf ( "	|----> 2: 删除机票数据                                                   <----|\n" );
	printf ( "	|----> 3: 查找机票数据                                                   <----|\n" );
	printf ( "	|----> 4: 排序机票数据                                                   <----|\n" );
    printf ( "	|----> 5: 显示所有机票                                                   <----|\n" );
	printf ( "	|----> 6: 修改单个机票                                                   <----|\n" );
	printf ( "	|----> 7：返回管理员菜单                                                 <----|\n" );
    printf ( "	|----> 8：退出程序                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = rapidInput(1, 8);
	return choice;
}


void adminRes()
{
    int choice = adminGui();
	node *head = NULL;
	// 先给新用户注册
    switch (choice)
    {
        case 1:
			printf("\n\t----> 		程序在进行		<----|\n");
            addPlaneData();	
            break;
        case 2:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到删除页面......");
			Sleep(3000);
            findPlaneData(1);
            break;
        case 3:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到查找页面......");
			Sleep(3000);
            findPlaneData(0);
            break;
        case 4:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到排序页面......");
			Sleep(3000);
            sortData();
			break;
        case 5:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到显示机票页面......");
			Sleep(3000);
			system("cls");
			head = creatPlane();
			printNode(head);
            break;
		case 6:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到查找页面......");
			Sleep(3000);
            findPlaneData(2);	
			break;		
        case 7:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\n\t将于3秒后跳转到管理员菜单界面......");
            Sleep(3000);
            system("cls");
			adminMenuRes();
            break;
		case 8:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\n\t程序结束，感谢您的使用谢谢！\n");
            break;
        default:
            break;
    }
	return ;
}


int findDataGui()
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	  ***************欢迎来到查找飞机票数据界面*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );
	printf ( "	|----> 1: 按航空公司查找                                                 <----|\n" );	
	printf ( "	|----> 2: 按航班号查找                                                   <----|\n" );
	printf ( "	|----> 3: 按起点查找                                                     <----|\n" );
	printf ( "	|----> 4: 按终点查找                                                     <----|\n" );
	printf ( "	|----> 5: 按起飞时间查找                                                 <----|\n" );
	printf ( "	|----> 6: 按票价查找                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = rapidInput(1, 6);
	return choice;
}


int sortDataGui()
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	  ***************欢迎来到排序飞机票数据界面*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );
	printf ( "	|----> 1: 按航空公司排序                                                 <----|\n" );
	printf ( "	|----> 2: 按起点排序                                                     <----|\n" );
	printf ( "	|----> 3: 按终点排序                                                     <----|\n" );	
	printf ( "	|----> 4: 按起飞时间排序                                                 <----|\n" );
	printf ( "	|----> 5: 按票价排序                                                     <----|\n" );	
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = rapidInput(1, 5);
	return choice;
}


int userGui()
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	     ***************欢迎来到用户操作界面*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );
	printf ( "	|----> 1: 购票                                                           <----|\n" );
	printf ( "	|----> 2: 退票                                                           <----|\n" );
	printf ( "	|----> 3：返回用户菜单                                                   <----|\n" );
    printf ( "	|----> 4：退出程序                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = rapidInput(1, 4);
	return choice;	
}


void userRes()
{
	int choice = userGui();
	printf("\n\t----> 		程序在进行		<----|\n");
    switch (choice)
    {
        case 1:
            book();
            break;
        case 2:
            cancel();
            break;
        case 3:
            printf("\n\t将于3秒后跳转到用户菜单界面......");
            Sleep(3000);
            system("cls");
			userMenuRes();
            break;
        case 4:
            printf("\n\t程序结束，感谢您的使用谢谢！\n");
            break;
        default:
            break;
    }		
	return ;
}


int changeDataGui()
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要根据哪项进行修改              <----|\n" );
	printf ( "	|----> 1: 航空公司                                                       <----|\n" );
	printf ( "	|----> 2: 航班号                                                         <----|\n" );
	printf ( "	|----> 3：起点                                                           <----|\n" );
    printf ( "	|----> 4：终点                                                           <----|\n" );
	printf ( "	|----> 5: 起飞时间                                                       <----|\n" );
	printf ( "	|----> 6: 降落时间                                                       <----|\n" );	
	printf ( "	|----> 7: 飞行时间                                                       <----|\n" );
    printf ( "	|----> 8：票价                                                           <----|\n" );
	printf ( "	|----> 9: 座位容量                                                       <----|\n" );
	printf ( "	|----> 10: 已订座位数                                                    <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = rapidInput(1, 10);
	return choice;		
}


void settingGui(char *adminName, char *password, char *confirmPassword)
{
    printf("\n\t请输入你的用户名（不能超20位,不能有空格）： ");
    scanf("%s", adminName);
    printf("\t请输入你的密码（不能超20位,不能有空格）: ");
    scanf("%s", password);
    printf("\t请确认你的密码（不能超20位,不能有空格）: ");
    scanf("%s", confirmPassword);
    while(strcmp(password, confirmPassword) != 0) // 判断两个字符串是否相等
    {
        printf("\t密码不正确，请重新输入你的密码（不能超20位,不能有空格）: ");
        scanf("%s", password);
        printf("\t请确认你的密码（不能超20位,不能有空格）: ");
        scanf("%s", confirmPassword);
    }
	return ;
}


void entryGui(char *inputName, char *inputPassWord)
{
    printf("\n\t请输入你的用户名（不能超20位,不能有空格）： ");
    scanf("%s", inputName);
    printf("\t请输入你的密码（不能超20位,不能有空格）: ");
    scanf("%s", inputPassWord);
	return ;
}


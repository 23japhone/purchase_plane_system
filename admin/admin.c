/*
 * @Author: 23japhone
 * @Date: 2022-11-27 16:55:36
 * @LastEditors: 23japhone
 * @LastEditTime: 2022-12-19 18:07:45
 * @description: 管理员操作
 */
#include "admin.h"


void adminSetting() 
{
    char ch,
         adminName[21], // 用户名20位
         password[21], // 密码设置
         confirmPassword[21], // 确认密码
         fileName[21], // 文件夹内的用户名
         filePassword[21]; // 文件夹内密码
    FILE *f;
    int i = 0;
    settingGui(adminName, password, confirmPassword);
    f = fopen("./飞机票订购系统/allFile/admin/adminData.txt", "r"); // 只读
    if(f == NULL) // 文件是否不存在
    {
        getchar(); // 读取多余空格
        perror("\n\t文件打开错误，等待5秒后跳转到管理员菜单界面......");
        Sleep(5000);
        system("cls");
        adminMenuRes();
    }
    else
    {
        ch = fgetc(f); // 判断文件是否是空的
        if(!feof(f)) // 不是空的，就可以读入
        {
            rewind(f); // 回到文件开头
            while (!feof(f))
            {
                fscanf(f, "%s %s\n", fileName, filePassword);
                if(strcmp(adminName, fileName) == 0)
                {
                    fclose(f);
                    f = NULL;
                    getchar(); // 读取多余空格
                    printf("\n\t用户名已经存在，请更换用户名，等待5秒后跳转到管理员菜单界面......");
                    Sleep(5000);
                    system("cls");
                    adminMenuRes();
                }
            }
        }
        fclose(f);
        f = NULL;
    }
    f = fopen("./飞机票订购系统/allFile/admin/adminData.txt", "a"); // 追加
    if(f == NULL) // 文件为空
    {
        getchar(); 
        perror("\n\t文件打开错误，等待5秒后跳转到管理员菜单界面......");
        Sleep(5000);
        system("cls");
        adminMenuRes();
    }
    else
    {
        fprintf(f, "%s %s\n", adminName, password);
        fclose(f);
        f = NULL;
        getchar();
        printf("\n\t注册成功！等待5秒后跳转到管理员菜单界面......");
        Sleep(5000);
        system("cls");
        adminMenuRes();
    }
    return ;
}


void adminEntry()
{
    char inputName[21], // 输入用户名
         inputPassWord[21], // 输入密码
         adminName[21], // 管理员名字
         password[21]; // 密码
    FILE *f;
    char ch;
    int i = 0, // 字符串索引
        flag1 = 0; // 字串相等判断
    entryGui(inputName, inputPassWord);
    f = fopen("./飞机票订购系统/allFile/admin/adminData.txt", "r"); // 只读
    if(f == NULL)
    {
        getchar();
        perror("\n\t文件打开错误，等待5秒后跳转到管理员菜单界面......");
        Sleep(5000);
        system("cls");
        adminMenuRes();
    }
    else
    {
        ch = fgetc(f); // 读取一个字符
        if(feof(f))
        {
            fclose(f);
            f = NULL;   
            getchar();
            printf("\n\t该文件内容为空，请注册账号后登录，等待5秒后跳转到管理员菜单界面......");         
            Sleep(5000);
            system("cls");
            adminMenuRes();
        }
        else
        {
            rewind(f); // 指针回到开头
            while (!feof(f))
            {
                fscanf(f, "%s  %s\n", adminName, password);
                if(strcmp(adminName, inputName) == 0) // 如果一样结束
                {
                    flag1 = 1; // 相等标志位1
                    break;
                }
            }
            fclose(f);
            f = NULL;
            if(flag1 != 1)
            {
                getchar();
                printf("\n\t该管理员名不存在，请检查用户名是否拼写正确，等待5秒后跳转到管理员菜单界面......");
                Sleep(5000);
                system("cls");
                adminMenuRes();
            }
            else
            {
                if(strcmp(password, inputPassWord) == 0) // 密码和设定值相等
                {
                    getchar();
                    printf("\n\t登录成功！等待5秒后跳转到管理员功能界面......");
                    Sleep(5000);
                    system("cls");
                    adminRes();
                }
                else
                {
                    getchar();
                    printf("\n\t密码错误，等待5秒后跳转到管理员菜单界面......");
                    Sleep(5000);
                    system("cls");
                    adminMenuRes();
                }
            }
        }
    }
    return ;
}


void addPlaneData() 
{
    int addIndex, // add的索引
        addNum; // 添加飞机票
    FILE *f;
    node *head = NULL, // 文件机票头
         *subHead = NULL, // 遍历文件机票头
         *pre = NULL, // 前一个地址
         *next = NULL, // 后一个地址
         *data = init(); // 作为头
    pre = data; // 来到数据头
    printf("\n\t请输入你想要添加几班航空信息： ");
    scanf("%d", &addNum);
    printf("\n\t3秒后跳转到添加飞机票页面......");
    Sleep(3000);
    system("cls");
    for(addIndex = 1; addIndex <= addNum; addIndex++)
    {
        next = (node *)malloc(nodeLen); // 分配空间
        printf("\t请输入航空公司： ");
        scanf("%s", next->company); 
        printf("\t请输入航班号： ");
        scanf("%s", next->planeNum);
        printf("\t请输入起点： ");
        scanf("%s", next->startPlace); 
        printf("\t请输入终点： ");
        scanf("%s", next->finalPlace); 
        printf("\t请输入起飞时间（如：2022/1/1/13:10）： ");
        scanf("%s", next->startTime); 
        printf("\t请输入降落时间（如：2022/1/1/13:10）： ");
        scanf("%s", next->finalTime); 
        printf("\t请输入飞行时间（如：1h20min）： ");
        scanf("%s", next->intervalTime); 
        printf("\t请输入票价： ");
        scanf("%s", next->price); 
        printf("\t请输入座位容量： ");
        scanf("%s", next->totalSeat); 
        printf("\t请输入已订座位数： ");
        scanf("%s", next->occupiedSeat); 
        if(addIndex < addNum)
            printf("\n\t第%d张机票输入成功，等待2秒后输入下一张", addIndex);
        else
            printf("\n\t最后一张机票输入成功，等待2秒后开始读取飞机票数据");
        Sleep(2000);
        system("cls");
        next->dataIndex = addIndex; // 数据序号
        next->dataLen = 0; // 标志位0
        next->next = NULL;
        pre->next = next;
        pre = next;
    }
    printf("\n\t..............读取中（等待3秒）.............\n\n");
    Sleep(3000);
    head = creatPlane(); // 读取原有数据
    subHead = head->next;
    pre = data->next;
    f = fopen("./飞机票订购系统/allFile/data/planeData.txt", "a"); // 追加
    if(f == NULL) // 文件为空
    {
        getchar();
        perror("\n\t文件打开错误，等待5秒后跳转到管理员界面......");
        Sleep(5000);
        system("cls");
        adminRes();
    }
    else
    {
        while (pre != NULL) // 循环票
        {
            while(subHead != NULL)
            {
                // 是否有重复添加飞机票        
                if(!strcmp(subHead->company, pre->company) && !strcmp(subHead->planeNum, pre->planeNum) && !strcmp(subHead->startPlace, pre->startPlace) && !strcmp(subHead->finalPlace, pre->finalPlace) && !strcmp(subHead->startTime, pre->startTime) && !strcmp(subHead->finalTime, pre->finalTime) && !strcmp(subHead->intervalTime, pre->intervalTime) && !strcmp(subHead->price, pre->price) && !strcmp(subHead->totalSeat, pre->totalSeat) && !strcmp(subHead->occupiedSeat, pre->occupiedSeat))
                {
                    pre->dataLen = 1; // flag为1
                    break;
                }
                subHead = subHead->next;
            }
            if(pre->dataLen)
                printf("\n\t第%d张飞机票已经添加，请勿重复添加！", pre->dataIndex);   
            else
            {
                fprintf(f, "%s %s %s %s %s %s %s %s %s %s\n", pre->company, pre->planeNum, pre->startPlace, pre->finalPlace, pre->startTime, pre->finalTime, pre->intervalTime, pre->price, pre->totalSeat, pre->occupiedSeat);
                printf("\n\t第%d张飞机票添加信息成功！", pre->dataIndex);                
            }     
            subHead = head->next; // 回到开头
            pre = pre->next;
        }
        fclose(f);
        f = NULL;
        getchar();
        printf("\n\t等待5秒后跳转到管理员界面......");
        Sleep(5000);
        system("cls");
        adminRes();
    }
    return ;
}


void findPlaneData(int nextStep)
{
    int choice, // 选择序号
        subChoice, // 是否删除变量
        flag = 0, // 找到的标志
        titleNum = 0, // 标题次数
        total = 0; // 找到的总数
    node *head = NULL,
         *subHead = NULL;
    char findName[20]; // 查找的内容
    system("cls");
    choice = findDataGui();
    printf("\n\t请输入你想要查找的内容： ");
    scanf("%s", findName);
    printf("\n\t----> 		程序在进行		<----|\n");
    head = creatPlane();
    subHead = head->next;
    printf("\n\t查询的结果如下： \n\n"); 
    while (subHead != NULL)
    {
        switch (choice)
        {
            case 1:
                if(strcmp(findName, subHead->company) == 0)
                {
                    flag = 1;
                    titleNum++;
                    total++;
                }
                break;
            case 2:
                if(strcmp(findName, subHead->planeNum) == 0)
                {
                    flag = 1;
                    titleNum++;
                    total++;
                }    
                break;
            case 3:
                if(strcmp(findName, subHead->startPlace) == 0)
                {
                    flag = 1;
                    titleNum++;
                    total++;
                }
                break;
            case 4:
                if(strcmp(findName, subHead->finalPlace) == 0)
                {
                    flag = 1;
                    titleNum++;
                    total++;
                }
                break;
            case 5:
                if(strcmp(findName, subHead->startTime) == 0)
                {
                    flag = 1;
                    titleNum++;
                    total++;
                }
                break;
            case 6:
                if(strcmp(findName, subHead->price) == 0)
                {
                    flag = 1;
                    titleNum++;
                    total++;
                }
                break;
            default:
                break;
        }
        if(flag == 1)
        {
            if(titleNum == 1)
                printf("      航空公司  航班号  起点      终点      起飞时间\t      降落时间\t        飞行时长  票价  座位容量  已订座位数\n"); 
            printf("%4d、", total);
            printf("%-10s", subHead->company);
            printf("%-8s", subHead->planeNum);
            printf("%-10s", subHead->startPlace);
            printf("%-10s", subHead->finalPlace);
            printf("%-18s", subHead->startTime);
            printf("%-18s", subHead->finalTime);
            printf("%-10s", subHead->intervalTime);
            printf("%-6s", subHead->price);
            printf("%-10s", subHead->totalSeat);
            printf("%-10s\n", subHead->occupiedSeat);
            flag = 0;
        }        
        subHead = subHead->next;
    }
    if(!total)
    {
        getchar();
        printf("\n\t抱歉，没有查询到有关%s的飞机数据，将于5秒后跳转到管理员功能界面......", findName);
        Sleep(5000);
        system("cls");
        adminRes();
    }
    else // 是否进行删除数据
    {
        if(nextStep == 0)
        {
            getchar();
            printf("\n\t查找结束，将于5秒后返回管理员功能界面......");
            Sleep(5000);
            system("cls");
            adminRes();
        }
        else
        {
            if(nextStep == 1)
                delData(total, choice, findName, 0);
            else
            {
                if(nextStep == 2)
                {
                    delData(total, choice, findName, 1);
                }
            }
        }
    }
    return ;
}


void delData(int total, int num, char *findName, int change) // num为哪一种选法
{
    int choice, // 哪一条记录
        changeChoice,
        index = 0;
    char ch,
         changeName[20]; // 修改的内容
    FILE *f;
    node *head = NULL,
         *pre = NULL,
         *subHead = NULL;
    head = creatPlane();
    pre = head;
    subHead = head->next;
    if(!change)
        printf("\n\t请输入你想删去哪一条飞机票记录： ");
    else
        printf("\n\t请输入你想要修改哪一条飞机票数据： ");
    getchar();
    choice = rapidInput(1, total);
    while (subHead != NULL)
    {
        switch (num)
        {
            case 1:
                if(strcmp(findName, subHead->company) == 0)
                    index++;
                break;
            case 2:
                if(strcmp(findName, subHead->planeNum) == 0)
                    index++;
                break;
            case 3:
                if(strcmp(findName, subHead->startPlace) == 0)
                    index++;
                break;
            case 4:
                if(strcmp(findName, subHead->finalPlace) == 0)
                    index++;
                break;
            case 5:
                if(strcmp(findName, subHead->startTime) == 0)
                    index++;
                break;
            case 6:
                if(strcmp(findName, subHead->price) == 0)
                    index++;
                break;
            default:
                break;
        }     
        if(index == choice)
        {
            if(change == 0)
                pre->next = subHead->next;
            else
            {
                if(change == 1)
                {
                    changeChoice = changeDataGui();
                    printf("\t请输入你要修改的内容： ");
                    scanf("%s", changeName);
                    switch (changeChoice)
                    {
                        case 1:
                            strcpy(subHead->company, changeName);
                            break;
                        case 2:
                            strcpy(subHead->planeNum, changeName);
                            break;
                        case 3:
                            strcpy(subHead->startPlace, changeName);
                            break;
                        case 4:
                            strcpy(subHead->finalPlace, changeName);
                            break;
                        case 5:
                            strcpy(subHead->startTime, changeName);
                            break;
                        case 6:
                            strcpy(subHead->finalTime, changeName);
                            break;
                        case 7:
                            strcpy(subHead->intervalTime, changeName);
                            break;
                        case 8:
                            strcpy(subHead->price, changeName);
                            break;
                        case 9:
                            strcpy(subHead->totalSeat, changeName);
                            break;
                        case 10:
                            strcpy(subHead->occupiedSeat, changeName);
                            break;
                        default:
                            break;
                    }
                }
            }
            break;
        }  
        pre = subHead;
        subHead = subHead->next;
    }
    subHead = head->next;
    f = fopen("./飞机票订购系统/allFile/data/planeData.txt", "w+"); // 只写    
    if(f == NULL) // 文件不存在
    {
        getchar();
        perror("\t文件打开错误，请等待5秒后跳转到管理员功能界面......");
        Sleep(5000);
        system("cls");
        adminRes();
    }   
    else
    {
        while (subHead != NULL)
        {
            fprintf(f, "%s %s %s %s %s %s %s %s %s %s\n", subHead->company, subHead->planeNum, subHead->startPlace, subHead->finalPlace, subHead->startTime, subHead->finalTime, subHead->intervalTime, subHead->price, subHead->totalSeat, subHead->occupiedSeat);
            subHead = subHead->next;
        }
        fclose(f);
        f = NULL;
        if(change == 0)
            printf("\n\t已经成功删除第%d个飞机票数据，将于5秒后返回管理员功能界面......", choice);
        else
        {
            if(change == 1)
            {
                printf("\n\t已经成功修改第%d个飞机票数据，将于5秒后返回管理员功能界面......", choice);
                getchar();
            }
        }
        Sleep(5000);
        system("cls");
        adminRes();            
    }
}


node *init()
{
    node *head = NULL;
    head = (node *)malloc(nodeLen);
    head->next = NULL;
    return head;
}


node *creatPlane()
{
    node *head = NULL,
         *mid = NULL,
         *next = NULL;
    FILE *f;
    char ch;
    head = init();
    head->dataLen = 0;
    mid = head;
    f = fopen("./飞机票订购系统/allFile/data/planeData.txt", "r");   
    if(f == NULL) // 文件不存在
    {
        getchar();
        perror("\n\t文件打开错误，请等待5秒跳转管理员功能界面......");
        Sleep(5000);
        system("cls");
        adminRes();
    } 
    else
    {
        ch = fgetc(f); // 读取一个字符     
        if(!feof(f))
        {
            rewind(f);
            while (!feof(f))
            {
                head->dataLen++;
                next = (node *)malloc(nodeLen);
                fscanf(f, "%s %s %s %s %s %s %s %s %s %s\n", next->company, next->planeNum, next->startPlace, next->finalPlace, next->startTime, next->finalTime, next->intervalTime, next->price, next->totalSeat, next->occupiedSeat);
                next->dataIndex = head->dataLen;
                next->next = NULL;
                mid->next = next;
                mid = next;                
            }
        } 
    }
    fclose(f);
    f = NULL;
    return head;
}


void printNode(node *head)
{
    node *subHead;
    int total = 0;
    subHead = head->next;
    printf("\n\t得到的结果为：\n\n");
    if(subHead == NULL)
    {
        printf("\t该文件内容为空，请添加航班信息，等待5秒后跳转到管理员功能界面......");
        Sleep(5000);
        system("cls");
        adminRes();
    } 
    else
    {
        printf("      航空公司  航班号  起点      终点      起飞时间\t      降落时间\t        飞行时长  票价  座位容量  已订座位数\n");
        while(subHead != NULL)
        {
            total++;
            printf("%4d、", total);
            printf("%-10s", subHead->company);
            printf("%-8s", subHead->planeNum);
            printf("%-10s", subHead->startPlace);
            printf("%-10s", subHead->finalPlace);
            printf("%-18s", subHead->startTime);
            printf("%-18s", subHead->finalTime);
            printf("%-10s", subHead->intervalTime);
            printf("%-6s", subHead->price);
            printf("%-10s", subHead->totalSeat);
            printf("%-10s\n", subHead->occupiedSeat);
            subHead = subHead->next;
        }
        printf("\n\t将于5秒后跳转管理员功能界面......");
        Sleep(5000);
        system("cls");
        adminRes();
    }
}


void sortData()
{
    int choice,
        flag = 0, // 是否比完
        flagChoice = 0, // 是否选到4 5
        num1,
        num2,
        year1,
        year2,
        month1,
        month2,
        day1,
        day2,
        hour1,
        hour2,
        min1,
        min2,
        i, // 外循环
        j; // 内循环
    node *head,
         *subHead,
         *next;
    char ch,
         subStr1[20],
         subStr2[20],
         temp[20],
         sub[20],
         nextChar[20];
    head = creatPlane();
    subHead = next = head->next;
    system("cls");
    choice = sortDataGui();
    printf("\n\t----> 		程序在进行		<----|\n");   
    if(subHead == NULL)
    {
        printf("\n\t该文件内容为空，请添加航班信息，等待5秒后跳转到管理员功能界面......");
        Sleep(5000);
        system("cls");
        adminRes();
    }
    else
    {
        for(i = 1; i <= head->dataLen - 1; i++)
        {
            for(j = 0; j <= head->dataLen - 1 - i; j++)
            {
                next = subHead->next;
                switch (choice)
                {
                    case 1:
                        strcpy(sub, subHead->company);
                        strcpy(nextChar, next->company);
                        break;
                    case 2:
                        strcpy(sub, subHead->startPlace);
                        strcpy(nextChar, next->startPlace);     
                        break;
                    case 3:
                        strcpy(sub, subHead->finalPlace);
                        strcpy(nextChar, next->finalPlace);    
                        break;
                    case 4:
                        flagChoice = 1;
                        strcpy(sub, subHead->startTime);
                        strcpy(nextChar, next->startTime);     
                        sscanf(sub, "%d/%d/%d/%d:%d", &year1, &month1, &day1, &hour1, &min1);
                        sscanf(nextChar, "%d/%d/%d/%d:%d", &year2, &month2, &day2, &hour2, &min2);
                        if(year1 > year2)
                            flag = 1;
                        else if(year1 == year2 && month1 > month2)
                            flag = 1;
                        else if(year1 == year2 && month1 == month2 && day1 > day2)
                            flag = 1;
                        else if(year1 == year2 && month1 == month2 && day1 == day2 && hour1 > hour2)
                            flag = 1;
                        else
                        {
                            if(year1 == year2 && month1 == month2 && day1 == day2 && hour1 == hour2 && min1 > min2)
                                flag = 1;
                        }   
                        break;
                    case 5:
                        flagChoice = 1;
                        strcpy(sub, subHead->price);
                        strcpy(nextChar, next->price);    
                        num1 = atoi(sub);
                        num2 = atoi(nextChar);
                        if(num1 > num2)
                            flag = 1;
                        break; 
                    default:
                        break;
                }
                if((strcmp(sub, nextChar) > 0 && flagChoice == 0) || flag == 1)
                {

                    strcpy(temp, subHead->company);
                    strcpy(subHead->company, next->company);
                    strcpy(next->company, temp);

                    strcpy(temp, subHead->planeNum);
                    strcpy(subHead->planeNum, next->planeNum);
                    strcpy(next->planeNum, temp);

                    strcpy(temp, subHead->startPlace);
                    strcpy(subHead->startPlace, next->startPlace);
                    strcpy(next->startPlace, temp);

                    strcpy(temp, subHead->finalPlace);
                    strcpy(subHead->finalPlace, next->finalPlace);
                    strcpy(next->finalPlace, temp);    

                    strcpy(temp, subHead->startTime);
                    strcpy(subHead->startTime, next->startTime);
                    strcpy(next->startTime, temp);      

                    strcpy(temp, subHead->finalTime);
                    strcpy(subHead->finalTime, next->finalTime);
                    strcpy(next->finalTime, temp);    

                    strcpy(temp, subHead->intervalTime);
                    strcpy(subHead->intervalTime, next->intervalTime);
                    strcpy(next->intervalTime, temp);       

                    strcpy(temp, subHead->price);
                    strcpy(subHead->price, next->price);
                    strcpy(next->price, temp);   

                    strcpy(temp, subHead->totalSeat);
                    strcpy(subHead->totalSeat, next->totalSeat);
                    strcpy(next->totalSeat, temp);

                    strcpy(temp, subHead->occupiedSeat);
                    strcpy(subHead->occupiedSeat, next->occupiedSeat);
                    strcpy(next->occupiedSeat, temp);                
                }
                subHead = next;
                flag = 0;
                flagChoice = 0;
            }
            subHead = next = head->next;
        }
        printNode(head);
    }
}

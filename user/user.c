#include "user.h"


void userSetting()
{
    char ch,
         userName[21], // 用户名20位
         fileName[21], // 文件夹内的用户名
         filePassword[21], // 文件夹内密码
         password[21], // 密码设置
         confirmPassword[21]; // 确认密码
    FILE *f;
    int i = 0;
    settingGui(userName, password, confirmPassword);
    f = fopen("./飞机票订购系统/allFile/user/userData.txt", "r"); // 只读
    if(f == NULL) // 文件是否不存在
    {
        getchar();
        perror("\n\t文件打开错误，等待5秒后跳转到用户菜单界面......");
        Sleep(5000);
        system("cls");
        userMenuRes();
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
                if(strcmp(userName, fileName) == 0)
                {
                    fclose(f);
                    f = NULL;
                    getchar();
                    printf("\n\t用户名已经存在，请更换用户名，等待5秒后跳转到用户菜单界面......");
                    Sleep(5000);
                    system("cls");
                    userMenuRes();
                }
            }
        }
        fclose(f);
        f = NULL;
    }
    f = fopen("./飞机票订购系统/allFile/user/userData.txt", "a"); // 追加
    if(f == NULL) // 文件为空
    {
        getchar();
        perror("\n\t文件打开错误，等待5秒后跳转到用户菜单界面......");
        Sleep(5000);
        system("cls");
        userMenuRes();
    }
    else
    {
        fprintf(f, "%s %s\n", userName, password);
        fclose(f);
        f = NULL;
        getchar();
        printf("\n\t注册成功！等待5秒后跳转到用户菜单界面......");
        Sleep(5000);
        system("cls");
        userMenuRes();
    }
    return ;   
}


void userEntry()
{
    char inputName[21], // 输入用户名
         inputPassWord[21], // 输入密码
         userName[21], // 用户名字
         password[21]; // 密码
    FILE *f;
    char ch;
    int i = 0, // 字符串索引
        flag1 = 0; // 字串相等判断
    entryGui(inputName, inputPassWord);
    f = fopen("./飞机票订购系统/allFile/user/userData.txt", "r"); // 只读
    if(f == NULL)
    {
        getchar();
        perror("\n\t文件打开错误，等待5秒后跳转到用户菜单界面......");
        Sleep(5000);
        system("cls");
        userMenuRes();
    }
    else
    {
        ch = fgetc(f); // 读取一个字符
        if(feof(f))
        {
            fclose(f);
            f = NULL;
            getchar();
            printf("\n\t该文件内容为空，请注册用户账号后登录，等待5秒后跳转到用户菜单界面......");
            Sleep(5000);
            system("cls");
            userMenuRes();
        }
        else
        {
            rewind(f); // 指针回到开头
            while (!feof(f))
            {
                fscanf(f, "%s  %s\n", userName, password);
                if(strcmp(userName, inputName) == 0) // 如果一样结束
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
                printf("\n\t该用户名不存在，请检查用户名是否拼写正确，等待5秒后跳转到用户菜单界面......");
                Sleep(5000);
                system("cls");
                userMenuRes();
            }
            else
            {
                if(strcmp(password, inputPassWord) == 0) // 密码和设定值相等
                {
                    getchar();
                    printf("\n\t登录成功！等待5秒后跳转到用户功能界面......");
                    Sleep(2000);
                    system("cls");
                    userRes();
                }
                else
                {
                    getchar();
                    printf("\n\t密码错误，等待5秒后跳转到用户菜单界面......");
                    Sleep(5000);
                    system("cls");
                    userMenuRes();
                }
            }
        }
    }
    return ;    
}

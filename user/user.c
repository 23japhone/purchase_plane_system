#include "user.h"


void userSetting()
{
    char ch,
         userName[21], // �û���20λ
         fileName[21], // �ļ����ڵ��û���
         filePassword[21], // �ļ���������
         password[21], // ��������
         confirmPassword[21]; // ȷ������
    FILE *f;
    int i = 0;
    settingGui(userName, password, confirmPassword);
    f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/user/userData.txt", "r"); // ֻ��
    if(f == NULL) // �ļ��Ƿ񲻴���
    {
        getchar();
        perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת���û��˵�����......");
        Sleep(5000);
        system("cls");
        userMenuRes();
    }
    else
    {
        ch = fgetc(f); // �ж��ļ��Ƿ��ǿյ�
        if(!feof(f)) // ���ǿյģ��Ϳ��Զ���
        {
            rewind(f); // �ص��ļ���ͷ
            while (!feof(f))
            {
                fscanf(f, "%s %s\n", fileName, filePassword);
                if(strcmp(userName, fileName) == 0)
                {
                    fclose(f);
                    f = NULL;
                    getchar();
                    printf("\n\t�û����Ѿ����ڣ�������û������ȴ�5�����ת���û��˵�����......");
                    Sleep(5000);
                    system("cls");
                    userMenuRes();
                }
            }
        }
        fclose(f);
        f = NULL;
    }
    f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/user/userData.txt", "a"); // ׷��
    if(f == NULL) // �ļ�Ϊ��
    {
        getchar();
        perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת���û��˵�����......");
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
        printf("\n\tע��ɹ����ȴ�5�����ת���û��˵�����......");
        Sleep(5000);
        system("cls");
        userMenuRes();
    }
    return ;   
}


void userEntry()
{
    char inputName[21], // �����û���
         inputPassWord[21], // ��������
         userName[21], // �û�����
         password[21]; // ����
    FILE *f;
    char ch;
    int i = 0, // �ַ�������
        flag1 = 0; // �ִ�����ж�
    entryGui(inputName, inputPassWord);
    f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/user/userData.txt", "r"); // ֻ��
    if(f == NULL)
    {
        getchar();
        perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת���û��˵�����......");
        Sleep(5000);
        system("cls");
        userMenuRes();
    }
    else
    {
        ch = fgetc(f); // ��ȡһ���ַ�
        if(feof(f))
        {
            fclose(f);
            f = NULL;
            getchar();
            printf("\n\t���ļ�����Ϊ�գ���ע���û��˺ź��¼���ȴ�5�����ת���û��˵�����......");
            Sleep(5000);
            system("cls");
            userMenuRes();
        }
        else
        {
            rewind(f); // ָ��ص���ͷ
            while (!feof(f))
            {
                fscanf(f, "%s  %s\n", userName, password);
                if(strcmp(userName, inputName) == 0) // ���һ������
                {
                    flag1 = 1; // ��ȱ�־λ1
                    break;
                }
            }
            fclose(f);
            f = NULL;
            if(flag1 != 1)
            {
                getchar();
                printf("\n\t���û��������ڣ������û����Ƿ�ƴд��ȷ���ȴ�5�����ת���û��˵�����......");
                Sleep(5000);
                system("cls");
                userMenuRes();
            }
            else
            {
                if(strcmp(password, inputPassWord) == 0) // ������趨ֵ���
                {
                    getchar();
                    printf("\n\t��¼�ɹ����ȴ�5�����ת���û����ܽ���......");
                    Sleep(2000);
                    system("cls");
                    userRes();
                }
                else
                {
                    getchar();
                    printf("\n\t������󣬵ȴ�5�����ת���û��˵�����......");
                    Sleep(5000);
                    system("cls");
                    userMenuRes();
                }
            }
        }
    }
    return ;    
}

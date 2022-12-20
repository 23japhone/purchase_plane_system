/*
 * @Author: 23japhone
 * @Date: 2022-11-27 16:55:36
 * @LastEditors: 23japhone
 * @LastEditTime: 2022-12-19 18:07:45
 * @description: ����Ա����
 */
#include "admin.h"


void adminSetting() 
{
    char ch,
         adminName[21], // �û���20λ
         password[21], // ��������
         confirmPassword[21], // ȷ������
         fileName[21], // �ļ����ڵ��û���
         filePassword[21]; // �ļ���������
    FILE *f;
    int i = 0;
    settingGui(adminName, password, confirmPassword);
    f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/admin/adminData.txt", "r"); // ֻ��
    if(f == NULL) // �ļ��Ƿ񲻴���
    {
        getchar(); // ��ȡ����ո�
        perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת������Ա�˵�����......");
        Sleep(5000);
        system("cls");
        adminMenuRes();
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
                if(strcmp(adminName, fileName) == 0)
                {
                    fclose(f);
                    f = NULL;
                    getchar(); // ��ȡ����ո�
                    printf("\n\t�û����Ѿ����ڣ�������û������ȴ�5�����ת������Ա�˵�����......");
                    Sleep(5000);
                    system("cls");
                    adminMenuRes();
                }
            }
        }
        fclose(f);
        f = NULL;
    }
    f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/admin/adminData.txt", "a"); // ׷��
    if(f == NULL) // �ļ�Ϊ��
    {
        getchar(); 
        perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת������Ա�˵�����......");
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
        printf("\n\tע��ɹ����ȴ�5�����ת������Ա�˵�����......");
        Sleep(5000);
        system("cls");
        adminMenuRes();
    }
    return ;
}


void adminEntry()
{
    char inputName[21], // �����û���
         inputPassWord[21], // ��������
         adminName[21], // ����Ա����
         password[21]; // ����
    FILE *f;
    char ch;
    int i = 0, // �ַ�������
        flag1 = 0; // �ִ�����ж�
    entryGui(inputName, inputPassWord);
    f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/admin/adminData.txt", "r"); // ֻ��
    if(f == NULL)
    {
        getchar();
        perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת������Ա�˵�����......");
        Sleep(5000);
        system("cls");
        adminMenuRes();
    }
    else
    {
        ch = fgetc(f); // ��ȡһ���ַ�
        if(feof(f))
        {
            fclose(f);
            f = NULL;   
            getchar();
            printf("\n\t���ļ�����Ϊ�գ���ע���˺ź��¼���ȴ�5�����ת������Ա�˵�����......");         
            Sleep(5000);
            system("cls");
            adminMenuRes();
        }
        else
        {
            rewind(f); // ָ��ص���ͷ
            while (!feof(f))
            {
                fscanf(f, "%s  %s\n", adminName, password);
                if(strcmp(adminName, inputName) == 0) // ���һ������
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
                printf("\n\t�ù���Ա�������ڣ������û����Ƿ�ƴд��ȷ���ȴ�5�����ת������Ա�˵�����......");
                Sleep(5000);
                system("cls");
                adminMenuRes();
            }
            else
            {
                if(strcmp(password, inputPassWord) == 0) // ������趨ֵ���
                {
                    getchar();
                    printf("\n\t��¼�ɹ����ȴ�5�����ת������Ա���ܽ���......");
                    Sleep(5000);
                    system("cls");
                    adminRes();
                }
                else
                {
                    getchar();
                    printf("\n\t������󣬵ȴ�5�����ת������Ա�˵�����......");
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
    int addIndex, // add������
        addNum; // ��ӷɻ�Ʊ
    FILE *f;
    node *head = NULL, // �ļ���Ʊͷ
         *subHead = NULL, // �����ļ���Ʊͷ
         *pre = NULL, // ǰһ����ַ
         *next = NULL, // ��һ����ַ
         *data = init(); // ��Ϊͷ
    pre = data; // ��������ͷ
    printf("\n\t����������Ҫ��Ӽ��ຽ����Ϣ�� ");
    scanf("%d", &addNum);
    printf("\n\t3�����ת����ӷɻ�Ʊҳ��......");
    Sleep(3000);
    system("cls");
    for(addIndex = 1; addIndex <= addNum; addIndex++)
    {
        next = (node *)malloc(nodeLen); // ����ռ�
        printf("\t�����뺽�չ�˾�� ");
        scanf("%s", next->company); 
        printf("\t�����뺽��ţ� ");
        scanf("%s", next->planeNum);
        printf("\t��������㣺 ");
        scanf("%s", next->startPlace); 
        printf("\t�������յ㣺 ");
        scanf("%s", next->finalPlace); 
        printf("\t���������ʱ�䣨�磺2022/1/1/13:10���� ");
        scanf("%s", next->startTime); 
        printf("\t�����뽵��ʱ�䣨�磺2022/1/1/13:10���� ");
        scanf("%s", next->finalTime); 
        printf("\t���������ʱ�䣨�磺1h20min���� ");
        scanf("%s", next->intervalTime); 
        printf("\t������Ʊ�ۣ� ");
        scanf("%s", next->price); 
        printf("\t��������λ������ ");
        scanf("%s", next->totalSeat); 
        printf("\t�������Ѷ���λ���� ");
        scanf("%s", next->occupiedSeat); 
        if(addIndex < addNum)
            printf("\n\t��%d�Ż�Ʊ����ɹ����ȴ�2���������һ��", addIndex);
        else
            printf("\n\t���һ�Ż�Ʊ����ɹ����ȴ�2���ʼ��ȡ�ɻ�Ʊ����");
        Sleep(2000);
        system("cls");
        next->dataIndex = addIndex; // �������
        next->dataLen = 0; // ��־λ0
        next->next = NULL;
        pre->next = next;
        pre = next;
    }
    printf("\n\t..............��ȡ�У��ȴ�3�룩.............\n\n");
    Sleep(3000);
    head = creatPlane(); // ��ȡԭ������
    subHead = head->next;
    pre = data->next;
    f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/data/planeData.txt", "a"); // ׷��
    if(f == NULL) // �ļ�Ϊ��
    {
        getchar();
        perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת������Ա����......");
        Sleep(5000);
        system("cls");
        adminRes();
    }
    else
    {
        while (pre != NULL) // ѭ��Ʊ
        {
            while(subHead != NULL)
            {
                // �Ƿ����ظ���ӷɻ�Ʊ        
                if(!strcmp(subHead->company, pre->company) && !strcmp(subHead->planeNum, pre->planeNum) && !strcmp(subHead->startPlace, pre->startPlace) && !strcmp(subHead->finalPlace, pre->finalPlace) && !strcmp(subHead->startTime, pre->startTime) && !strcmp(subHead->finalTime, pre->finalTime) && !strcmp(subHead->intervalTime, pre->intervalTime) && !strcmp(subHead->price, pre->price) && !strcmp(subHead->totalSeat, pre->totalSeat) && !strcmp(subHead->occupiedSeat, pre->occupiedSeat))
                {
                    pre->dataLen = 1; // flagΪ1
                    break;
                }
                subHead = subHead->next;
            }
            if(pre->dataLen)
                printf("\n\t��%d�ŷɻ�Ʊ�Ѿ���ӣ������ظ���ӣ�", pre->dataIndex);   
            else
            {
                fprintf(f, "%s %s %s %s %s %s %s %s %s %s\n", pre->company, pre->planeNum, pre->startPlace, pre->finalPlace, pre->startTime, pre->finalTime, pre->intervalTime, pre->price, pre->totalSeat, pre->occupiedSeat);
                printf("\n\t��%d�ŷɻ�Ʊ�����Ϣ�ɹ���", pre->dataIndex);                
            }     
            subHead = head->next; // �ص���ͷ
            pre = pre->next;
        }
        fclose(f);
        f = NULL;
        getchar();
        printf("\n\t�ȴ�5�����ת������Ա����......");
        Sleep(5000);
        system("cls");
        adminRes();
    }
    return ;
}


void findPlaneData(int nextStep)
{
    int choice, // ѡ�����
        subChoice, // �Ƿ�ɾ������
        flag = 0, // �ҵ��ı�־
        titleNum = 0, // �������
        total = 0; // �ҵ�������
    node *head = NULL,
         *subHead = NULL;
    char findName[20]; // ���ҵ�����
    system("cls");
    choice = findDataGui();
    printf("\n\t����������Ҫ���ҵ����ݣ� ");
    scanf("%s", findName);
    printf("\n\t----> 		�����ڽ���		<----|\n");
    head = creatPlane();
    subHead = head->next;
    printf("\n\t��ѯ�Ľ�����£� \n\n"); 
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
                printf("      ���չ�˾  �����  ���      �յ�      ���ʱ��\t      ����ʱ��\t        ����ʱ��  Ʊ��  ��λ����  �Ѷ���λ��\n"); 
            printf("%4d��", total);
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
        printf("\n\t��Ǹ��û�в�ѯ���й�%s�ķɻ����ݣ�����5�����ת������Ա���ܽ���......", findName);
        Sleep(5000);
        system("cls");
        adminRes();
    }
    else // �Ƿ����ɾ������
    {
        if(nextStep == 0)
        {
            getchar();
            printf("\n\t���ҽ���������5��󷵻ع���Ա���ܽ���......");
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


void delData(int total, int num, char *findName, int change) // numΪ��һ��ѡ��
{
    int choice, // ��һ����¼
        changeChoice,
        index = 0;
    char ch,
         changeName[20]; // �޸ĵ�����
    FILE *f;
    node *head = NULL,
         *pre = NULL,
         *subHead = NULL;
    head = creatPlane();
    pre = head;
    subHead = head->next;
    if(!change)
        printf("\n\t����������ɾȥ��һ���ɻ�Ʊ��¼�� ");
    else
        printf("\n\t����������Ҫ�޸���һ���ɻ�Ʊ���ݣ� ");
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
                    printf("\t��������Ҫ�޸ĵ����ݣ� ");
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
    f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/data/planeData.txt", "w+"); // ֻд    
    if(f == NULL) // �ļ�������
    {
        getchar();
        perror("\t�ļ��򿪴�����ȴ�5�����ת������Ա���ܽ���......");
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
            printf("\n\t�Ѿ��ɹ�ɾ����%d���ɻ�Ʊ���ݣ�����5��󷵻ع���Ա���ܽ���......", choice);
        else
        {
            if(change == 1)
            {
                printf("\n\t�Ѿ��ɹ��޸ĵ�%d���ɻ�Ʊ���ݣ�����5��󷵻ع���Ա���ܽ���......", choice);
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
    f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/data/planeData.txt", "r");   
    if(f == NULL) // �ļ�������
    {
        getchar();
        perror("\n\t�ļ��򿪴�����ȴ�5����ת����Ա���ܽ���......");
        Sleep(5000);
        system("cls");
        adminRes();
    } 
    else
    {
        ch = fgetc(f); // ��ȡһ���ַ�     
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
    printf("\n\t�õ��Ľ��Ϊ��\n\n");
    if(subHead == NULL)
    {
        printf("\t���ļ�����Ϊ�գ�����Ӻ�����Ϣ���ȴ�5�����ת������Ա���ܽ���......");
        Sleep(5000);
        system("cls");
        adminRes();
    } 
    else
    {
        printf("      ���չ�˾  �����  ���      �յ�      ���ʱ��\t      ����ʱ��\t        ����ʱ��  Ʊ��  ��λ����  �Ѷ���λ��\n");
        while(subHead != NULL)
        {
            total++;
            printf("%4d��", total);
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
        printf("\n\t����5�����ת����Ա���ܽ���......");
        Sleep(5000);
        system("cls");
        adminRes();
    }
}


void sortData()
{
    int choice,
        flag = 0, // �Ƿ����
        flagChoice = 0, // �Ƿ�ѡ��4 5
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
        i, // ��ѭ��
        j; // ��ѭ��
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
    printf("\n\t----> 		�����ڽ���		<----|\n");   
    if(subHead == NULL)
    {
        printf("\n\t���ļ�����Ϊ�գ�����Ӻ�����Ϣ���ȴ�5�����ת������Ա���ܽ���......");
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

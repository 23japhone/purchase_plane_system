#include "TICKETS.h"


void book( )
{
    int i, 
        j = 0, 
        k = 0, 
        tIndex = 0,
        fileFlag = 0,
        overFlag = 0,
        ttotal,
        tcur,
        seat,
        num1,
        num2,
        num3,
        result,
        purchaseNum,
        subPurChaseNum,
        flag = 0,
        a[20] = {0};
    char ch,
         start[20], 
         end[20], 
         flight[8];
    FILE *fp = NULL,
         *f = NULL;
    ticket t1[100];
    printf("\n\t��������ĳ����㣺 ");
    scanf("%s", start);
    printf("\t���������Ŀ�ĵأ� ");
    scanf("%s", end);
	printf("\n\t----> 		�����ڽ���		<----|\n");
    result = readFile("./�ɻ�Ʊ����ϵͳ/allFile/data/planeData.txt", t);
    printf("\n\t��ѯ���ĺ������£� \n\n");  
    for(i = 0; i < result; i++)
    {
        if(strcmp(start, t[i].starting) == 0)
        {
            if(strcmp(end, t[i].ending) == 0)
            {
                a[j]=i;
                j++;
                if(j == 1)
                    printf("      ���չ�˾  �����  ���      �յ�      ���ʱ��\t      ����ʱ��\t        ����ʱ��  Ʊ��  ��λ����  �Ѷ���λ��\n");
                printf("%4d��", j);
                printf("%-10s", t[i].company);
                printf("%-8s", t[i].num);
                printf("%-10s", t[i].starting);
                printf("%-10s", t[i].ending);
                printf("%-18s", t[i].takeoff);
                printf("%-18s", t[i].landing);
                printf("%-10s", t[i].period);
                printf("%-6s", t[i].price);
                printf("%-10s", t[i].all);
                printf("%-10s\n", t[i].reserved);
                k = 1;
            }
        }
    }
    if(k == 0 || result == 0)
    {
        getchar();
        printf("\t��Ǹ��û�в�ѯ���ú��࣬ϵͳ����5��󷵻��û����ܽ���......");
        Sleep(5000);
        system("cls");
        userRes();
    }
    else
    {
        printf("\n\t��ѡ�������������ĺ���ţ� ");
        scanf("%s", flight);
        printf("\t���������빺���Ż�Ʊ�� ");
        scanf("%d", &purchaseNum);
        f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/user/purchaseData.txt", "r"); // ֻ���鿴�Ƿ��Ѷ�
        if(f == NULL)
        {
            getchar();
            perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת���û����ܽ���......");
            Sleep(5000);
            system("cls");
            userRes();
        }
        else
        {
            ch = fgetc(f);
            if(feof(f))
                fileFlag = 1;
            rewind(f);
            for(j; j >= 1; j--)     
            {
                if(strcmp(flight, t[a[j - 1]].num) == 0) // �ҵ���
                {
                    while (!feof(f) && fileFlag != 1) // ���ļ�
                    {
                        fscanf(f, "%s %s %s %s %s %s %s %s\n", t1[tIndex].company, t1[tIndex].num, t1[tIndex].starting, t1[tIndex].ending, t1[tIndex].takeoff, t1[tIndex].landing, t1[tIndex].price, t1[tIndex].purchaseTotal);
                        if(strcmp(t[a[j - 1]].company, t1[tIndex].company) == 0 && strcmp(t[a[j - 1]].num, t1[tIndex].num) == 0 && strcmp(t[a[j - 1]].starting, t1[tIndex].starting) == 0 && strcmp(t[a[j - 1]].ending, t1[tIndex].ending) == 0 && strcmp(t[a[j - 1]].takeoff, t1[tIndex].takeoff) == 0 && strcmp(t[a[j - 1]].landing, t1[tIndex].landing) == 0 && strcmp(t[a[j - 1]].price, t1[tIndex].price) == 0)
                        {
                            tcur = tIndex;
                            flag = 1;
                        }
                        tIndex++;
                    }
                    num1 = atoi(t[a[j - 1]].all);
                    num2 = atoi(t[a[j - 1]].reserved);
                    num3 = num2 + purchaseNum;
                    if(num3 > num1)
                    {
                        overFlag = 1;
                        break;
                    }
                    if(flag == 0)
                    {
                        sprintf(t[a[j - 1]].purchaseTotal, "%d", purchaseNum);
                        strcpy(t1[tIndex].company, t[a[j - 1]].company);
                        strcpy(t1[tIndex].num, t[a[j - 1]].num);
                        strcpy(t1[tIndex].starting, t[a[j - 1]].starting);
                        strcpy(t1[tIndex].ending, t[a[j - 1]].ending);
                        strcpy(t1[tIndex].takeoff, t[a[j - 1]].takeoff);
                        strcpy(t1[tIndex].landing, t[a[j - 1]].landing);
                        strcpy(t1[tIndex].price, t[a[j - 1]].price);
                        strcpy(t1[tIndex].purchaseTotal, t[a[j - 1]].purchaseTotal);
                        tIndex++;
                    }
                    ttotal = tIndex;
                    printf("\n\t..............��Ʊ�У��ȴ�3�룩.............\n\n");
                    Sleep(3000);
                    seat = atoi(t[a[j - 1]].reserved);
                    seat += purchaseNum;
                    sprintf(t[a[j - 1]].reserved, "%d", seat);
                    if(flag)
                    {
                        subPurChaseNum = atoi(t1[tcur].purchaseTotal);
                        subPurChaseNum += purchaseNum;
                        sprintf(t1[tcur].purchaseTotal, "%d", subPurChaseNum);
                    }
                    printf("      ���չ�˾  �����  ���      �յ�      ���ʱ��\t      ����ʱ��\t        ����ʱ��  Ʊ��  ��λ����  �Ѷ���λ��\n");
                    printf("%4d��", 1);
                    printf("%-10s", t[a[j - 1]].company);
                    printf("%-8s", t[a[j - 1]].num);
                    printf("%-10s", t[a[j - 1]].starting);
                    printf("%-10s", t[a[j - 1]].ending);
                    printf("%-18s", t[a[j - 1]].takeoff);
                    printf("%-18s", t[a[j - 1]].landing);
                    printf("%-10s", t[a[j - 1]].period);
                    printf("%-6s", t[a[j - 1]].price);
                    printf("%-10s", t[a[j - 1]].all);
                    printf("%-10s\n", t[a[j - 1]].reserved);
                    writeFile("./�ɻ�Ʊ����ϵͳ/allFile/data/planeData.txt", t, result);
                    break;                        
                }
            }      
            fclose(f);
            f = NULL;
        }
        if(overFlag == 1)
        {
            getchar();
            printf("\n\t�ɻ�ʣ����λ�����������¹���ϵͳ����5�����ת���û�����......");
            Sleep(5000);
            system("cls");
            userRes();
        }
        else
        {
            f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/user/purchaseData.txt", "w+");
            if(f == NULL)
            {
                getchar();
                perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת���û����ܽ���......");
                Sleep(5000);
                system("cls");
                userRes();
            }       
            else
            {   
                for(tIndex = 0; tIndex < ttotal; tIndex++)
                    fprintf(f, "%s %s %s %s %s %s %s %s\n", t1[tIndex].company, t1[tIndex].num, t1[tIndex].starting, t1[tIndex].ending, t1[tIndex].takeoff, t1[tIndex].landing, t1[tIndex].price, t1[tIndex].purchaseTotal);
            }    
            fclose(f);
            f = NULL; 
            getchar();
            printf("\n\t����ɹ�������5�����ת���û����ܽ���......");
            Sleep(5000);
            system("cls");
            userRes();
        }
    }      
}


void cancel()
{
    int i, 
        j = 0, 
        k = 0, 
        tIndex = 0,
        ttotal,
        tcur,
        fileFlag = 0,
        seat,
        cancelNum,
        purchaseTotal,
        subPurChaseNum,
        flag = 0,
        result,
        a[20] = {0};
    char ch,
         start[20], 
         end[20], 
         flight[8];
    FILE *fp = NULL,
         *f = NULL;
    ticket t1[100];
    printf("\n\t��������ĳ����㣺 ");
    scanf("%s", start);
    printf("\t���������Ŀ�ĵأ� ");
    scanf("%s", end);
	printf("\n\t----> 		�����ڽ���		<----|\n");
    result = readFile("./�ɻ�Ʊ����ϵͳ/allFile/data/planeData.txt", t);
    printf("\n\t��ѯ���ĺ������£� \n\n"); 
    for(i = 0; i < result; i++)
    {
        if(strcmp(start, t[i].starting) == 0)
        {
            if(strcmp(end, t[i].ending) == 0)
            {
                a[j]=i;
                j++;
                if(j == 1)
                    printf("      ���չ�˾  �����  ���      �յ�      ���ʱ��\t      ����ʱ��\t        ����ʱ��  Ʊ��  ��λ����  �Ѷ���λ��\n"); 
                printf("%4d��", j);
                printf("%-10s", t[i].company);
                printf("%-8s", t[i].num);
                printf("%-10s", t[i].starting);
                printf("%-10s", t[i].ending);
                printf("%-18s", t[i].takeoff);
                printf("%-18s", t[i].landing);
                printf("%-10s", t[i].period);
                printf("%-6s", t[i].price);
                printf("%-10s", t[i].all);
                printf("%-10s\n", t[i].reserved);
                k = 1;
            }
        }
    }
    if(k == 0 || result == 0)
    {
        getchar();
        printf("\t��Ǹ��δ��ѯ����Ʊ��¼��ϵͳ����5��󷵻��û����ܽ���......");
        Sleep(5000);
        system("cls");
        userRes();
    }
    else
    {
        printf("\n\t��ѡ���������ĺ���ţ� ");
        scanf("%s", flight);
        printf("\t�����������˼��Ż�Ʊ�� ");
        scanf("%d", &cancelNum);      
        f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/user/purchaseData.txt", "r"); // ֻ���鿴�Ƿ��Ѷ�  
        if(f == NULL)
        {
            getchar();
            perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת���û����ܽ���......");
            Sleep(5000);
            system("cls");
            userRes();
        }
        else
        {
            ch = fgetc(f);
            if(feof(f))
                fileFlag = 1;
            rewind(f);
            for(j; j >= 1; j--)     
            {
                if(strcmp(flight, t[a[j - 1]].num) == 0) // �ҵ���
                {
                    while (!feof(f) && fileFlag != 1) // ���ļ�
                    {
                        fscanf(f, "%s %s %s %s %s %s %s %s\n", t1[tIndex].company, t1[tIndex].num, t1[tIndex].starting, t1[tIndex].ending, t1[tIndex].takeoff, t1[tIndex].landing, t1[tIndex].price, t1[tIndex].purchaseTotal);
                        if(strcmp(t[a[j - 1]].company, t1[tIndex].company) == 0 && strcmp(t[a[j - 1]].num, t1[tIndex].num) == 0 && strcmp(t[a[j - 1]].starting, t1[tIndex].starting) == 0 && strcmp(t[a[j - 1]].ending, t1[tIndex].ending) == 0 && strcmp(t[a[j - 1]].takeoff, t1[tIndex].takeoff) == 0 && strcmp(t[a[j - 1]].landing, t1[tIndex].landing) == 0 && strcmp(t[a[j - 1]].price, t1[tIndex].price) == 0)
                        {
                            tcur = tIndex;
                            flag = 1;
                        }
                        tIndex++;
                    }      
                    if(flag == 0)
                        break;
                    purchaseTotal = atoi(t1[tcur].purchaseTotal);
                    if(cancelNum > purchaseTotal)
                        break;                           
                    ttotal = tIndex;       
                    printf("\n\t..............��Ʊ�У��ȴ�3�룩.............\n\n");
                    Sleep(3000);
                    seat = atoi(t[a[j - 1]].reserved);
                    seat -= cancelNum;
                    sprintf(t[a[j - 1]].reserved, "%d", seat);
                    subPurChaseNum = atoi(t1[tcur].purchaseTotal);
                    subPurChaseNum -= cancelNum;
                    sprintf(t1[tcur].purchaseTotal, "%d", subPurChaseNum);
                    printf("      ���չ�˾  �����  ���      �յ�      ���ʱ��\t      ����ʱ��\t        ����ʱ��  Ʊ��  ��λ����  �Ѷ���λ��\n");         
                    printf("%4d��", 1);
                    printf("%-10s", t[a[j - 1]].company);
                    printf("%-8s", t[a[j - 1]].num);
                    printf("%-10s", t[a[j - 1]].starting);
                    printf("%-10s", t[a[j - 1]].ending);
                    printf("%-18s", t[a[j - 1]].takeoff);
                    printf("%-18s", t[a[j - 1]].landing);
                    printf("%-10s", t[a[j - 1]].period);
                    printf("%-6s", t[a[j - 1]].price);
                    printf("%-10s", t[a[j - 1]].all);
                    printf("%-10s\n", t[a[j - 1]].reserved);
                    writeFile("./�ɻ�Ʊ����ϵͳ/allFile/data/planeData.txt", t, result);
                    break;                                                           
                }        
            }    
            fclose(f);
            f = NULL;
            if(flag == 0)
            {
                getchar();
                printf("\n\t��Ǹ��Ʊʧ�ܣ�����δ����ú��࣬ϵͳ����5��󷵻��û����ܽ���......");
                Sleep(5000);
                system("cls");
                userRes();
            }
            if(cancelNum > purchaseTotal)
            {
                getchar();
                printf("\n\t��Ǹ��Ʊʧ�ܣ���Ʊ�������ڹ���������ϵͳ����5��󷵻��û����ܽ���......");
                Sleep(5000);
                system("cls");
                userRes();                
            }
        }
        if(flag == 1 && cancelNum <= purchaseTotal)
        {
            f = fopen("./�ɻ�Ʊ����ϵͳ/allFile/user/purchaseData.txt", "w+");
            if(f == NULL)
            {
                getchar();
                perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת���û����ܽ���......");
                Sleep(5000);
                system("cls");
                userRes();
            }       
            else
            {   
                for(tIndex = 0; tIndex < ttotal; tIndex++)
                    fprintf(f, "%s %s %s %s %s %s %s %s\n", t1[tIndex].company, t1[tIndex].num, t1[tIndex].starting, t1[tIndex].ending, t1[tIndex].takeoff, t1[tIndex].landing, t1[tIndex].price, t1[tIndex].purchaseTotal);
            }    
            fclose(f);
            f = NULL;     
            getchar();
            printf("\n\t��Ʊ�ɹ�������5�����ת���û����ܽ���......");
            Sleep(5000);
            system("cls");
            userRes();       
        }

    }
}


int readFile(char *fname, ticket TICKET[])
{
    int i = 0,
        result = 0;
    FILE *fp;
    fp = fopen(fname, "r");
    if(fp == NULL)
    {
        perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת���û�����......");
        Sleep(5000);
        system("cls");
        userRes();
    }
    while(!feof(fp))
    {
        result++;
        fscanf(fp, "%s %s %s %s %s %s %s %s %s %s\n", TICKET[i].company, TICKET[i].num, TICKET[i].starting, TICKET[i].ending, TICKET[i].takeoff, TICKET[i].landing, TICKET[i].period, TICKET[i].price, TICKET[i].all, TICKET[i].reserved);
        i++;
    }
    fclose(fp);
    fp = NULL;
    return result;
}


void writeFile(char *fname, ticket TICKET[], int result)
{
    int i = 0;
    FILE *fp;
    fp = fopen(fname, "w+");
    if(fp == NULL)
    {
        perror("\n\t�ļ��򿪴��󣬵ȴ�5�����ת���û�����......");
        Sleep(2000);
        system("cls");
        userRes();
    }
    for(i; i < result; i++)
        fprintf(fp, "%s %s %s %s %s %s %s %s %s %s\n", TICKET[i].company, TICKET[i].num, TICKET[i].starting, TICKET[i].ending, TICKET[i].takeoff, TICKET[i].landing, TICKET[i].period, TICKET[i].price, TICKET[i].all, TICKET[i].reserved);
    fclose(fp);
    fp = NULL;
}

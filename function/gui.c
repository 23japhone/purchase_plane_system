#include "gui.h"


int adminMenu() // ����Ա�˵�
{
	int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	    ***************��ӭ��������Ա�Ĳ�������*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );	
	printf ( "	|----> 1: ����Ա��¼                                                     <----|\n" );
	printf ( "	|----> 2������Աע��                                                     <----|\n" );	
    printf ( "	|----> 3��������һ��                                                     <----|\n" );
    printf ( "	|----> 4���˳�����                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = rapidInput(1, 4);
	return choice;
}


void adminMenuRes()
{
	int choice = adminMenu();
	// �ȸ����û�ע��
	printf("\n\t----> 		�����ڽ���		<----|\n");	
	switch (choice)
	{
		case 1:
			adminEntry();
			break;
		case 2:
			adminSetting();
			break;
		case 3:
			printf("\n\t����3�����ת����ʼ����......");
            Sleep(3000);
            system("cls");
            menuRes();
            break;	
		case 4:
			printf("\n\t�����������л����ʹ��лл��\n");	
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
	printf ( "            	      ***************��ӭ�����û��Ĳ�������*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );	
	printf ( "	|----> 1: �û���¼                                                       <----|\n" );
	printf ( "	|----> 2���û�ע��                                                       <----|\n" );	
    printf ( "	|----> 3��������һ��                                                     <----|\n" );
    printf ( "	|----> 4���˳�����                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = rapidInput(1, 4);
	return choice;	
}


void userMenuRes()
{
	int choice = userMenu();
	// �ȸ����û�ע��
	printf("\n\t----> 		�����ڽ���		<----|\n");	
	switch (choice)
	{
		case 1:
			userEntry();
			break;
		case 2:
			userSetting();
			break;
		case 3:
			printf("\n\t����3�����ת����ʼ����......");
            Sleep(3000);
            system("cls");
            menuRes();
            break;	
		case 4:
			printf("\n\t�����������л����ʹ��лл��\n");	
			break;				
		default:
			break;
	}
	return ;	
}


int menu() // �˵�
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	    ***************��ӭ�����ɻ�Ʊ�Ķ���ϵͳ*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );
	printf ( "	|----> 1: ����Ա                                                         <----|\n" );
	printf ( "	|----> 2���û�                                                           <----|\n" );
    printf ( "	|----> 3���˳�����                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = rapidInput(1, 3);
	return choice;
}


void menuRes()
{
	int choice = menu();
	// �ȸ����û�ע��
	printf("\n\t----> 		�����ڽ���		<----|\n");
	switch (choice)
	{
		case 1:
			printf("\n\tϵͳ����3�����ת������Ա�˵�����......");
			Sleep(3000);
			system("cls");
			adminMenuRes();
			break;
		case 2:
			printf("\n\tϵͳ����3�����ת���û��˵�����......");
			Sleep(3000);
			system("cls");
			userMenuRes();
			break;	
		case 3:
			printf("\n\t�����������л����ʹ��лл��\n");
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
	printf ( "            	   ***************��ӭ��������Ա��������*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );
	printf ( "	|----> 1: ������Ʊ����                                                   <----|\n" );
	printf ( "	|----> 2: ɾ����Ʊ����                                                   <----|\n" );
	printf ( "	|----> 3: ���һ�Ʊ����                                                   <----|\n" );
	printf ( "	|----> 4: �����Ʊ����                                                   <----|\n" );
    printf ( "	|----> 5: ��ʾ���л�Ʊ                                                   <----|\n" );
	printf ( "	|----> 6: �޸ĵ�����Ʊ                                                   <----|\n" );
	printf ( "	|----> 7�����ع���Ա�˵�                                                 <----|\n" );
    printf ( "	|----> 8���˳�����                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = rapidInput(1, 8);
	return choice;
}


void adminRes()
{
    int choice = adminGui();
	node *head = NULL;
	// �ȸ����û�ע��
    switch (choice)
    {
        case 1:
			printf("\n\t----> 		�����ڽ���		<----|\n");
            addPlaneData();	
            break;
        case 2:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת��ɾ��ҳ��......");
			Sleep(3000);
            findPlaneData(1);
            break;
        case 3:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת������ҳ��......");
			Sleep(3000);
            findPlaneData(0);
            break;
        case 4:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת������ҳ��......");
			Sleep(3000);
            sortData();
			break;
        case 5:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת����ʾ��Ʊҳ��......");
			Sleep(3000);
			system("cls");
			head = creatPlane();
			printNode(head);
            break;
		case 6:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת������ҳ��......");
			Sleep(3000);
            findPlaneData(2);	
			break;		
        case 7:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\n\t����3�����ת������Ա�˵�����......");
            Sleep(3000);
            system("cls");
			adminMenuRes();
            break;
		case 8:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\n\t�����������л����ʹ��лл��\n");
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
	printf ( "            	  ***************��ӭ�������ҷɻ�Ʊ���ݽ���*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );
	printf ( "	|----> 1: �����չ�˾����                                                 <----|\n" );	
	printf ( "	|----> 2: ������Ų���                                                   <----|\n" );
	printf ( "	|----> 3: ��������                                                     <----|\n" );
	printf ( "	|----> 4: ���յ����                                                     <----|\n" );
	printf ( "	|----> 5: �����ʱ�����                                                 <----|\n" );
	printf ( "	|----> 6: ��Ʊ�۲���                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = rapidInput(1, 6);
	return choice;
}


int sortDataGui()
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	  ***************��ӭ��������ɻ�Ʊ���ݽ���*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );
	printf ( "	|----> 1: �����չ�˾����                                                 <----|\n" );
	printf ( "	|----> 2: ���������                                                     <----|\n" );
	printf ( "	|----> 3: ���յ�����                                                     <----|\n" );	
	printf ( "	|----> 4: �����ʱ������                                                 <----|\n" );
	printf ( "	|----> 5: ��Ʊ������                                                     <----|\n" );	
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = rapidInput(1, 5);
	return choice;
}


int userGui()
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf ( "            	     ***************��ӭ�����û���������*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );
	printf ( "	|----> 1: ��Ʊ                                                           <----|\n" );
	printf ( "	|----> 2: ��Ʊ                                                           <----|\n" );
	printf ( "	|----> 3�������û��˵�                                                   <----|\n" );
    printf ( "	|----> 4���˳�����                                                       <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = rapidInput(1, 4);
	return choice;	
}


void userRes()
{
	int choice = userGui();
	printf("\n\t----> 		�����ڽ���		<----|\n");
    switch (choice)
    {
        case 1:
            book();
            break;
        case 2:
            cancel();
            break;
        case 3:
            printf("\n\t����3�����ת���û��˵�����......");
            Sleep(3000);
            system("cls");
			userMenuRes();
            break;
        case 4:
            printf("\n\t�����������л����ʹ��лл��\n");
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
	printf ( "	|---->                       ��ѡ��������Ҫ������������޸�              <----|\n" );
	printf ( "	|----> 1: ���չ�˾                                                       <----|\n" );
	printf ( "	|----> 2: �����                                                         <----|\n" );
	printf ( "	|----> 3�����                                                           <----|\n" );
    printf ( "	|----> 4���յ�                                                           <----|\n" );
	printf ( "	|----> 5: ���ʱ��                                                       <----|\n" );
	printf ( "	|----> 6: ����ʱ��                                                       <----|\n" );	
	printf ( "	|----> 7: ����ʱ��                                                       <----|\n" );
    printf ( "	|----> 8��Ʊ��                                                           <----|\n" );
	printf ( "	|----> 9: ��λ����                                                       <----|\n" );
	printf ( "	|----> 10: �Ѷ���λ��                                                    <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = rapidInput(1, 10);
	return choice;		
}


void settingGui(char *adminName, char *password, char *confirmPassword)
{
    printf("\n\t����������û��������ܳ�20λ,�����пո񣩣� ");
    scanf("%s", adminName);
    printf("\t������������루���ܳ�20λ,�����пո�: ");
    scanf("%s", password);
    printf("\t��ȷ��������루���ܳ�20λ,�����пո�: ");
    scanf("%s", confirmPassword);
    while(strcmp(password, confirmPassword) != 0) // �ж������ַ����Ƿ����
    {
        printf("\t���벻��ȷ������������������루���ܳ�20λ,�����пո�: ");
        scanf("%s", password);
        printf("\t��ȷ��������루���ܳ�20λ,�����пո�: ");
        scanf("%s", confirmPassword);
    }
	return ;
}


void entryGui(char *inputName, char *inputPassWord)
{
    printf("\n\t����������û��������ܳ�20λ,�����пո񣩣� ");
    scanf("%s", inputName);
    printf("\t������������루���ܳ�20λ,�����пո�: ");
    scanf("%s", inputPassWord);
	return ;
}


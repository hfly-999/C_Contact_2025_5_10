#include"contact.h"


void menu()
{
	printf("**********************************************************\n");
	printf("***********      1.add            2.del      *************\n");
	printf("***********      3.search         4.modify   *************\n");
	printf("***********      5.show           6.sort     *************\n");
	printf("***********              0.exit              *************\n");
	printf("**********************************************************\n");
}

int main()
{
	Contact con;
	ReadContact(&con);
	//初始化通讯录
	
	
	int pos=0;
	int input = 0;
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);

		switch (input)
		{
		case EXIT:
			ExitContact(&con);
			break;
		case ADD://增
			AddContact(&con);
			break;
		case DEL://删
			DelContact(&con);
			break;
		case FIND://查
			FindContact(&con);
			break;
		case MODIFY://改
			ModifyContact(&con);
			break;
		case SHOW://打印
			DisplayContact(&con);
			break;	
		case SORT:break;
		default:
			printf("选择错误，请重新选择!!!\n");
			input = 1;
			break;
		}
	} while (input);
	DestroyContact(&con);
	return 0;
}
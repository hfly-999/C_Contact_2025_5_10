#include"contact.h"


//-------------------------------------------------------------------------------------------//
void InitContact(Contact* con)
{
	con->pos = 0;
	con->Data = (PeopleInfo*)malloc(CAPACITY_SIZE * sizeof(PeopleInfo));
	con->rate = 1;
	if (con->Data == NULL)return;
	con->capacity = CAPACITY_SIZE;//容量=默认容量
}
void DelContact(Contact* con)
{
	printf("请输入你要删除的元素的位置:\n");
	int del = 0;
	cin >> del;
	if (del > con->pos || del < 1)
	{
		printf("删除位置错误,请重新操作\n");
	}
	else
	{
		for (del--; del < con->pos; del++)
		{
			*(con->Data + del) = *(con->Data + del + 1);
		}
		con->pos--;
		if (con->capacity < ((con->rate-1) * CAPACITY_SIZE))//判断是否需要缩减部分空间
		{
			PeopleInfo* ptr = (PeopleInfo*)realloc(con->Data,sizeof(PeopleInfo)*(con->capacity-CAPACITY_SIZE));
			if (ptr != NULL)//重新分配成功
			{
				con->Data = ptr;
				con->capacity -= CAPACITY_SIZE;
			}
		}
		cout << "删除成功\n";
	}
	
}
void DisplayContact(const Contact* con)
{
	for (int j = 0; j < 88; j++)cout << "-";
	cout << endl;
	printf("|  |%-10s |%-8s |%-10s |%-15s |%-32s|\n","姓名","性别","年龄","电话号码","家庭住址");
	cout << '|';
	for (int j = 0; j < 86; j++)cout << "-";
	cout << '|' << endl;
	for (int i = 0; i < con->pos; i++)
	{
		printf("|%d |%-10s |%-8s |%-10s |%-15s |%-32s|\n",
			i+1,
			(con->Data + i)->name,
			(con->Data + i)->sex,
			(con->Data + i)->age,
			(con->Data + i)->phonenumber,
			(con->Data + i)->address);
		if (i != con->pos - 1)
		{
			cout << '|';
			for (int j = 0; j < 86; j++)cout << "-";
			cout << '|' << endl;
		}
	}
	
	for (int j = 0; j < 88; j++)cout << "-";
	cout <<endl<<"打印完成!!\n";
}
void AddContact(Contact* con)
{
	//-------------------------------------------------------------------------------------------------//
	//判断模块
	if (con->pos == con->capacity)//如果容量满了
	{
		con->rate++;//内存申请的倍率
		PeopleInfo* ptr = (PeopleInfo*)realloc(con->Data, con->rate * CAPACITY_SIZE * sizeof(PeopleInfo));//重新开辟
		if (ptr == NULL)//开辟失败
		{
			printf("内存空间已满,添加失败!!\n");
			return;
		}
		else
		{
			con->Data = ptr;//让data指针指向可能是新空间的地址
			printf("程序在空间中申请了新的内存\n");
		}
		con->capacity += CAPACITY_SIZE;//容量++
	}
	
	//-------------------------------------------------------------------------------------------------//
	//添加模块
		printf("请输入名字:\n");
		scanf("%s", (con->Data + con->pos)->name);
		printf("请输入年龄:\n");
		scanf("%s", (con->Data + con->pos)->age);
		printf("请输入电话号码:\n");
		scanf("%s", (con->Data + con->pos)->phonenumber);
		printf("请输入性别:\n");
		scanf("%s", (con->Data + con->pos)->sex);
		printf("请输入家庭住址:\n");
		scanf("%s", (con->Data + con->pos)->address);
		con->pos++;
		printf("添加成功!!\n");
	//-------------------------------------------------------------------------------------------------//
}



void FindContact(const Contact* con)
{
	cout << "请输入你要查找的人的名字";
	char name[MAX_NAME];
	cin >> name;
	int i = 0;
	for (i; i < con->pos; i++)
	{
		if (0 == strcmp((const char*)(con->Data+i), name))
		{
			cout << "找到了,这个人的信息如下:\n";
			printf("%-10s %-8s %-10s %-15s %-35s\n",
				(con->Data + i)->name,
				(con->Data + i)->sex,
				(con->Data + i)->age,
				(con->Data + i)->phonenumber,
				(con->Data + i)->address);
			break;
		}
	}
	if (i == con->pos)cout << "没有找到!!" << endl;

}
void ModifyContact(Contact* con)
{
	cout << "请输入你要修改的人的名字";
	char name[MAX_NAME];
	cin >> name;
	int i = 0;
	for (i; i < con->pos; i++)
	{
		if (0 == strcmp((const char*)(con->Data + i), name))
		{
			printf("请输入新名字:\n");
			scanf("%s", (con->Data + i)->name);
			printf("请输入新年龄:\n");
			scanf("%s", (con->Data + i)->age);
			printf("请输入新电话号码:\n");
			scanf("%s", (con->Data + i)->phonenumber);
			printf("请输入新性别:\n");
			scanf("%s", (con->Data + i)->sex);
			printf("请输入新家庭住址:\n");
			scanf("%s", (con->Data + i)->address);
			printf("修改成功!!\n");
			break;
		}
	}
	if (i == con->pos)cout << "查无此人!!" << endl;

}
void DestroyContact(Contact* con)
{
	printf("用户结束进程,正在销毁通讯录\n");
	Sleep(250);
	cout << ".";
	Sleep(250);
	cout << ".";
	Sleep(250);
	cout << ".";
	Sleep(250);
	con->pos = 0;
	con->capacity = 0;
	free(con->Data);
	con->Data = NULL;
	cout << "通讯录销毁完毕!!" << endl;
}

//-------------------------------------------------------------------------------------------//
void ReadContact(Contact* con)
{
	FILE* fp = fopen("contact.txt", "rb");
	FILE* ffp = fopen("data.txt", "rb");
	if (fp == NULL)
	{
		InitContact(con);
		return;
	}
	fread(con, sizeof(Contact), 1, fp);
	con->Data = (PeopleInfo*)malloc(con->capacity * sizeof(PeopleInfo));
	fread(con->Data, sizeof(PeopleInfo), con->capacity, ffp);
	fclose(fp);
	fclose(ffp);
	fp = NULL;
	ffp = NULL;

}

void ExitContact(Contact *con)
{
	printf("正在保存通讯录......");
	FILE* fp = fopen("contact.txt", "wb");
	FILE* ffp = fopen("data.txt", "wb");
	fwrite(con, sizeof(Contact), 1, fp);//存储通信录的信息
	fwrite(con->Data, sizeof(PeopleInfo), con->capacity, ffp);//存储每个人的信息
	fclose(fp);
	fclose(ffp);
	fp = NULL;
	ffp = NULL;
	printf("退出通讯录@exit\n");
}
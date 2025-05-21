#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define MAX 128//通讯录最大人数
#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_PHONE_NUMBER 15
#define MAX_ADDRESS 20
#define MAX_AGE 4
#define CAPACITY_SIZE 2
enum option
{
	EXIT,
	ADD,
	DEL,
	FIND,
	MODIFY,
	SHOW,
	SORT,
};

struct PeopleInfo
{
	char name[MAX_NAME];
	char phonenumber[MAX_PHONE_NUMBER];
	char age[MAX_AGE];
	char sex[MAX_SEX];
	char address[MAX_ADDRESS];
};

struct Contact
{
	int pos;//记录元素个数
	PeopleInfo *Data;
	int capacity;//当前通讯录的最大容量
};



//-------------------------------------------------------------------------------------------------//
//初始化
void InitContact(Contact* con);
//增加
void AddContact(Contact* con);
//删除
void DelContact(Contact* con);
//查找
void FindContact(const Contact* con);
//打印
void DisplayContact(const Contact* con);
//改变
void ModifyContact(Contact* con);
//销毁
void DestroyContact(Contact* con);
//-------------------------------------------------------------------------------------------------//
//从文件当中读取通讯录
void ReadContact(Contact* con);
//把通讯录保存到文件中
void ExitContact(Contact *con);
#pragma once
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <malloc.h>
#include <math.h>
using namespace std;
bool identity = 0;//0Ϊ�˿ͣ�1Ϊ����Ա
typedef struct {
	string name;
	int flow;
	int mid;
}station;

typedef struct {
	station metro[200];
	int length;
}SqList;

void CreateList(SqList* L, station metro[]) {
	L->metro[0].name = "֣�ݻ�վ";
	L->metro[0].flow = rand()/20;
	L->metro[0].mid = 1;

	L->metro[1].name = "���߹㳡";
	L->metro[1].flow = rand()/20;
	L->metro[1].mid = 2;

	L->metro[2].name = "����·";
	L->metro[2].flow = rand()/20;
	L->metro[2].mid = 3;

	L->metro[3].name = "�Ͼ�ɽ";
	L->metro[3].flow = rand()/20;
	L->metro[3].mid = 4;

	L->metro[4].name = "��ׯ";
	L->metro[4].flow = rand()/20;
	L->metro[4].mid = 5;
	//L->length = sizeof(&L);
	L->length = 5;
}
void fresh(SqList* L)
{
	for (int i = 1; i <= L->length; i++)
	{
		L->metro[i-1].mid = i;
	}
}
int Print(SqList* L,int i) {
	cout << "����վID:" << L->metro[i - 1].mid << endl;
	cout << "����վ��:" << L->metro[i - 1].name << endl;
	switch (identity) {
	case 1:
		cout << "����վ������:" << L->metro[i - 1].flow << endl;
	}
	cout << "\n" << endl;
	return 0;
}

int Printall(SqList* L) {
	for (int i = 1; i <= L->length; i++) {
		Print(L, i);
	}
	return 0;
}
int Printlist(SqList* L,unsigned i, unsigned o ) {
	if (i >= o){
		for (i; i>=o+1;i--) {
			cout << L->metro[i - 1].name << "-->";
		}
		cout << L->metro[i - 1].name<<endl;
	}
	else if (i <= o-1) {
		for (i; i <= o-1; i++) {
			cout << L->metro[i - 1].name << "-->";
		}
		cout << L->metro[i - 1].name << endl;
	}
	return 0;
}

int Find(SqList* L, string station)
{
	int i = 1;
	bool find = 0;
	for (i = 1; i <= L->length; i++) {
		if (L->metro[i - 1].name == station) {
			find = 1;
			break;
		}
	}
	switch (find) {
	case 0:
		cout << "δ�ҵ�" << endl;
		return 0;
		break;
	case 1:
		Print(L, i);
		return i;
		break;
	}

}
void search(SqList *L) {
	string name;
	cout << "��������Ҫ���ҵ�վ��" << endl;
	cin >> name;
	Find(L, name);
}

int Price(SqList* L) {
	int in = 0;
	int out = 0;
	int distance = 0;
	string Getin = "0";
	string Getoff = "0";
	cout << "�������ϳ�վվ��" << endl;
	cin >> Getin;
	in = Find(L, Getin);
	cout << "�������³�վվ��" << endl;
	cin >> Getoff;
	out = Find(L, Getoff);
	switch (in && out) {
		case 0:
			cout << "�������󣬷����ϲ�ҳ��" << endl;
			break;
		default:
			distance = abs(out - in);
			if (distance <= 2) {
				cout << "Ʊ��2Ԫ" << endl;
				cout << "·�ߣ�\n" << endl;
				Printlist(L, in,out);
			}
			if (distance > 2)
			{
				cout << "Ʊ��" << (distance+1)/2+1 << "Ԫ"<<endl;
				cout << "·�ߣ�\n" << endl;
				Printlist(L, in, out);
			}
	}
	return 0;
}

int Cost(SqList* L) {
	int in = 0;
	int out = 0;
	int distance = 0;
	string Getin = "0";
	cout << "�������ϳ�վվ��" << endl;
	cin >> Getin;
	in = Find(L, Getin);
	for (out = in+1; out <=L->length; out++) {
		switch (in && out) {
		case 0:
			cout << "�������󣬷����ϲ�ҳ��" << endl;
			break;
		default:
			distance = abs(out - in);
			if (distance <= 2) {
				cout << "·�ߣ�" ;
				Printlist(L, in, out);
				cout << "Ʊ��2Ԫ\n" << endl;
			}
			if (distance > 2)
			{
				cout << "·�ߣ�" ;
				Printlist(L, in, out);
				cout << "Ʊ��" << (distance + 1) / 2 + 1 << "Ԫ\n" << endl;
			}
		}
	}
	for (out = in-1; out>=1; out--) {
		switch (in && out) {
		case 0:
			cout << "�������󣬷����ϲ�ҳ��" << endl;
			break;
		default:
			distance = abs(out - in);
			if (distance <= 2) {
				cout << "·�ߣ�" ;
				Printlist(L, in, out);
				cout << "Ʊ��2Ԫ\n" << endl;
			}
			if (distance > 2)
			{
				cout << "·�ߣ�" ;
				Printlist(L, in, out);
				cout << "Ʊ��" << (distance + 1) / 2 + 1 << "Ԫ\n" << endl;
			}
		}
	}
	return 0;
}

int edit(SqList* L) {
	int sid = 0;
	string oname="0";
	string nname="0";
	string choice="0";
	int nflow = 0;
	cout << "��������Ҫ�޸ĵ�վ��" << endl;
	cin >> oname;
	sid=Find(L, oname);
	if (sid > 0) {
		cout << "��վ����Ϣ����" << endl;
		Print(L, sid);
		cout << "�������µ�վ��" << endl;
		cin >> nname;
		cout << "�������µĿ�����" << endl;
		cin >> nflow;
		cout << "վ����" << L->metro[sid - 1].name << "-->" << nname << endl;
		cout << "������" << L->metro[sid - 1].flow << "-->" << nflow << endl;
		cout << "ȷ��Ҫ������y/n" << endl;
		cin >> choice;
		if (choice == "y") {
			L->metro[sid - 1].name = nname;
			L->metro[sid - 1].flow = nflow;
			cout << "�޸��ѱ���"<<endl;
		}
		if (choice == "n") {
			cout << "�޸�δ����" << endl;
		}
		}
	return 0;
	}

int adds(SqList* L){
	string name="0";
	string choice = "0";
	int sid=0;
	int flow = 0;
	cout << "��������Ҫ������վ���վ����" << endl;
	cin >> name;
	cout << "��������Ҫ������վ��ID" << endl;
	cin >> sid;
	cout << "��������Ҫ������վ��Ŀ�����" << endl;
	cin >> flow;
	cout << "��Ҫ������վ����Ϣ����" << endl;
	cout << "վ������" << name << "\nվ��ID��" << sid << "\nվ���������"<< flow << endl;
	cout << "��ȷ��Ҫ�������վ����y/n" << endl;
	cin >> choice;
	if (choice == "y") {
		for (int i = L->length; i >= sid; i--) {
			L->metro[i] = L->metro[i - 1];
		}
		L->metro[sid - 1].name = name;
		L->metro[sid - 1].flow = flow;
		L->metro[sid - 1].mid = sid;
		L->length = L->length + 1;
		fresh(L);
		cout << "������վ��" << endl;
	}
	else if (choice == "n") {
		cout << "��ѡ���������վ��" << endl;
	}

	return 0;
}

int remove(SqList* L) {
	string name="0";
	string choice = "0";
	int sid = 0;
	cout << "��������Ҫɾ����վ����" << endl;
	cin >> name;
	sid=Find(L, name);
	cout << "���Ƿ�Ҫɾ�����վ�㣿y/n" << endl;
	cin >> choice;
	if (choice == "y") {
		for (int i = sid; i < L->length; i++) {
			L->metro[i-1] = L->metro[i];
		}
		L->length = L->length - 1;
		fresh(L);
		cout << "��ɾ��վ��" << endl;
	}
	else if (choice == "n") {
		cout << "��ѡ��ɾ�����վ��" << endl;
	}

	return 0;
}

int ShellSort(SqList Li, int n) {
	int i, j, d;
	station tmp;
	d = n / 2;
	while (d > 0)
	{
		for (i = d; i < n; i++)
		{
			tmp = Li.metro[i];
			j = i - d;
			while (j >= 0 && tmp.flow < Li.metro[j].flow)
			{
				Li.metro[j + d] = Li.metro[j];
				j = j - d;
			}
			Li.metro[j + d] = tmp;
		}
		d = d / 2;
	}
	Printall(&Li);
	return 0;
}

int partition(SqList* Li,int s,int t) {
	int i = s, j = t;
	station tmp = Li->metro[i];
	while (i < j)
	{
		while (j > i && Li->metro[i].flow >= tmp.flow)
		{
			j--;
		}
		Li->metro[i] = Li->metro[j];
		while (i < j && Li->metro[i].flow <= tmp.flow)
		{
			i++;
		}
		Li->metro[j] = Li->metro[i];
	}
	Li->metro[i] = tmp;
	//cout << "######���ǵ�" << i << "�˻���" << endl;
	return i;
}

int FastSort(SqList* Li,int s,int t) {
	int i;
	if (s < t)
	{
		i = partition(Li, s, t);
		FastSort(Li,s,i-1);
		FastSort(Li,i+1,t);
	}
	//cout << "���" << endl;
	return 0;
}

int FSprint(SqList L){
	FastSort(&L, 1, L.length);
	Printall(&L);
	return 0;
}


 void Merge(SqList* Li,int low,int mid,int high) {
	SqList* Li1=NULL;
	SqList Lt = *Li;
	Li1 = &Lt;
	int i = low, j = mid + 1, k = 0;
	Li1 = (SqList*)malloc((high - low + 1) * sizeof(SqList));
	while (i <= mid && j <= high) {
		if (Li->metro[i].flow <= Li->metro[j].flow)
		{
			Li1->metro[k] = Li->metro[i];
			i++;
			k++;
		}
		else
		{
			Li1->metro[k] = Li->metro[j];
			j++;
			k++;
		}
	}
	while (i <= mid) {
		Li1->metro[k] = Li->metro[i];
		i++; 
		k++;
	}
	while (j <= high) {
		Li1->metro[k] = Li->metro[j];
		j++;
		k++;
	}
	for (k = 0, i = low; i <= high; k++, j++)
	{
		Li->metro[i] = Li1->metro[k];
	}
	free(Li1);
}
void MergePass(SqList* Li, int length, int n)
{
	int i = 0;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)
		Merge(Li, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n - 1)
		Merge(Li, i, i + length - 1, n - 1);
}
void Mergesort(SqList Li,int n) {
	int length=0;
	for (length = 1; length < n; length = 2 * length)
		MergePass(&Li, length, n);
	Printall(&Li);
}

void bubble(SqList L) {
	bool flag = 1;
	station swap;
	for (int i = 0; i < L.length-1; i++) {
		for (int j = L.length-1; j > i; j--) {
			flag = 0;
			if (L.metro[j].flow < L.metro[j - 1].flow) {
				swap = L.metro[j];
				L.metro[j] = L.metro[j - 1];
				L.metro[j - 1] = swap;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
	Printall(&L);
}

void BISort(SqList L,int n) {
	int i = 0; 
	int j = 0; 
	int low = 0;
	int high = 0;
	int mid = 0;
	station tmp;
	for (i = 1; i < n; i++) {
		if (L.metro[i].flow < L.metro[i - 1].flow) {
			tmp = L.metro[i];
			low = 0;
			high = i - 1;
			while (low <= high) {
				mid = (low + high) / 2;
				if (tmp.flow < L.metro[mid].flow) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			for (j = i - 1; j >= high + 1; j--) {
				L.metro[j + 1] = L.metro[j];
			}
			L.metro[high + 1] = tmp;
		}
		
	}
	Printall(&L);
}
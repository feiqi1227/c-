#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MAX 100//��Ʒ�������Ϊ100
struct goods
{
	int n;//��Ʒ���
	int w;//��Ʒ����
	int v;//��Ʒ��ֵ
	double p;//��Ʒ�Լ۱�
	double c;//��¼װ����Ʒ�ı����������Ʒ��ȫ���뱳������choice=1��������,choice=0��
}g[MAX];

void Init(int n, struct goods*ps);//��ʼ����Ʒ��Ϣ
bool cmp(struct goods *a,struct goods *b);//�Ƚ�
void CompletePack(int _bagW,int n, goods*ps);


void Init(int n, struct goods*ps)//��ʼ����Ʒ��Ϣ
{
	cout << "������������Ʒ�������ͼ�ֵ��" << endl;
	for (int i = 0; i < n; i++)
	{
		ps[i].n = i;//��Ʒ���
		cin >>ps[i].w >> ps[i].v;//��ʼ����Ʒ�����ͼ�ֵ
		ps[i].p = (double)ps[i].v / (double)ps[i].w;//�Լ۱�
		ps[i].c = 0;//��û�з��뱳��
	}
}

bool cmp(struct goods *a,struct goods *b)//�Ƚ�
{
	return a->p > b->p;
}
void CompletePack(int _bagW,int n,struct goods*ps)
{
	double sum = 0;//�����ܼ�ֵ
	for (int i = 0;i<n; i++)
	{
		if (_bagW >ps[i].w)//��������������Ʒ����
		{
			ps[i].c = 1;
			sum =sum+ ps[i].v;
			_bagW = _bagW - ps[i].w;//ʣ�౳������
		}
		else//��������С����Ʒ����
		{
			ps[i].c = (double)_bagW / (double)ps[i].w;//װ����Ʒ�ı���
			sum =sum+ps[i].c *ps[i].v;
			break;
		}
	}
	cout << "��������ֵ��" << sum << endl;
}
void print(int n, struct goods* ps)
{
	for (int i = 0; i < n; i++)
	{
		if (ps[i].p != 0)
		{
			if (ps[i].p == 1)
				cout << "��Ʒ" << ps[i].n << setw(20) << "��ֵΪ��" << ps[i].v << endl;
			else
				cout << "��Ʒ" << ps[i].n << "װ����" << ps[i].p <<setw(8)<< "   ��ֵΪ��" << ps[i].v << endl;
		}
	}
}

int main()
{
	int bagW, n;//���������������Ʒ����
	cout << "������������Ʒ��������Ʒ������" << endl;
	cin >> bagW >> n;
	Init(n,g);
	cout << endl ;
	sort(g, g + n, cmp);
	CompletePack(bagW,n, g);
	return 0;

}


//4 3
//2 8
//9 18
//5 6
//5 8
//8 20
//5 5
//4 6
//5 7
//5 15

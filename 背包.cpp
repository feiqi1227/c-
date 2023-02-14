#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MAX 100//物品数量最多为100
struct goods
{
	int n;//物品编号
	int w;//物品重量
	int v;//物品价值
	double p;//物品性价比
	double c;//记录装入物品的比例（如果物品完全放入背包，则choice=1；不放入,choice=0）
}g[MAX];

void Init(int n, struct goods*ps);//初始化物品信息
bool cmp(struct goods *a,struct goods *b);//比较
void CompletePack(int _bagW,int n, goods*ps);


void Init(int n, struct goods*ps)//初始化物品信息
{
	cout << "请依次输入物品的重量和价值：" << endl;
	for (int i = 0; i < n; i++)
	{
		ps[i].n = i;//物品编号
		cin >>ps[i].w >> ps[i].v;//初始化物品重量和价值
		ps[i].p = (double)ps[i].v / (double)ps[i].w;//性价比
		ps[i].c = 0;//都没有放入背包
	}
}

bool cmp(struct goods *a,struct goods *b)//比较
{
	return a->p > b->p;
}
void CompletePack(int _bagW,int n,struct goods*ps)
{
	double sum = 0;//背包总价值
	for (int i = 0;i<n; i++)
	{
		if (_bagW >ps[i].w)//背包容量大于物品重量
		{
			ps[i].c = 1;
			sum =sum+ ps[i].v;
			_bagW = _bagW - ps[i].w;//剩余背包容量
		}
		else//背包容量小于物品重量
		{
			ps[i].c = (double)_bagW / (double)ps[i].w;//装入物品的比例
			sum =sum+ps[i].c *ps[i].v;
			break;
		}
	}
	cout << "背包最大价值：" << sum << endl;
}
void print(int n, struct goods* ps)
{
	for (int i = 0; i < n; i++)
	{
		if (ps[i].p != 0)
		{
			if (ps[i].p == 1)
				cout << "物品" << ps[i].n << setw(20) << "价值为：" << ps[i].v << endl;
			else
				cout << "物品" << ps[i].n << "装入了" << ps[i].p <<setw(8)<< "   价值为：" << ps[i].v << endl;
		}
	}
}

int main()
{
	int bagW, n;//背包最大容量和物品数量
	cout << "请依次输入物品重量和物品数量：" << endl;
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

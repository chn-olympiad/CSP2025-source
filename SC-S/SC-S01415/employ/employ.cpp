#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int Mod = 998244353; 
struct STU{
	char s;
	int naixin;
	int vis;
}a[N];
bool cmp(STU x,STU y)
{
	return x.naixin < y.naixin;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

int n,m;
int ans = 0;
void xl(int start,int k,int huan,int gong)//从start开始的序列，还有m个人 ,已经淘汰了k个人 
{
	if(gong == 1) //已经没有人了 
	{
		if(huan == m) ans++; 
		if(huan == m - 1 && (a[start].s == '1' && a[start].naixin > k)) ans++;
		a[start].vis = 0; 
//		cout << "已从 " << start<<" 处回溯" << endl;
		return;
	}
	a[start].vis = 1;
	if(a[start].s == '1' && a[start].naixin > k) k++,huan++;
//	cout << start << " " << k << ' ' << m << " " << n2 << endl;
//	if(huan == n) ans++;
	for(int i = 1;i <= n;i++)
	{
		if(a[i].vis == 0) 
		{
//			cout << "现在为："<<start<<"  下一个选择：" << i << endl << endl << endl;
			xl(i,k,m,gong - 1);
		}
	}
	a[start].vis = 0;	 
	if(gong == 1) //已经没有人了 
	{
		if(huan == m) ans++; 
		a[start].vis = 0; 
//		cout << "已从 " << start<<" 处回溯" << endl;
		return;
	}
	return;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i].s;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].naixin;
	}
	//当一个人的耐心 <= 0时或者s[i] = 0时不会被录用 
	//n个人，枚举每一种排列 
	sort(a + 1,a + n + 1,cmp);
	int maxn = 0;
	for(int i = 1;i <= n;i++)//枚举开始的序列 
	{
		ans = 0;
		for(int j = 1;j <= n;j++) a[j].vis = 0;
		xl(i,0,0,n);
		maxn = max(maxn,ans % Mod); 
	}
	cout << maxn % Mod << endl;
	return 0;
}

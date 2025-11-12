//我去电脑20分钟蓝屏一次，心态炸了呀 
#include <bits/stdc++.h>
using namespace std;
long long t,n,f[100005],maxn;//i为总人数,f[i]为总数 
struct p
{
	long long a,b,c;
} a[100005];
bool cmp1(p x, p y)
{
	return x.a>y.a;
}
bool cmp2(p x, p y)
{
	return x.b>y.b;
}
bool cmp3(p x, p y)
{
	return x.c>y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i<=t;i++)
	{
		cin >> n;
		memset(f,0,sizeof(f));
		maxn = -1;
		for(int j = 1;j<=n;j++)
		{
			cin >> a[j].a >> a[j].b >> a[j].c;
		}
		
		sort(a+1,a+n+1,cmp1);
		/*检测排序 
		for(int j = 1;j<=n;j++) 
		{
			cout << "a[" << j << "][0]:" << a[j].a << " ";
			cout << "a[" << j << "][1]:" << a[j].b << " ";
			cout << "a[" << j << "][2]:" << a[j].c << endl;
		}
		cout << endl;
		//*/
		for(int j = 1;j<=n/2;j++)
			f[n/2] += max(max(a[j].a,a[j].b),a[j].c);
		for(int j = n/2+1;j<=n;j++)
		{
			//01背包 
			f[j] = max(f[j], f[j-1] + max(a[j].b,a[j].c));
		}
		if(maxn < f[n]) maxn = f[n];
		//for(int j = 1;j<=n;j++) cout << "f[" << j << "]:" << f[j] << endl;
		
		sort(a+1,a+n+1,cmp2);
		/*检测排序 
		for(int j = 1;j<=n;j++) 
		{
			cout << "a[" << j << "][0]:" << a[j].a << " ";
			cout << "a[" << j << "][1]:" << a[j].b << " ";
			cout << "a[" << j << "][2]:" << a[j].c << endl;
		}
		cout << endl;
		//*/
		memset(f,0,sizeof(f));
		for(int j = 1;j<=n/2;j++)
			f[n/2] += max(max(a[j].a,a[j].b),a[j].c);
		for(int j = n/2+1;j<=n;j++)
		{
			//01背包 
			f[j] = max(f[j], f[j-1] + max(a[j].a,a[j].c));
		}
		if(maxn < f[n]) maxn = f[n];
		//for(int j = 1;j<=n;j++) cout << "f[" << j << "]:" << f[j] << endl;
		
		sort(a+1,a+n+1,cmp3);
		/*检测排序 
		for(int j = 1;j<=n;j++) 
		{
			cout << "a[" << j << "][0]:" << a[j].a << " ";
			cout << "a[" << j << "][1]:" << a[j].b << " ";
			cout << "a[" << j << "][2]:" << a[j].c << endl;
		}
		cout << endl;
		//*/
		memset(f,0,sizeof(f));
		for(int j = 1;j<=n/2;j++)
			f[n/2] += max(max(a[j].a,a[j].b),a[j].c);
		for(int j = n/2+1;j<=n;j++)
		{
			//01背包 
			f[j] = max(f[j], f[j-1] + max(a[j].b,a[j].a));
		}
		if(maxn < f[n]) maxn = f[n];
		//for(int j = 1;j<=n;j++) cout << "f[" << j << "]:" << f[j] << endl;
		
		cout << maxn << endl;
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#define ll long long
using namespace std;
int re();
void wr(int x);
const ll mo=998244353;
int n,m;
int z[510];
int a[510];
int q[510];
int vis[510];
ll ans=0;
void check()
{
	int tem=0,tem2=0;
	for(int i=1;i<=n;i++)
	{
		if(z[i] && q[a[i]]>tem)
		{
			tem2++;
		}
		else
		{
			tem++;
		}
	}
	if(tem2>=m){
		ans++;
		ans%=mo;
	}
	return ;
}
void ddfs(int x)
{
	if(x==n)
	{
		check();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[x+1]=i;
			ddfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=re(),m=re();
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		z[i]=s[i-1]-'0';
		q[i]=re();
	}
	ddfs(0);
	wr(ans);
	putchar('\n');
	return 0;
}
int re()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void wr(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		wr(x/10);
	}
	putchar(x%10+'0');
}


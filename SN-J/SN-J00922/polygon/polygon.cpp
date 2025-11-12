//SN-J00922
#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],sum,maxa,mo=998244353;
long long num[5100][5100];
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int now,long long maxn,long long suma,long long xv)//选或不选 
{
	if(now>n+1) return;
	if(xv>=3 && suma>2*maxn) 
	{
		sum++;
	//cout<<maxn<<" "<<suma<<'\n';
		sum%=mo;
	}
	dfs(now+1,max(maxn,a[now]),suma+a[now],xv+1);//xuan
	dfs(now+1,maxn,suma,xv);//bu
}
void dfs1(int now,int s)
{
	if(now>n) return;
	if(s>=3) sum++;
	for(int i=1;i+now<=n;i++)
	{
		dfs1(i+now,s+1);
		dfs1(i+now,s);
	}
//	dfs1(now+1,s+1);
//	dfs1(now+1,s);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if(n==3)//tp1
	{
		if(maxa*2<a[1]+a[2]+a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxa==1)//tp3
	{
		dfs1(1,0);
		cout<<sum;
		return 0;
	}
	if(n<=20 && n>3)//tp2
	{
		dfs(1,0,0,0);
		cout<<sum;
		return 0;
	}
	return 0;
}


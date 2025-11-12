#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100010],as;
struct A
{
	int a,b,c;
}e[100010];
void dfs(int x,int s,int num1,int num2,int num3)
{
//	cout<<x<<' '<<s<<' '<<num1<<' '<<num2<<' '<<num3<<'\n';
	if(x==n+1)
	{
		as=max(as,s);
		return ;
	}
	if(num1<n/2)
		dfs(x+1,s+e[x].a,num1+1,num2,num3);
	if(num2<n/2)
		dfs(x+1,s+e[x].b,num1,num2+1,num3);
	if(num3<n/2)
		dfs(x+1,s+e[x].c,num1,num2,num3+1);
}
bool cmp(A x,A y)
{
	return x.a-x.b < y.a-y.b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int fl=1,f=1;
		for(int i=1;i<=n;i++)
		{
			cin>>e[i].a>>e[i].b>>e[i].c;
			if(e[i].c!=0||e[i].b!=0)
				fl=0;
			if(e[i].c!=0)
				f=0;
		}
		if(fl)
		{
			as=0;
			for(int i=1;i<=n;i++)
				a1[i]=e[i].a;
			sort(a1+1,a1+n+1);
			for(int i=n/2+1;i<=n;i++)
				as+=a1[i];
			cout<<as<<'\n';
			continue;
		}
		if(f)
		{
			as=0;
			sort(e+1,e+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				as+=e[i].b;
			for(int i=n/2+1;i<=n;i++)
				as+=e[i].a;
			cout<<as<<'\n';
			continue;
		}
		as=INT_MIN;
		dfs(1,0,0,0,0);
		cout<<as<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
6
7 6 0
4 7 0
8 5 0
8 6 0
4 2 0
7 8 0
*/
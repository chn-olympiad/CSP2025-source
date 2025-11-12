#include<bits/stdc++.h>
using namespace std;
int n,a[5050],sum;
/*
int bfs(int x,int y,int m)
{
	int summ=m;
	for(int i=1;i<=x;i++)
	{
		summ+=bfs(i-1,x-1,summ);
	}
}
int check(int x,int y,int m)//从0~y-1个数字，挑x-1个数且小于2max 
{
	int summ=0;
	for(int i=x-1;i<=y-1;i++)
	{
		summ+=bfs(i-1,x-1,a[i]);
	}
	if(summ==0)return -10;
	else sum+=summ;
}
* */
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int maxx=-10;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(maxx<a[i])maxx=a[i];
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>maxx*2)cout<<1<<endl;
		else cout<<0;
	}
	else cout<<1;
//	else cout<<000;
	/*
	else
	{
		for(int i=1;i<=n;i++)//i是边数 
		{
			for(int j=n;j>=n;j--)//j代表最大值 
			{
				int maxx=check(i,j,a[j]);
				if(maxx==-10)break;
			}
		}
		cout<<sum;
	}
	*/
	//see you,my OI life 
	return 0;
}


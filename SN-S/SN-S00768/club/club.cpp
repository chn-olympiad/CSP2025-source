#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],ap,bp,cp,ans[100005];
int n,o,sum;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int x)
{
	if(x==n+1)
	{
		o++;
		ans[o]=sum;
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)
		{
			ap++;
			if(ap>n/2)
			{
				ap--;
				continue;
			}
			sum+=a[x];
			dfs(x+1);
			sum-=a[x];
			ap--;
		}
		if(i==2)
		{
			bp++;
			if(bp>n/2)
			{
				bp--;
				continue;
			}
			sum+=b[x];
			dfs(x+1);
			sum-=b[x];
			bp--;
		}
		if(i==3)
		{
			cp++;
			if(cp>n/2)
			{
				cp--;
				continue;
			}
			sum+=c[x];
			dfs(x+1);
			sum-=c[x];
			cp--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n>200)
		{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i];
			}
			cout<<sum;
			continue;
		}
		dfs(1);
		int m=0;
		for(int i=1;i<=o;i++)
		{
			m=max(m,ans[i]);
		}
		cout<<m<<endl;
		for(int i=1;i<=o;i++) ans[i]=0;
	}
	return 0;
}

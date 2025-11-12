#include<bits/stdc++.h>
using namespace std;
long long n,k,lp,ans;
int a[500005];
int p[500005][2];
bool yy[500005];
bool check(int x,int y)
{
	int num=a[x];
	for(int i=x+1;i<=y;i++)
	{
		num^=a[i];
	}
	if(num==k)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void dfs(long long q,long long last,long long lasti)
{
	ans=max(ans,q);
	for(int i=lasti+1;i<=lp;i++)
	{
		if(p[i][0]>last && yy[i]==false)
		{
			yy[i]=true;
			dfs(q+1,p[i][1],i);
			yy[i]=false;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool p1=true,p2=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			p1=false;
		}
		if(a[i]>1)
		{
			p2=false;
		}
	}
	if(p1==true && k==0)
	{
		if(n%2==0)
		{
			cout<<n/2;
		}
		else
		{
			cout<<(n-1)/2;
		}
		return 0;
	}
	else if(p2==true && k==1)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(p2==true && k==0)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
			else if(a[i]==1 && a[i+1]==1)
			{
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(check(i,j)==true)
				{
					p[++lp][0]=i;
					p[lp][1]=j;
				}
			}
		}
		dfs(0,0,0);
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
ll a[10015][5];
int n;
ll ans=0;
int cnt[5];
ll read()
{
	char c=getchar();
	int flag=1;
	ll x=0;
	while(c>'9'||c<'0')
	{
	    if(c=='-')
	    {
	   		flag=-1;
		}	
		c=getchar();
	}		
	while(c>='0'&&c<='9')
	{
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*flag;
} 
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
}
void dfs(int x,int y,ll sum,int cnnt)
{
	if(x>n||y>3||x<=0||y<=0)
		return ;
	if(cnt[y]>=n/2)
		return ;
	if(cnnt==n)
	{
		ans=max(ans,sum+a[x][y]);
		return ;
	}
	cnt[y]++;
	if(cnt[1]<n/2)
		dfs(x+1,1,sum+a[x][y],cnnt+1);
	if(cnt[2]<n/2)
		dfs(x+1,2,sum+a[x][y],cnnt+1);
	if(cnt[3]<n/2)
		dfs(x+1,3,sum+a[x][y],cnnt+1);
	cnt[y]--;
	return ;
}
int aa[10015];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,flag=0;
	T=read();
	
	while(T--)
	{
		n=read();
		flag=0;
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			aa[i]=a[i][1];
			if(a[i][2]!=0||a[i][3]!=0)
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			sort(aa+1,aa+1+n);
			for(int i=n;i>n/2;i--)
			{
				ans+=aa[i];
			}
			write(ans);
			putchar('\n');
			continue;
		}
		dfs(1,1,0,1);
		cnt[1]=cnt[2]=cnt[3]=0;
		dfs(1,2,0,1);
		cnt[1]=cnt[2]=cnt[3]=0;
		dfs(1,3,0,1);
		write(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}





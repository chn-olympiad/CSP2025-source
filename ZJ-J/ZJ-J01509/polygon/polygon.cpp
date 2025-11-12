#include <bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
#define ll long long

int n;
int a[5005];
int vis[505];
int aa[505];
int ans=0;
void dfs(int bian,int x,int y)
{
	if(bian+1==x)
	{
		int tmp[505];
		For(i,1,bian) 
		{
			tmp[i] = aa[i];
		}
		sort(tmp+1,tmp+bian+1);
		int sum=0;
		For(i,1,bian-1)
		{
			sum+=tmp[i];
		}
		if(sum>tmp[bian])
		{
			ans++;
		}
	}
	For(i,y,n)
	{
		if(vis[i]==0)
		{
			aa[x]=a[i];
			vis[i]=1;
			dfs(bian,x+1,i+1);
			vis[i]=0;	
		}
	}
}

void p()
{
	ll tot=0;
	For(i,3,n)
	{
		ll ans=1;
		For(j,n-i+1,n)
		{
			ans=ans%998244353;
			ans*=j;
		}
		For(j,1,i)
		{
			ans/=j;
		}
		tot+=ans;
		tot=(tot%998244353);
	}
	cout<<tot<<endl;
}

void z()
{
	ans=0;
	For(i,3,n)
	{
		dfs(i,1,1);
		ans=ans%998244353;
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool pian=true;
	For(i,1,n)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			pian=false;
		}
	}
	if(n<3) 
	{
		cout<<0<<endl;
		return 0;
	}
	if(n==3)
	{
		sort(a+1,a+n+1);
		if(a[1]+a[2]+a[3]>2*a[3])
		{
			cout<<1<<endl;
		}
		else cout<<0<<endl;
		return 0;
	}
	if(pian)
	{
		p();
	}
	else 
	{
		z();
	}
	return 0;
}

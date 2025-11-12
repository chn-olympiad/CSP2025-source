#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e3+10;
int n;
int a[N][3];
void sove1()
{
	int ans=-98765;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(i!=j)
				ans=max(ans,a[1][i]+a[2][j]);
		}
	}
	cout<<ans<<'\n';
}
void soveA()//特殊A 
{
	int b[N];
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i][1];
	}
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	int ans=0;
	for(int i=0;i<=n/2;i++)
	{
		ans+=b[i];
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		int flag2=1;
		int flag3=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0)
			{
				flag2=0;
			}
			if(a[i][3]!=0)
			{
				flag3=0;
			}
		}
		if(n==2)sove1();
		if(flag2==1&&flag3==1)
		{
			soveA();
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				int maxx=-45;
				for(int j=1;j<=3;j++)
				{
					maxx=max(maxx,a[i][j]);
				}
				ans+=maxx;
			}
			cout<<ans<<'\n';
		}
	 } 
	return 0;
 } 
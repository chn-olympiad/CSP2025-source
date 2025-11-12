#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c[505];
int t[505];
int ans;
char s[505];
int cc(int x)
{
	int s=1;
	for(int i=2;i<=x;i++)
	{
		s=s*(i%998244353);
		s=s%998244353;
	}
	return s;
}
void my_employ(int step,int sum,int at)
{
	if((n-sum)<m)
	{
		return ;
	}
	if(step==n+1)
	{
		if(at>=m)
		{
			ans++;
			ans=ans%998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i]==0)
		{
			t[i]=1;
			if(s[step-1]=='0'||c[i]<=sum)
			{
				my_employ(step+1,sum+1,at);
			}
			else
			{
				if((at+1)>=m)
				{
					ans=ans+(cc(n-step)%998244353);
					ans=ans%998244353;
				}
				else
				{
					my_employ(step+1,sum,at+1);
				}
			}
			t[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	my_employ(1,0,0);
	cout<<ans%998244353<<endl;
	return 0;
}

#include<iostream>
using namespace std;
long long n,m,sum=0,out,ans=0;
string test;
long long te[505];
long long pa[505],people[505];
void dfs(long long t)
{
	if(t<=0)
	{
		if(sum>=m)
		{
			ans++;
			ans%=998244353;
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(people[i]==1)continue;
		people[i]=1;
		if(te[i]==1)sum++;
		else
		{
			for(int j=1;j<=n;j++) pa[j]--;
			out=1;
			while(out)
			{
				out=0;
				for(int j=1;j<=n;j++)
				{
					if(pa[j]<=0&&people[j]==0)
					{
						people[j]=1;
						t--;
						out=1;
						for(int k=1;k<=n;k++) pa[k]--;
					}
				}
			}
		}
		t--;
		
		dfs(t);
		
		t++;
		if(te[i]==1)sum--;
		else
		{
			for(int j=1;j<=n;j++) pa[j]++;
			out=1;
			while(out)
			{
				out=0;
				for(int j=1;j<=n;j++)
				{
					if(pa[j]<0&&people[j]==1)
					{
						people[j]=0;
						t++;
						out=1;
						for(int k=1;k<=n;k++) pa[k]++;
					}
				}
			}
		}
		people[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>test;
	for(int i=0;i<test.size();i++)
	{
		te[i+1]=test[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>pa[i];
	}
	dfs(n);
	cout<<ans%998244353<<endl;
	return 0;
}

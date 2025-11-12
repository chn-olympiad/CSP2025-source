#include<iostream>
using namespace std;
int n,m,a[505],he,xuan[505];
string s;
long long f[505],ans;
const long long mod=998244353;
bool bj[505];
void dfs(int x)
{
	if(x==n+1)
	{
		int bu=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(bu>=a[xuan[i]]||s[i-1]=='0')
			{
				bu++;
			}
			else
			{
				sum++;
			}
		}
		if(sum>=m)
		{
		ans++;ans%=mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(bj[i]==1){continue;}
		xuan[x]=i;
		bj[i]=1;
		dfs(x+1);
		bj[i]=0; 
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	he=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0){he--;}
	}
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
	}
	else 
	{
		cout<<0;
	}
	return 0;
}

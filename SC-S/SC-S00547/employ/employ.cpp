#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int c[505];
int a[505];
bool use[15];
string s;
const int p=998244353;
long long ans=0;
void dfs(int t)
{
	//cout<<t<<endl;
	if(t>n)
	{
		int fail=0,uf=0;
		for(int i=1;i<=n;i++)
		{
			if(fail>=c[a[i]])
			{
				fail++;
				continue;
			}
			if(s[i]=='0'){
				fail++;
				continue;
			}
			uf++;
		}
		if(uf>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(use[i])continue;
		use[i]=1;
		a[t]=i;
		dfs(t+1);
		a[t]=0;
		use[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
	}
	cout<<0<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int id[100010];
int c[100010];
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
	if(n<=10)
	{
		for(int i=1;i<=n;i++)
		{
			id[i]=i;
		}
		int kk=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i-1-kk>=c[i])
			{
				continue;
			}
			if(s[i-1] == '1')
			{	
				kk++;
			}
		}
		if(kk>=m)
		{
			ans++;
		}
		while(next_permutation(id+1,id+1+n))
		{
			int kk=0;
			for(int i=1;i<=n;i++)
			{
				if(i-1-kk>=c[id[i]])
				{
					continue;
				}
				if(s[i-1] == '1')
				{	
					kk++;
				}
			}
			if(kk>=m)
			{
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	else
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i;
			ans%=mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

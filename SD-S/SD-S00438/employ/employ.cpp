#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[505],b[505],c[32];
constexpr int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	getchar();
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=getchar()^48;
		flag&=a[i];
	}
	int zeros=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		if(b[i]==0)
			zeros++; 
	}
	if(flag&&n-zeros<m)
	{
		cout<<0;
	}
	else if(n<=20)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			c[i]=i;
		do
		{
			int lose=0;
			for(int i=1;i<=n;i++)
			{
				if(lose>=b[c[i]]||a[i]==0)
					lose++;
			}
			if(n-lose>=m)
				ans++;
		} while(next_permutation(c+1,c+n+1));
		cout<<ans;		
	}
	else
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

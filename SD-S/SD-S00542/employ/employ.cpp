#include<bits/stdc++.h>
using namespace std;

const int mod=998224353;

long long ans=1;

int s[500];

char a[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	int n,m,num=0;
	cin>>n>>m;
	cin>>a+1;
	bool k=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='0')
		{
			k=1;
		}
		cin>>s[i];
		if (s[i]==0)
		{
			num++;
		}
	}
	sort (s+1,s+1+n);
	//特殊性质A(没过) + 测试点15 
	if (!k)
	{
//		cout<<num<<"\n";
//		cout<<n-num<<"\n";
		if (m>n-num)
		{
			cout<<0;
		}
		else
		{
			for (int j=1;j<=(n-num);j++)
			{
				ans=1ll*(ans*j)%mod;
			}
			cout<<ans;
		}
	}
	return 0;
}


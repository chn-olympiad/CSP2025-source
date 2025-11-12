#include <bits/stdc++.h> 
using namespace std;
int n,m,k,f;
string s;
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++)
	{
		a[i]=s[i]-'0';
		if(a[i]==1)
		{
			f++;
		}
	}
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x)
		{
			k++;
		}
	} 
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	else if(f==1)
	{
		cout<<k;
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=k;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	printf("%lld",ans);
	return 0;
}

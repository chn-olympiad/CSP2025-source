#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],ans=1,tot=0,n1;
char c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	n1=n;
	for(long long i=1;i<=n;i++)	cin>>c[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)	n1--;
	}
	if(n1<m)
	{
		cout<<"0"<<endl;
		return 0;
	}
	 if(m==1)
	{
		for(long long i=1;i<=n;i++)
		{
			if(c[i]!='0')tot++;
		}
		for(long long i=1;i<=tot;i++)
		{
			ans*=i;
			ans%=998244353; 
		}
		cout<<ans<<endl;
	}
	else 
	{
		for(long long i=1;i<=n;i++)
		{
			ans*=i;
			ans%=998244353; 
		}
		cout<<ans<<endl;
	}
	return 0;
}

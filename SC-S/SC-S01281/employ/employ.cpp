#include<iostream>
using namespace std;
int n,m;
const long long mod=998244353;
string st;
int c[1000005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;long long ans=1;
	cin>>st;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==1)
	{
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(st[i]=='1')
			{
				flag=1;
			}
		}
		if(flag=0) cout<<"0";
		else {
			
			for(int i=1;i<=n;i++)
			{
				ans=(ans%mod)*i;
			}
			cout<<ans%mod;
			return 0;
		}
	}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(st[i]=='0')
		{
			flag=1;
		}
	}
	if(flag==0){
		for(int i=1;i<=n;i++)
			{
				ans=(ans*i)%mod;
			}
			cout<<ans%mod;
			return 0;
	}
	else cout<<"0";return 0;
}
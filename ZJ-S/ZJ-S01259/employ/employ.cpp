#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s=' '+s;
	int c[n+5];
	for(int i=1;i<=n;i++)cin>>c[i];
	int ans=-1,b=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				if(c[i]<=b)continue;
				else sum++;
			}
			if(sum!=0)
			{
				if(ans==-1)ans=1*sum%mod;
				else ans=ans*sum%mod;		
			}
		}
		else 
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				if(c[i]>b)continue;
				else sum++;
			}
			if(sum!=0)
			{
				if(ans==-1)ans=1*sum%mod;
				else ans=ans*sum%mod;				
			}
			b++;
		}
	}
	cout<<ans-1<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
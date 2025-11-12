#include<bits/stdc++.h>
using namespace std;
int n,m,a[508];
string s; 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int flag=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==0)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cnt++;
			}
		}
		if(n-cnt<m)
		{
			cout<<"0"<<"\n";
		}
		else
		{
			long long ans=1,t=n;
			ans=ans*t%998244353;
			cout<<ans<<"\n";
		}
	}
	cout<<"0"<<"\n";
	return 0;
}




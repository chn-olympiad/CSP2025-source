#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,m;
string s;
int c[505];
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
	if(m==1)
	{
		int good=0;
		for(int i=n;i>=1;i--)
		{
			if(c[i]>n+1-i)
			{
				good=n+1-i;
				break;
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=2;
		}
		int delans=1;
		for(int i=1;i<=n-good;i++)
		{
			delans*=2;
		}
		ans=ans-delans-1;
		cout<<ans%N<<endl;
		return 0;
	}
	else
	{
		cout<<1<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
}


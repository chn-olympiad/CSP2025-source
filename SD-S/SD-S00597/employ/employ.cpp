#include<bits/stdc++.h>
using namespace std;
long long ren[505];
string kj;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>kj;
	for(int i=0;i<m;i++)
	{
		cin>>ren[i];
	}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=kj[i]-'0';
	}
	if(ans==kj.length())
	{
		ans=1;
		for(int i=0;i<n;i++)
		{
			ans=ans*ren[i];
			ans%=998224353;
		}
		cout<<ans<<endl;
	}
	else if(m==n)
	{
		sort(ren,ren+n);
		int yi=1,shu=1,g=-1;
		ans=0;
		for(int i=n-1;i>=0;i--)
		{
			if(ren[i]!=g)
			{
				ans*=shu;
				shu=1;
				g=ren[i];
				yi=1;
			}
			else
			{
				shu++;
				yi*=shu+1;
			}
			if(ren[i]<=i+1)
			{
				cout<<0<<endl;
				return 0;
			}
		}
		ans*=yi;
		cout<<ans<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}


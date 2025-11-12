#include<bits/stdc++.h>

using namespace std;

const int N=520,M=998244353;

long long n,m,a[N],ans,maxx,ss,sss;
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	maxx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			ans++;
		}
		maxx=max(maxx,a[i]);
	}
	if(m==1)
	{
		ss=1;
		if(maxx>ans)
		{
			for(int i=1;i<=n;i++)
			{
				ss=(ss*i%M)%M;
			}
			cout<<ss;
		}
		else
		{
			long long cnt=maxx-1;
			for(int i=1;i<n;i++)
			{
				ss=(ss*i%M)%M;
			}
			//for(int i=1;i<=)
		}
	}
	return 0;
}


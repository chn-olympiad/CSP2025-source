#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998224353;
int n,a[5005];
int qpow(int x,int a)
{
	int ans=1,X=x;
	while(a>0)
	{
		if(a%2==1) ans=ans*X%mod;
		X=X*X%mod;
		a>>=1;
	}
	return ans;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int maxa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(maxa==1)
	{
		cout<<(qpow(2,n)+mod-(n*n+n+2)/2)%mod<<endl;
		return 0;
	}
	if(n<=20)
	{
		int ans=0;
		for(int i=0;i<(1<<n);i++)
		{
			int sum=0,maxaa=0,cnt=0;
			for(int j=1;j<=n;j++)
				if(i&(1<<(j-1)))
				{
					sum+=a[j];
					maxaa=max(maxaa,a[j]);
					cnt++;
				}
			if(cnt<3 || maxaa*2>=sum) continue;
			ans++;
		}
		cout<<ans%mod<<endl;
		return 0;
	}
	return 0;
}
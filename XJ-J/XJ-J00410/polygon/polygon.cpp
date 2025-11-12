#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[5005],ans=0,mod=998244353;
bool check(int m)
{
	int maxx=0,sum=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(m>>i&1)
		{
			sum+=a[i+1];
			maxx=max(maxx,a[i+1]);
			cnt++;
		}
	}
	if(sum>2*maxx&&cnt>=3) return true;
	return false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i;
	cin>>n;
	if(n>30)
	{
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(i=1;i<=n;i++) cin>>a[i];
		int last=pow(2,n)-1;
		for(i=1;i<=last;i++)
		{
			if(check(i)) ans++;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}

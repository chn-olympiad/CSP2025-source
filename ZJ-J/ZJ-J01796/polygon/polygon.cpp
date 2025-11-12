#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const long long e=998244353;
long long n;
long long ans=0,a[100005];
void search(long long p,long long q,long long k)
{
	for(int i=q-1;i>=1;i--)
	{
		if(a[i]+k>=p)
		{
			ans+=pow(2,i-1);
			if(a[i]+k==p)ans-=1;
		}else if(i>1)
		{
			search(p,i,k+a[i]);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n);
	for(int i=n;i>=3;i--)
	{
		search(a[i],i,0);
	}
	cout<<ans%e;
	return 0;
}
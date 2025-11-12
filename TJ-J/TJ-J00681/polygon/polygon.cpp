#include <bits/stdc++.h>
using namespace std;
long long mod=998224353;
int a[100005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i--)
	{
		if(ans>a[n]*2)
		{
			cnt++;
			ans-=a[i];
		}
		else
		{
			ans-=a[n];
		}
	}
	cout<<cnt;
	return 0;
}

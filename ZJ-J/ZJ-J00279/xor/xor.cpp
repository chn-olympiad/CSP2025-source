#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0] = -1;
	for(long long i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i] == k)
		{
			ans++;
			a[i] = -1;
		}
		if(a[i] == a[i-1]&&a[i]!=-1)
		{
			cnt++;
			a[i] = -1;
		}
	}
	if(k == 0)
	{
		cout<<ans+cnt;
	}
	else
	{
		cout<<ans;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000010],sum,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum^=a[i];
		if(sum==k)
		{
			ans++;
			sum=0;
		}
	}
	cout<<ans;
	return 0;
}

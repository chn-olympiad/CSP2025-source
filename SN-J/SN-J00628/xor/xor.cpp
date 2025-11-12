#include<bits/stdc++.h>
using namespace std;
int ans,sum,n,a[10005];
long long k;
int main()
{
	frepen("xor.in","r",stdin);
	frepen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum=a[i]^sum;
		if(sum==k)
		{
			ans++;
			sum=0;
		}
	}
	cout<<ans;
	return 0;
}

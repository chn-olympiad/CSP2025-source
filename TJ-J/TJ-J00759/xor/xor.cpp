#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,k,a[510000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) ans++;
	} 
	if(ans==n&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	else
	{
		if(k==0)
		{
			int y=ans/2;
			cout<<max(n-ans,n-ans+y);
			return 0;
		}
		else
		{
			cout<<max(ans,n-ans);
			return 0;
		} 
	} 
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum,ans;
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int l=1,r=1;r<=n;r++)
	{
		sum^=a[r];
		while(sum>k&&l<r)sum^=a[l++];
		if(sum==k)ans++,l=r+1,sum=0;
	}
	cout<<ans;
	return 0;
}


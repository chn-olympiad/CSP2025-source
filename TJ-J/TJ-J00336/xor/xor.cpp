#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans,n,k,a[15],a0,a1;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
		if(a[i]==0) a0++;
		if(a[i]==1) a1++;
		cout<<a1<<" "<<a0<<" ";
		if(i==n)
		{
			if(k==0&&ans==n)
			{
				cout<<n;
				break;
			}
			if(k==1&&n==1)
			{
				cout<<0;
				break;
			}
			if(k==1&&ans*2==n)
			{
				cout<<n/2;
				break;
			}
//			if(k==1&&a1>a0)
//			{
//				if(a0%2==0&&a1%2==1) cout<<a0+a0/2;
//				if(a1%2==0&&a0%2==1) cout<<a0+a1/2;
//				break;
//			}
//			if(k==1&&a0>a1)
//			{
//				if(a0%2==0&&a1%2==1) cout<<a1+a0/2;
//				if(a1%2==0&&a0%2==1) cout<<a1+a1/2;
//				break;
//			}
		}
	}
	return 0;
}

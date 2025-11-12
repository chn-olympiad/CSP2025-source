#include<bits/stdc++.h>
using namespace std;
int n;
int nums[1000010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>nums[i];
	sort(nums+1,nums+1+n);
	int tmp = nums[n]*2;
	if(n==3)
	{
		long long ans = 1%998244353;
	    if(nums[1]+nums[2]+nums[3]>tmp) cout<<ans;
	    else cout<<0;
	}
	else{
		long long w = 0;
		long long num = 2;
		for(int i = 3;i<=n;i++)
		{
			long long ans = 1;
		    for(int j = n;j>n-i;j--) ans*=j;
		    num*=i;
		    w+=ans/num;
		}
		cout<<w%998244353;
	}
	return 0;
}

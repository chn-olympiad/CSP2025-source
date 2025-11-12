#include<bits/stdc++.h>
using namespace std;
int n,k;
int nums[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	nums[0]=1;
	bool is = true;
	cin>>n>>k;
	for(int i = 1;i<=n;i++) 
	{
		cin>>nums[i];
		if(nums[i]!=nums[i-1]||nums[i]!=1) is = false;
	}
	if(is)
	{
		cout<<n/2;
		return 0;
	}
	int maxx = 0;
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		int num  = nums[i];
		if(num==k)
		{
		    ans++;
			continue;
		}
		for(int j = i+1;j<=n;j++)
		{
		if(num^nums[j]==k) 
		{
			ans++;
			i=j+1;
			break;
		}
			num^=nums[j];
		}
	}
	maxx = max(maxx,ans);
	cout<<maxx;
	return 0;
}

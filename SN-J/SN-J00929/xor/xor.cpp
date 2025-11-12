/*
SN-J00929
董国栋 
西安市曲江第一学校 
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],dp[500010],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int now=0;
	for(int i=1;i<=n;i++)
	{
		now^=a[i];
		if(now==k)
			ans++,now=0;
	}
	cout<<ans;
	return 0;
}

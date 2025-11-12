#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long long n,m,t,ans=1;
string a;
long long nums[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>nums[i];
		if(nums[i]!=0)
		{
			t++;
		}
	}
	if(t<m)
	{
		cout<<0<<endl;
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			ans*=i;
			ans%=998244353;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
*/ 


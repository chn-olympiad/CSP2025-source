//SN-J00649  林靖轩  西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mo=998244353;
int n,cnt=-1,ans=1,sum=0;
int a[5010];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt=max(a[i],cnt),sum+=a[i];
	
	if(cnt<=1)
	{
		for(int i=1;i<=n;i++)
			ans*=2,ans%=mo;
		ans-=1;
		//不取任何数
		ans-=n;
		//只取一个数
		ans-=(n*(n-1)/2)%mo;
		ans%=mo;
		//只取二个数
		cout<<ans;
		return 0; 
		 
	}
	else
	{
		if(n<=2)
		{
			cout<<0;
			return 0;
		}
		else if(n==3)
		{
			int maa=-1;
			for(int i=1;i<=n;i++)
				maa=max(maa,a[i]);
			if(sum>maa*2)
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
		else
		{
			cout<<0;
			return 0;	
		} 
	}
	return 0;
}
//6*4+3*4=9*4=36

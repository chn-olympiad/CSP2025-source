#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=1)
		{
			flag=1;
		}
	}
	if(n<3)
	{
		cout << 0;
		return 0;
	}
	if(n==3)
	{
		int x=a[1]+a[2]+a[3];
		int y=max(max(a[1],a[2]),a[3]);
		if(x>2*y)
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	if(flag==0)
	{
		int ans=0;
		for(int i=1;i<=n-2;i++)
		for(int j=1;j<=n-1-i;j++)
		{
			ans+=i;
		}
		ans%=998;
		ans%=244;
		ans%=353;
		cout << ans;
		return 0;
	}
	return 0;
}

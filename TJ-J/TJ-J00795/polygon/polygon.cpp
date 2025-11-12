#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long _pow(int a,int b)
{
	long long ans = 1;
	for(int i = 1;i <= b;i++)
	{
		ans *= a;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,maxa = -1e9,cnt = 0;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		maxa = max(maxa,a[i]);
	}
	if(maxa == 1)
	{
		cout<<n % 998244353;
		return 0;
	}
	long long val = _pow(2,n) - 1;
	for(int i = 1;i <= val;i++)
	{
		long long num = i,j = 1,ans = 0,maxaj = -1e9;
		while(num)
		{
			ans += a[j] * (num & 1);
			maxaj = max(maxaj,a[j] * (num & 1));
			num = num >> 1;	
			j++;
		}
		if(ans > 2 * maxaj)
		{
			cnt++;
			cnt %= 998244353;
		}
	}
	cout<<cnt % 998244353;
	return 0;
}


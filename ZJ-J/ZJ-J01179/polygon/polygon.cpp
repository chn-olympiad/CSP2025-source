#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],sum,ans,mnax,c[5005][5005];
int main()
{
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum==n)
	{
		c[0][0] = 1;
		for(int i = 1;i <= n+1;i++)
		{
			for(int j = 1;j <= i;j++)
			{
				c[i][j] = (c[i-1][j-1]+c[i-1][j]) % 998244353;
			}
		}
		sum = 0;
		for(int i = 3;i <= n;i++)
		{
			sum = (sum+c[n+1][i+1]) % 998244353;
		}
		cout<<sum;
	}
	else
	{
		sort(a+1,a+1+n);
		for(int bs = 1;bs < pow(2,n);bs++)
		{
			sum = mnax = 0;
			for(int j = 0;j < n;j++)
			{
				if((bs>>j)%2)
				{
					mnax = max(mnax,a[j+1]);
					sum+=a[j+1];
				}
			}
			cout<<sum<<' '<<mnax<<'\n';
			if(sum > mnax*2)
			{
				cout<<sum<<' '<<mnax<<'\n';
				ans++;
				ans %= 998244353;
			}
		}
		cout<<ans;
	}
	
	return 0;
}

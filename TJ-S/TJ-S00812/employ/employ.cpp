#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m ;
	if(m==1)
	{
		ans=1;
		for(int i=n;i>0;i--)
		{
			ans*=i;
			ans%=998244353;
		}
		cout << ans ;
		return 0;
	}
	else
	{
		cout << 0 ;
		return 0;
	}
}

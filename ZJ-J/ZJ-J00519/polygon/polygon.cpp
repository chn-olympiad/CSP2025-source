/*
把long long换成long long
开freopen
去#define 
*/
#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n;
long long a[5005];
long long ans = 0;
void AAA(long long x,long long y,long long z,long long m)
{
	if(x>n)
	{
		if(y>2&&z>2*m) 
		{
			ans++;
			ans %= mod;
		}
		return;
	}
	AAA(x+1,y,z,m);
	AAA(x+1,y+1,z+a[x],max(m,a[x]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i];
    if(n<=26) AAA(1,0,0,0);
    else 
    {
    	ans = 1;
    	for(long long i=1;i<=n;i++)
    	{
    		ans *= 2;
    		ans %= mod;
		}
		for(long long i=1;i<n;i++)
		{
			ans -= i;
			ans += mod;
			ans %= mod;
		}
	}
    cout<<ans;
    return 0;
}


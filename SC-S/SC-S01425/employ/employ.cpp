#include <bits/stdc++.h>
using namespace std;
long long n,m,k,c[999999],ans=1;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>c[i];
    	ans=ans*i;
        ans=ans%998244353;
	}
	cout<<ans%998244353;
	return 0;
}
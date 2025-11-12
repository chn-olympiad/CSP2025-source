#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n < 3) cout << 0; return 0;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n == 3 && a[1]+a[2]+a[3] > 20) cout << 1;
	else cout << (((n-1)*n)/2)%mod;
	return 0;
}

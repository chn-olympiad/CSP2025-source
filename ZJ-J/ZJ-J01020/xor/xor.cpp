#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k;
	vector<ll> a(n+1);
	vector<ll> x_s(n+1,0);
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		x_s[i] += x_s[i-1] ^ a[i];
	}
	ll ans = 0;
	int R = 0;
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			if ((i > R) && ((i==j ? a[i]:x_s[j]^x_s[i-1])== k)){
				R = j;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

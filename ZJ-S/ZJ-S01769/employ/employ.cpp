#include<bits/stdc++.h>
using namespace std;
int n,m,p[505],c[505];
char s[505];
const int Mod(998244353);
void baoli()
{
	long long ans(0);
	for(int i(1);i <= n;++i) p[i] = i;
	do
	{
		int cnt1(0),cnt2(0);
		for(int i(1);i <= n;++i)
		{
			if(c[p[i]] > cnt2 && s[i] == '1') ++cnt1;
			else ++cnt2;
		}
		if(cnt1 >= m) ++ans,ans %= Mod;
	}while(next_permutation(p+1,p+1+n));
	cout << ans;
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	cin >> (s+1);
	for(int i(1);i <= n;++i) cin >> c[i];
	baoli();
}

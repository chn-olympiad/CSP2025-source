#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int c[505], f[505];
int n, m;
string s;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++) f[i]=i;
	int ans=0;
	do
	{
		int refused=0, employed=0;
		for(int i=1;i<=n;i++)
		{
			if(refused>=c[f[i]]||s[i]=='0')
				refused++;
			else employed++;
			if(employed>=m) break;
		}
		if(employed>=m) ans++, ans%=mod;
	}while(next_permutation(f+1, f+1+n));
	cout<<ans;
	return 0;
}

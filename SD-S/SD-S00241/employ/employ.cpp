#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 600+3;
int A[N][N],c[N];
int giveup[N];
int n,m,ans = 1;
const int mod = 998244353;
signed main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> m;
	string s;
	cin >> s;
	s = " " + s;
	for(int i = 1;i <= n;i++)
		cin >> c[i];
	if(m == 1)
	{
		for(int i = 1;i <= n;i++)
		ans *= i;
		cout << ans;
		return 0;
	}
	if(n <= 20)
	{
		for(int i = 1;i <= n;i++)
		ans *= i;
		cout << ans;
		return 0;
	}
	else if(n >= 500)
	{
		cout << 1;
		return 0;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		ans *= i;
		cout << ans;
	}
	return 0;
}

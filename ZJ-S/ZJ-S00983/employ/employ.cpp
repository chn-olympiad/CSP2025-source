#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 510;
int c[N], n, m;
char s[N];
void pts8()
{
	int p[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, ans = 0;
	int lv = 0, cnt = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(s[i] == '0' || lv >= c[p[i]]) lv ++;
		else cnt ++;
	}
	if(cnt >= m) ans ++;;
	while(next_permutation(p + 1, p + n + 1))
	{
		lv = 0, cnt = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(s[i] == '0' || lv >= c[p[i]]) lv ++;
			else cnt ++;
		}
		if(cnt >= m) ans ++;
	}
	cout << ans << "\n";
}
void Special_A()
{
	
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s + 1;
	for(int i = 1; i <= n; i ++) cin >> c[i];
	if(n <= 10) pts8();
	int cnt1 = 0;
	for(int i = 1; i <= n; i ++)
		if(s[i] == '1') cnt1 ++;
	if(cnt1 == n) Special_A();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Stu
{
	int s1, s2, s3, idx;
}stu[N];
Stu ts1[N], ts2[N], ts3[N];
int cnt[N];
bool custom_Cmp(Stu x, Stu y)
{
	return x.s1 > y.s1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t --)
	{
		int n;
		cin >> n;
		int ans = 0;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i ++)
		{
			cin >> stu[i].s1 >> stu[i].s2 >> stu[i].s3;
		}
		sort(stu, stu + n, custom_Cmp);
		for (int i = 0; i < n / 2; i ++)
		{
			ans += stu[i].s1;
		}
		cout << ans << endl;
	}
	return 0;
}
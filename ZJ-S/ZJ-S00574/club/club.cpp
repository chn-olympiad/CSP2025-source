#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define int long long
int n, ans;
int ch[4];
int a[N][4];
int cha[N];
int ch1[N];
void solve()
{
	ans = 0;
	memset(ch, 0, sizeof(ch));
	memset(ch1, 0, sizeof(ch1));
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int maxx = -1, tmp;
		for(int j = 1;j <= 3;j++)
			if(a[i][j] > maxx)
			{
				maxx = a[i][j];
				tmp = j;
			}
		ch1[i] = tmp;
		ch[tmp]++;
		ans += maxx;
		sort(a[i] + 1, a[i] + 3 + 1);
	}
	int k = max(ch[1],max(ch[2], ch[3]));
	int jcr, l = 0;
	for(int i = 1;i <= 3;i++)
		if(ch[i] == k)	jcr = i;
	for(int i = 1; i <= n;i++)
		if(ch1[i] == jcr)
		{
			cha[++l] = a[i][3] - a[i][2];
		}	
	sort(cha + 1, cha + l + 1);
	k -= n / 2;
	for(int i = 1;i <= k;i++)	ans -= cha[i];
	cout << ans << "\n";
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--)	solve();
	return 0;
}

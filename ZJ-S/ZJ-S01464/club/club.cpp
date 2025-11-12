#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n , a[N][3] , c[N];
void Solve()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	int cnt[3] = {}; ll ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		int mx = max({a[i][0] , a[i][1] , a[i][2]});
		for(int j = 0 ; j < 3 ; j++)
		{
			if(a[i][j] == mx)
			{
				c[i] = j;
				cnt[j]++;
				ans += mx;
				break ;
			}
		}
	}
	if(max({cnt[0] , cnt[1] , cnt[2]}) <= n / 2)
	{
		cout << ans << "\n";
		return ;
	}
	int t = cnt[0] > n / 2 ? 0 : (cnt[1] > n / 2 ? 1 : 2);
	vector<int>vc;
	for(int i = 1 ; i <= n ; i++)
		if(c[i] == t)
		{
			int se = -1;
			for(int j = 0 ; j < 3 ; j++)
				if(j != t)se = max(se , a[i][j]);
			vc.push_back(a[i][t] - se);
		}
	sort(vc.begin() , vc.end());
	// cerr << ans << ':' << cnt[t] - n / 2 << "\n";
	for(int i = 0 ; i < cnt[t] - n / 2 ; i++)
		ans -= vc[i];
	cout << ans << "\n";
	return ;
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int T; cin >> T;
	while(T--)Solve();
	return 0;
}
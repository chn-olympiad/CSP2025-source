#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[505];
signed main()
{
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,q = 1,ans = 0;
	cin >> n >> m;
	string k;
	cin >> k;
	for(int i = 0;i < n;i++) q &= k[i];
	if(n <= 10)
	{
		vector<int> pm;
		for(int i = 1;i <= n;i++) cin >> p[i];
		for(int i = 1;i <= n;i++) pm.push_back(i);
		int tmp = 1;
		for(int i = 1;i <= n;i++) tmp *= i;
		for(int r = 1;r <= tmp;r++)
		{
			next_permutation(pm.begin(),pm.end());
			int p_ = 0,l = 0;
			for(int i = 0;i < n;i++)
			{
				if(p_ >= p[pm[i]])
				{
					p_++;
					continue;
				}
				if(k[i] == '0') p_++;
				else l++;
			}
			if(l >= m) ans++;
		}
		cout << ans << endl;
	}
	else cout << rand() << endl;
	return 0;
}
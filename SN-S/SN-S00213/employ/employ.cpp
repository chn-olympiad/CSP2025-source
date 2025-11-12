#include<bits/stdc++.h>

using namespace std;

#define N 19
#define mod 998244353

int n, m, CNT, c[N], a[N];
string s;

//void DP()
//{
//	CNT = n;
//	for(int j = 1; j <= n; j++)
//	{
//		if(0 >= c[j] || s[1] == '0')f[1 << j - 1][j][1] = 1;
//		else f[1 << j - 1][j][0] = 1;
//	}
//	for(int sta = 0; sta < (1 << n); sta++)
//	{
//		int i = __builtin_popcount(sta);
//		for(int j = 1; j <= n; j++)
//		{
//			if(!(sta >> j - 1 & 1))continue;
//			for(int k = 0; k <= i; k++)//被gank的人数 
//			{
//				int nsta = (sta ^ (1 << j - 1));
//				if(k < c[j] && s[i] == '1')
//				{
//					CNT += n;
//					for(int l = 1; l <= n; l++)
//						if(nsta >> l - 1 & 1)
//							f[sta][j][k] = (f[sta][j][k] + f[nsta][l][k]) % mod;
//				}
//				else if(k >= 1)
//				{
//					CNT += n;
//					for(int l = 1; l <= n; l++)
//						if(nsta >> l - 1 & 1)
//							f[sta][j][k] = (f[sta][j][k] + f[nsta][l][k - 1]) % mod;
//				}
//			}
//		}
//	}
//		
//			
//}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s; s = " " + s;
	for(int i = 1; i <= n; i++)cin >> c[i], a[i] = i;
	int ans = 0;
	do
	{
		int cnt = 0;//前面没选上的人数 
		for(int i = 1; i <= n; i++)
			if(cnt >= c[a[i]] || s[i] == '0')cnt++;
		if(cnt <= n - m)ans++;
		if(ans > mod)ans -= mod;
	}
	while(next_permutation(a + 1, a + n + 1));
	cout << ans; 
	return 0;
} 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
//Ahhhhhhhh I'm So Cute Ahhhhhhhhh Too Hard n^2
const int N = 5e5 + 10;

ll a[N];
ll pre[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = (pre[i - 1] ^ a[i]);
	}
	ll ans = 0, last = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j >= last; j--)
		{
			if ((pre[i] ^ pre[j - 1]) == k)
			{
				ans++;
				last = i + 1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
//HaoYunLai ZhuNiHaoYunLai
//HaoYunDaiLaiLeXiHeAi
//HaoYunLaiWoMenHaoYunLai
//YinZheHaoYunXingWangFaDaTongSiHai!

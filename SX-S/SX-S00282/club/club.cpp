#include <bits/stdc++.h>
using namespace std;

int t, ans, n, x1, x2, x3, x4, x5, x6;
int a1[50010], a2[50010], a3[50010];
//int x[100010];
//, vis[100010];//, ans[300010];

void choose()
{
	x1 = a1[1] + a2[2];
	x2 = a1[1] + a3[2];
	x3 = a2[1] + a3[2];
	x4 = a2[1] + a1[2];
	x5 = a3[1] + a1[2];
	x6 = a3[1] + a2[2];
	ans = max(max(max(x1, x2), x3), max(max(x5, x6), x4));
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;

	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= 2; i++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		choose();
		cout << ans << "\n";
	}
	return 0;
}












































































//int t, ans, cnt1, cnt2, cnt3, n;
//int a1[50010], a2[50010], a3[50010];
//int x[100010], vis[100010];//, ans[300010];
//
//void choose()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		if (a1[i] >= a2[i] && a1[i] >= a3[i])
//		{
//			x[i] = a1[i];
////			vis[i] = 1;
////			cnt1++;
//		}
//		else if (a2[i] >= a1[i] && a2[i] >= a3[i])
//		{
//			x[i] = a2[i];
////			vis[i] = 2;
////			cnt2++;
//		}
//		else if (a3[i] >= a1[i] && a3[i] >= a2[i])
//		{
//			x[i] = a3[i];
////			vis[i] = 3;
////			cnt3++;
//		}
////		ans1 = ans1 + x[i];
//		ans += x[i];
//	}
//}
//
////void check()
////{
////	if (cnt1 > n / 2)
////	{
////		for (int i = 1; i <= n; i++)
////		{
////			ans[i] = ans1;
////			if (vis[i] == 1)
////			{
////				for (int j = 1; j <= cnt1 - n / 2; j++)
////				{
////					if (vis[i + j - 1] == 1)
////					{
////						//lian xu de shu???
////						if (a2[i + j - 1] >= a3[i + j - 1])
////							x[i + j - 1] = a2[i + j - 1];
////						else if (a3[i + j - 1] >= a2[i + j - 1])
////							x[i + j - 1] = a3[i + j - 1];
////					}
////
////					ans[i] = ans[i] - a1[i + j - 1] + x[i + j - 1];
////					x[i + j - 1] = a1[i + j - 1];//?
////				}
////			}
////			if (i > 1)
////			{
////				ans1 = max(ans[i], ans[i - 1]);
////			}
////		}
////		check();
////	}
////
////	if (cnt2 > n / 2)
////	{
////		for (int i = 1; i <= n; i++)
////		{
////			ans[i] = ans1;
////			if (vis[i] == 2)
////			{
////				for (int j = 1; j <= cnt2 - n / 2; j++)
////				{
////					if (vis[i + j - 1] == 2)
////					{
////						//lian xu de shu???
////						if (a1[i + j - 1] >= a3[i + j - 1])
////							x[i + j - 1] = a1[i + j - 1];
////						else if (a3[i + j - 1] >= a1[i + j - 1])
////							x[i + j - 1] = a3[i + j - 1];
////					}
////
////					ans[i] = ans[i] - a1[i + j - 1] + x[i + j - 1];
////					x[i + j - 1] = a1[i + j - 1];//?
////				}
////			}
////			if (i > 1)
////			{
////				ans1 = max(ans[i], ans[i - 1]);
////			}
////		}
////		check();
////	}
////
////	if (cnt3 > n / 2)
////	{
////		for (int i = 1; i <= n; i++)
////		{
////			ans[i] = ans1;
////			if (vis[i] == 3)
////			{
////				for (int j = 1; j <= cnt3 - n / 2; j++)
////				{
////					if (vis[i + j - 1] == 1)
////					{
////						//lian xu de shu???
////						if (a1[i + j - 1] >= a2[i + j - 1])
////							x[i + j - 1] = a1[i + j - 1];
////						else if (a2[i + j - 1] >= a1[i + j - 1])
////							x[i + j - 1] = a2[i + j - 1];
////					}
////
////					ans[i] = ans[i] - a1[i + j - 1] + x[i + j - 1];
////					x[i + j - 1] = a1[i + j - 1];//?
////				}
////			}
////			if (i > 1)
////			{
////				ans1 = max(ans[i], ans[i - 1]);
////			}
////		}
////		check();
////	}
////}
//
//int main()
//{
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> t;
//
//	while (t--)
//	{
//	//			memset(a1,0,sizeof)
//	//			memset(vis, 0, sizeof(vis));
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//
//
//			cin >> a1[i] >> a2[i] >> a3[i];
//
//		}
//		choose();
////		check();
//		cout << ans << "\n";
//	}
//	return 0;
//}
////GOOD LUCK!
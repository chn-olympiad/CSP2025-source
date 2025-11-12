#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct stu{
	int a, b, c, id;
	bool is = false;
}f[100005];

bool cmpa(stu x, stu y)
{
	return x.a > y.a;
}

bool cmpa_abc(stu x, stu y)
{
	if (x.a != y.a) return x.a > y.a;
	else if (x.b != y.b) return x.b < y.b;
	else if (x.c != y.c) return x.c < y.c;
	else return x.id < y.id;
}

bool cmpb_abc(stu x, stu y)
{
	if (x.b != y.b) return x.b > y.b;
	else if (x.c != y.c) return x.c < y.c;
	else return x.id < y.id;
}

bool cmpa_acb(stu x, stu y)
{
	if (x.b != y.b) return x.b > y.b;
	else if (x.c != y.c) return x.c < y.c;
	else if (x.b != y.b) return x.b < y.b;
	else return x.id < y.id;
}

bool cmpb_acb(stu x, stu y)
{
	if (x.c != y.c) return x.c < y.c;
	else if (x.b != y.b) return x.b > y.b;
	else return x.id < y.id;
}

bool cmpb_bac(stu x, stu y)
{
	if (x.b != y.b) return x.b > y.b;
	else if (x.a != y.a) return x.a < y.a;
	else if (x.c != y.c) return x.c < y.c;
	else return x.id < y.id;
}

bool cmpa_bac(stu x, stu y)
{
	if (x.a != y.a) return x.a < y.a;
	else if (x.c != y.c) return x.c > y.c;
	else return x.id < y.id;
}

bool cmpb_bca(stu x, stu y)
{
	if (x.b != y.b) return x.b > y.b;
	else if (x.c != y.c) return x.c < y.c;
	else if (x.a != y.a) return x.a < y.a;
	else return x.id < y.id;
}

bool cmpc_bca(stu x, stu y)
{
	if (x.c != y.c) return x.c > y.c;
	else if (x.a != y.a) return x.a < y.a;
	else return x.id < y.id;
}

bool cmpc_cab(stu x, stu y)
{
	if (x.c != y.c) return x.c > y.c;
	else if (x.a != y.a) return x.a < y.a;
	else if (x.b != y.b) return x.b < y.b;
	else return x.id < y.id;
}

bool cmpa_cab(stu x, stu y)
{
	if (x.a != y.a) return x.a > y.a;
	else if (x.b != y.b) return x.b < y.b;
	else return x.id < y.id;
}

bool cmpc_cba(stu x, stu y)
{
	if (x.c != y.c) return x.c > y.c;
	else if (x.b != y.b) return x.b < y.b;
	else if (x.a != y.a) return x.a < y.a;
	else return x.id < y.id;
}

bool cmpb_cba(stu x, stu y)
{
	if (x.b != y.b) return x.b > y.b;
	else if (x.a != y.a) return x.a < y.a;
	else return x.id < y.id;
}

void specAd(int n)
{
	int ans = 0;
	sort(f + 1, f + n + 1, cmpa);
	for (int i = 1; i <= n / 2; i++) ans += f[i].a;
	cout << ans << endl;
}


void solve()
{
	int n, solve = -1;
	cin >> n;
	bool specA = true;
	for (int i = 1; i <= n; i++)
	{
		f[i].id = i;
		cin >> f[i].a >> f[i].b >> f[i].c;
		if (f[i].b != 0 || f[i].c != 0) specA = false;
	}
	if (specA)
	{
		specAd(n);
		return;
	}
	int n2 = n / 2;
	// a b c!!
	for (int i = 0; i <= n2; i++)
	{
//		cout << "选择到A：" << i << endl;
		int ans = 0;
		sort(f + 1, f + n + 1, cmpa_abc);
//		cout << "此时列表：" << endl;
//		for (int z = 1; z <= n; z++)
//		{
//			cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//		}
		for (int j = 1; j <= i; j++)
		{
//			cout << "选择id：" << f[j].id << ' ';
			f[j].is = true;
			ans += f[j].a;
//			cout << "目前ans：" << ans << endl;
		}
//		cout << endl;
		int ans2 = ans;
		for (int k = n2 - i; k <= n2; k++)
		{
//			cout << "选择到B：" << k << endl;
			ans = ans2;
			sort(f + (1 + i), f + n + 1, cmpb_abc);
//			cout << "此时列表：" << endl;
//			for (int z = 1; z <= n; z++)
//			{
//				cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//			}
			for (int l = i + 1; l <= i + k; l++)
			{
//				cout << "选择id：" << f[l].id << ' ';
				f[l].is = true;
				ans += f[l].b;
//				cout << "目前ans：" << ans << endl;	
			}
			int last = n - k - i;
//			cout << "选择到C：" << last << endl;
			for (int s = i + k + 1; s <= n; s++)
			{
//				cout << "选择id：" << f[s].id << ' ';
				ans += f[s].c;
//				cout << "目前ans：" << ans << endl;
			} 
			solve = max(ans, solve);
		}
	}
	//a c b!!
	for (int i = 0; i <= n2; i++)
	{
//		cout << "选择到A：" << i << endl;
		int ans = 0;
		sort(f + 1, f + n + 1, cmpa_acb);
//		cout << "此时列表：" << endl;
//		for (int z = 1; z <= n; z++)
//		{
//			cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//		}
		for (int j = 1; j <= i; j++)
		{
//			cout << "选择id：" << f[j].id << ' ';
			f[j].is = true;
			ans += f[j].a;
//			cout << "目前ans：" << ans << endl;
		}
//		cout << endl;
		int ans2 = ans;
		for (int k = n2 - i; k <= n2; k++)
		{
//			cout << "选择到B：" << k << endl;
			ans = ans2;
			sort(f + (1 + i), f + n + 1, cmpb_acb);
//			cout << "此时列表：" << endl;
//			for (int z = 1; z <= n; z++)
//			{
//				cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//			}
			for (int l = i + 1; l <= i + k; l++)
			{
//				cout << "选择id：" << f[l].id << ' ';
				f[l].is = true;
				ans += f[l].c;
//				cout << "目前ans：" << ans << endl;	
			}
			int last = n - k - i;
//			cout << "选择到C：" << last << endl;
			for (int s = i + k + 1; s <= n; s++)
			{
//				cout << "选择id：" << f[s].id << ' ';
				ans += f[s].b;
//				cout << "目前ans：" << ans << endl;
			} 
			solve = max(ans, solve);
		}
	}
	// b a c!!
	for (int i = 0; i <= n2; i++)
	{
//		cout << "选择到A：" << i << endl;
		int ans = 0;
		sort(f + 1, f + n + 1, cmpb_bac);
//		cout << "此时列表：" << endl;
//		for (int z = 1; z <= n; z++)
//		{
//			cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//		}
		for (int j = 1; j <= i; j++)
		{
//			cout << "选择id：" << f[j].id << ' ';
			f[j].is = true;
			ans += f[j].b;
//			cout << "目前ans：" << ans << endl;
		}
//		cout << endl;
		int ans2 = ans;
		for (int k = n2 - i; k <= n2; k++)
		{
//			cout << "选择到B：" << k << endl;
			ans = ans2;
			sort(f + (1 + i), f + n + 1, cmpa_bac);
//			cout << "此时列表：" << endl;
//			for (int z = 1; z <= n; z++)
//			{
//				cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//			}
			for (int l = i + 1; l <= i + k; l++)
			{
//				cout << "选择id：" << f[l].id << ' ';
				f[l].is = true;
				ans += f[l].a;
//				cout << "目前ans：" << ans << endl;	
			}
			int last = n - k - i;
//			cout << "选择到C：" << last << endl;
			for (int s = i + k + 1; s <= n; s++)
			{
//				cout << "选择id：" << f[s].id << ' ';
				ans += f[s].c;
//				cout << "目前ans：" << ans << endl;
			} 
			solve = max(ans, solve);
		}
	}
	// b c a!!
	for (int i = 0; i <= n2; i++)
	{
//		cout << "选择到A：" << i << endl;
		int ans = 0;
		sort(f + 1, f + n + 1, cmpb_bca);
//		cout << "此时列表：" << endl;
//		for (int z = 1; z <= n; z++)
//		{
//			cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//		}
		for (int j = 1; j <= i; j++)
		{
//			cout << "选择id：" << f[j].id << ' ';
			f[j].is = true;
			ans += f[j].b;
//			cout << "目前ans：" << ans << endl;
		}
//		cout << endl;
		int ans2 = ans;
		for (int k = n2 - i; k <= n2; k++)
		{
//			cout << "选择到B：" << k << endl;
			ans = ans2;
			sort(f + (1 + i), f + n + 1, cmpc_bca);
//			cout << "此时列表：" << endl;
//			for (int z = 1; z <= n; z++)
//			{
//				cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//			}
			for (int l = i + 1; l <= i + k; l++)
			{
//				cout << "选择id：" << f[l].id << ' ';
				f[l].is = true;
				ans += f[l].c;
//				cout << "目前ans：" << ans << endl;	
			}
			int last = n - k - i;
//			cout << "选择到C：" << last << endl;
			for (int s = i + k + 1; s <= n; s++)
			{
//				cout << "选择id：" << f[s].id << ' ';
				ans += f[s].a;
//				cout << "目前ans：" << ans << endl;
			} 
			solve = max(ans, solve);
		}
	}
	// c a b!!
	for (int i = 0; i <= n2; i++)
	{
//		cout << "选择到A：" << i << endl;
		int ans = 0;
		sort(f + 1, f + n + 1, cmpc_cab);
//		cout << "此时列表：" << endl;
//		for (int z = 1; z <= n; z++)
//		{
//			cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//		}
		for (int j = 1; j <= i; j++)
		{
//			cout << "选择id：" << f[j].id << ' ';
			f[j].is = true;
			ans += f[j].c;
//			cout << "目前ans：" << ans << endl;
		}
//		cout << endl;
		int ans2 = ans;
		for (int k = n2 - i; k <= n2; k++)
		{
//			cout << "选择到B：" << k << endl;
			ans = ans2;
			sort(f + (1 + i), f + n + 1, cmpa_cab);
//			cout << "此时列表：" << endl;
//			for (int z = 1; z <= n; z++)
//			{
//				cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//			}
			for (int l = i + 1; l <= i + k; l++)
			{
//				cout << "选择id：" << f[l].id << ' ';
				f[l].is = true;
				ans += f[l].a;
//				cout << "目前ans：" << ans << endl;	
			}
			int last = n - k - i;
//			cout << "选择到C：" << last << endl;
			for (int s = i + k + 1; s <= n; s++)
			{
//				cout << "选择id：" << f[s].id << ' ';
				ans += f[s].b;
//				cout << "目前ans：" << ans << endl;
			} 
			solve = max(ans, solve);
		}
	}
	// c b a!!
	for (int i = 0; i <= n2; i++)
	{
//		cout << "选择到A：" << i << endl;
		int ans = 0;
		sort(f + 1, f + n + 1, cmpc_cba);
//		cout << "此时列表：" << endl;
//		for (int z = 1; z <= n; z++)
//		{
//			cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//		}
		for (int j = 1; j <= i; j++)
		{
//			cout << "选择id：" << f[j].id << ' ';
			f[j].is = true;
			ans += f[j].c;
//			cout << "目前ans：" << ans << endl;
		}
//		cout << endl;
		int ans2 = ans;
		for (int k = n2 - i; k <= n2; k++)
		{
//			cout << "选择到B：" << k << endl;
			ans = ans2;
			sort(f + (1 + i), f + n + 1, cmpb_cba);
//			cout << "此时列表：" << endl;
//			for (int z = 1; z <= n; z++)
//			{
//				cout << f[z].id << ' ' << f[z].a << ' ' << f[z].b << ' ' << f[z].c << endl;
//			}
			for (int l = i + 1; l <= i + k; l++)
			{
//				cout << "选择id：" << f[l].id << ' ';
				f[l].is = true;
				ans += f[l].b;
//				cout << "目前ans：" << ans << endl;	
			}
			int last = n - k - i;
//			cout << "选择到C：" << last << endl;
			for (int s = i + k + 1; s <= n; s++)
			{
//				cout << "选择id：" << f[s].id << ' ';
				ans += f[s].a;
//				cout << "目前ans：" << ans << endl;
			} 
			solve = max(ans, solve);
		}
	}
	cout << solve << endl;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}

/*
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107
*/

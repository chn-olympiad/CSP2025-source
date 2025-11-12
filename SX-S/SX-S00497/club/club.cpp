#include <bits/stdc++.h>
using namespace std;
int n, ans;
const int MAXN = 1e5+15;
int ans1 = 0, ans2 = 0, ans3 = 0;

struct Node {
	int a_1;//满意度
	int a_2;
	int a_3;
	bool aa = 0;
	bool bb = 0;
	bool cc = 0;
//	int a_all;//总满意度
} a[MAXN];

struct node {
	int aaa;//修改变化量
	int nnn;//修改社团
	int oold;//原先值
	int oldn;//原先位置
};

bool cmp1(Node mm, Node nn) {
	return mm.a_1 < nn.a_1; //为特殊性质A设计
}

bool cmp2(Node mm, Node nn) { //为特殊性质B设计
	int minum, minun;
	minum = mm.a_1 - mm.a_2;
	minun = nn.a_1 - nn.a_2;
	return minum < minun;
}

bool cmp(Node mm, Node nn) {
	int minum, minun;
	minum = abs(mm.a_1 - mm.a_2) + abs(mm.a_1 - mm.a_3) + abs(mm.a_2 - mm.a_3);
	minun = abs(nn.a_1 - nn.a_2) + abs(nn.a_1 - nn.a_3) + abs(nn.a_2 - nn.a_3);
	return minum > minun;
}

bool cmpc(node mm, node nn) {
	return mm.aaa > nn.aaa;
}


void tz1(int q) {
	node c[MAXN];//改变值
	memset(c, 0, sizeof(c));
	int hh;
	int j = 1;
	for (int i = 1; i <= n; i++) {

		if (a[i].aa) {
//			cout << "testbool1: " << a[i].aa << " " << a[i].a_1 << endl;

			if (a[i].a_2 > a[i].a_3) {
				c[j].aaa = a[i].a_2 - a[i].a_1;
				c[j].oold = a[i].a_1;
				c[j].oldn = i;
				c[j].nnn = 2;
				j++;
			} else if (a[i].a_2 < a[i].a_3) {
				c[j].aaa = a[i].a_3 - a[i].a_1;
				c[j].oold = a[i].a_1;
				c[j].oldn = i;
				c[j].nnn = 3;
				j++;
			} else if (a[i].a_2 == a[i].a_3 && ans2 > ans3) {
				c[j].aaa = a[i].a_3 - a[i].a_1;
				c[j].oold = a[i].a_1;
				c[j].oldn = i;
				c[j].nnn = 3;
				j++;
			} else if (a[i].a_2 == a[i].a_3 && ans2 < ans3) {
				c[j].aaa = a[i].a_2 - a[i].a_1;
				c[j].oold = a[i].a_1;
				c[j].oldn = i;
				c[j].nnn = 2;
				j++;
			}
			a[i].aa = 0;
			hh = j - 1;
		}
	}
	sort(c + 1, c + hh + 1, cmpc);

//	cout << " " << hh << endl;
	int s = ans1 - q;
	for (int i = 1; i <= s; i++) {
		ans += c[i].aaa;
		if (c[i].nnn == 2)
			ans2++;
		else if (c[i].nnn == 3)
			ans3++;
		ans1--;
//		cout << "test: " << c[i].aaa << " " << c[i].oold << " " << c[i].nnn << endl;
	}

}

void tz2(int q) {
	node c[MAXN];//改变值
	memset(c, 0, sizeof(c));
	int hh;
	int j = 1;
	for (int i = 1; i <= n; i++) {

		if (a[i].bb) {
//			cout << "testbool1: " << a[i].bb << " " << a[i].a_2 << endl;

			if (a[i].a_1 > a[i].a_3) {
				c[j].aaa = a[i].a_1 - a[i].a_2;
				c[j].oold = a[i].a_2;
				c[j].oldn = i;
				c[j].nnn = 1;
				j++;
			} else if (a[i].a_1 < a[i].a_3) {
				c[j].aaa = a[i].a_3 - a[i].a_2;
				c[j].oold = a[i].a_2;
				c[j].oldn = i;
				c[j].nnn = 3;
				j++;
			} else if (a[i].a_1 == a[i].a_3 && ans1 > ans3) {
				c[j].aaa = a[i].a_3 - a[i].a_2;
				c[j].oold = a[i].a_2;
				c[j].oldn = i;
				c[j].nnn = 3;
				j++;
			} else if (a[i].a_2 == a[i].a_1 && ans1 < ans3) {
				c[j].aaa = a[i].a_1 - a[i].a_2;
				c[j].oold = a[i].a_2;
				c[j].oldn = i;
				c[j].nnn = 1;
				j++;
			}
			a[i].bb = 0;
			hh = j - 1;
		}
	}
	sort(c + 1, c + hh + 1, cmpc);

//	cout << " " << hh << endl;
	int s = ans2 - q;
	for (int i = 1; i <= s; i++) {
		ans += c[i].aaa;
		if (c[i].nnn == 1)
			ans1++;
		else if (c[i].nnn == 3)
			ans3++;
		ans2--;
//		cout << "test: " << c[i].aaa << " " << c[i].oold << " " << c[i].nnn << endl;
	}
}

void tz3(int q) {
	node c[MAXN];//改变值
	memset(c, 0, sizeof(c));
	int hh;
	int j = 1;
	for (int i = 1; i <= n; i++) {

		if (a[i].cc) {
//			cout << "testbool1: " << a[i].cc << " " << a[i].a_3 << endl;

			if (a[i].a_1 > a[i].a_2) {
				c[j].aaa = a[i].a_1 - a[i].a_3;
				c[j].oold = a[i].a_3;
				c[j].oldn = i;
				c[j].nnn = 1;
				j++;
			} else if (a[i].a_1 < a[i].a_2) {
				c[j].aaa = a[i].a_2 - a[i].a_3;
				c[j].oold = a[i].a_3;
				c[j].oldn = i;
				c[j].nnn = 2;
				j++;
			} else if (a[i].a_1 == a[i].a_2 && ans1 > ans2) {
				c[j].aaa = a[i].a_2 - a[i].a_3;
				c[j].oold = a[i].a_3;
				c[j].oldn = i;
				c[j].nnn = 2;
				j++;
			} else if (a[i].a_2 == a[i].a_1 && ans1 < ans2) {
				c[j].aaa = a[i].a_1 - a[i].a_3;
				c[j].oold = a[i].a_3;
				c[j].oldn = i;
				c[j].nnn = 1;
				j++;
			}
			a[i].cc = 0;
			hh = j - 1;
		}
	}
	sort(c + 1, c + hh + 1, cmpc);

//	cout << " " << hh << endl;
	int s = ans3 - q;
	for (int i = 1; i <= s; i++) {
		ans += c[i].aaa;
		if (c[i].nnn == 1)
			ans1++;
		else if (c[i].nnn == 2)
			ans2++;
		ans3--;
//		cout << "test: " << c[i].aaa << " " << c[i].oold << " " << c[i].nnn << endl;
	}
}



int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		n = ans1 = ans2 = ans3 = ans = 0;
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		bool h = 0, y = 0;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a_1 >> a[i].a_2 >> a[i].a_3;
			if ((a[i].a_2 != 0) or (a[i].a_3 != 0))
				h = 1;
			if (a[i].a_3 != 0)
				y = 1;
		}
		if (!h) {
			sort(a + 1, a + 1 + n, cmp1);
			for (int i = n; i > n / 2; --i) {
				ans += a[i].a_1;
//				cout << "test:" << a[i].a_1 << endl;
			}
			cout << ans << endl;

			continue;

		} else if (!y) {
			sort(a + 1, a + 1 + n, cmp2);
			for (int i = n; i > n / 2; --i) {
				ans += a[i].a_1;
//				cout << "test:" << a[i].a_1 << " " << a[i].a_2 << endl;
			}
			for (int i = n / 2 ; i > 0; --i) {
				ans += a[i].a_2;
//				cout << "test:" << a[i].a_1 << " " << a[i].a_2 << endl;
			}
			cout << ans << endl;
			continue;
		}
		sort(a + 1, a + 1 + n, cmp);

//		bool h1 = 1, h2 = 1, h3 = 1;
		int q = floor(n / 2);
		for (int w = 1; w <= n; w++) {
			int mx = -1;
			int aurora = -1;
//			cout << "test:" << w << " :" << a[w].a_1 << " " << a[w].a_2 << " " << a[w].a_3;
//			cout << " minus:" << (abs(a[w].a_1 - a[w].a_2) + abs(a[w].a_1 - a[w].a_3) + abs(a[w].a_2 - a[w].a_3));
			if (a[w].a_1 > mx) {
				mx = a[w].a_1;
				aurora = 1;
//				ans1++;
			}
			if (a[w].a_2 > mx) {
				mx = a[w].a_2;
				aurora = 2;
//				ans2++;
			}
			if (a[w].a_3 > mx) {
				mx = a[w].a_3;
				aurora = 3;
//				ans3++;
			}
			ans += mx;


			if (aurora == 1) {
				ans1++;
				a[w].aa = 1;
			}

			else if (aurora == 2) {
				ans2++;
				a[w].bb = 1;
			}

			else if (aurora == 3) {
				ans3++;
				a[w].cc = 1;
			}

//			cout << "chosen: " << mx << endl;
		}
		while ((ans1 > q) || (ans2 > q) || (ans3 > q)) {
			if (ans1 > q)
				tz1(q);
			if (ans2 > q)
				tz2(q);
			if (ans3 > q)
				tz3(q);
		}



		cout << ans << endl;
	}

	return 0;
}
/*
30
10424 1888 2199
17649 15804 14198
10138 18538 13467
6761 3083 2293
15041 10863 4222
14340 5758 4300
19996 18929 18297
10926 3304 2176
7141 10829 10956
13607 4376 14108
16686 9725 6258
4434 18794 4926
11129 10938 790
8722 4648 9466
8433 9585 14771
14115 7600 2137
13059 4853 4038
16361 10577 6964
11071 2792 4531
19225 16563 12240
4933 7500 11108
13470 7273 3969
19927 15477 7010
13889 8913 284
16346 8745 3469
4832 9878 2776
11723 6399 3415
13453 19859 13711
10335 7892 6192
19584 11583 14062

*/
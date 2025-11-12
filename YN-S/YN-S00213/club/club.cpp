#include <bits/stdc++.h>////////////
using namespace std;
int n;
const int maxn = 2e6 + 5;

struct nodee {
	int num, id, shu;
};
//用3个数组分别存储以i，j、k为优先排序因素
nodee man1[maxn], man2[maxn], man3[maxn];

bool cmp1(nodee x, nodee y) {
	return x.num > y.num;
}

bool cmp2(nodee x, nodee y) {
	return x.num > y.num;
}

bool cmp3(nodee x, nodee y) {
	return x.num > y.num;
}

bool vis[maxn];//是否被选中
int s[3];
int iid[3];
long long ans = 0;
void jiajia(int &a, int b) {//++++
	a++;

	if (vis[man1[iid[b]].id] && man1[iid[b]].id <= n) {
		jiajia(a, b);
	}
}

void solve() {
	cin >> n;
	ans = 0;
	s[0] = s[1] = s[2] = 0;

	for (int i = 1; i <= n; i++) {

		int a, b, c;
		cin >> a >> b >> c;
		man1[i] = {a, i, 0};
		man2[i] = {b, i, 1};
		man3[i] = {c, i, 2};
		vis[i] = false;
	}

	iid[0] = 1;
	iid[1] = 1;
	iid[2] = 1;

	sort(man1 + 1, man1 + 1 + n, cmp1);
	sort(man2 + 1, man2 + 1 + n, cmp2);
	sort(man3 + 1, man3 + 1 + n, cmp3);

	//接下来，一项一项的往下比较
	//三种数组中更大的一组就放入社团
	int biggest, bigger, biggness;
	nodee biggest_yuan, bigger_yuan, biggness_yuan;
	int xxxs, xxs, xs;

	for (int i = 1; i <= n; i++) {
//
//		int summmmmmm = 0;
//
//		if (man1[iid[0]].num == 0)
//			summmmmmm++;
//
//		if (man2[iid[1]].num == 0)
//			summmmmmm++;
// 
//		if (man3[iid[2]].num == 0)
//			summmmmmm++;
//		bool flag = false;
// 
//		if (summmmmmm >= 3)
//			flag = true;
//
//		if (vis[man1[iid[0]].id] && flag) {
//			jiajia(iid[0], 0);
//		}
//
//		if (vis[man2[iid[1]].id] && flag) {
//			jiajia(iid[1], 1);
//		}
//
//		if (vis[man2[iid[2]].id] && flag) {
//			jiajia(iid[2], 2);
//		}

		biggest = max(man1[iid[0]].num, max(man2[iid[1]].num, man3[iid[2]].num));

		if (man1[iid[i]].num == biggest) {
			biggest_yuan = man1[iid[0]];
			xxxs = 0;
		} else if (man2[iid[i]].num == biggest) {
			biggest_yuan = man2[iid[1]];
			xxxs = 1;
		} else {
			biggest_yuan = man3[iid[2]];
			xxxs = 2;
		}

		biggness = min(man1[iid[0]].num, min(man2[iid[1]].num, man3[iid[2]].num));

		if (man1[iid[0]].num == biggness) {
			biggness_yuan = man1[iid[0]];
			xxs = 0;
		} else if (man2[iid[1]].num == biggness) {
			biggness_yuan = man2[iid[1]];
			xxs = 1;
		} else {
			biggness_yuan = man3[iid[2]];
			xxs = 2;
		}

		bigger = man1[iid[0]].num + man2[iid[1]].num + man3[iid[2]].num - biggest - biggness;

		if (man1[iid[0]].num == bigger) {
			bigger_yuan = man1[iid[i]];
			xs = 0; 
		} else if (man2[iid[1]].num == bigger) {
			bigger_yuan = man2[iid[1]];
			xs = 1;
		} else {
			bigger_yuan = man3[iid[2]];
			xs = 2;
		}

		if (!vis[biggest_yuan.id] && s[xxxs] < n / 2 && iid[biggest_yuan.shu] <= n) {
			vis[biggest_yuan.id]
			    = true;
			s[xxxs]++;
			iid[biggest_yuan.shu]++;
			ans += biggest;
		} else if (!vis[bigger_yuan.id] && s[xxs] < n / 2 && iid[bigger_yuan.shu] <= n) {
			vis[bigger_yuan.id] = true;
			s[xxs]++;
			iid[bigger_yuan.shu]++;
			ans += bigger;
		} else { 
			vis[biggness_yuan.id] = true;
			s[xs]++;
			iid[biggness_yuan.shu]++;
			ans += biggness;
		}
	}

	cout << ans << endl;
}

int main(void) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

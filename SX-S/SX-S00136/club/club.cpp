#include <bits/stdc++.h>
using namespace std;
long long T, n, a1, b1, c1, summ;

struct node {
	int a, b, c, c1, c2, maxx, minn, middle;
	string maxxx, minnn, mid;
} nod[200005];

bool cmp(node x, node y) {
	if (x.c1 == y.c1) {
		return x.c2 > y.c2;//差一一样按照差二排序
	}
	return x.c1 > y.c1;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> nod[i].a >> nod[i].b >> nod[i].c;
			if (nod[i].a >= nod[i].b) {
				if (nod[i].a >= nod[i].c) {
					if (nod[i].b >= nod[i].c) { //c<=b<=a;
						nod[i].maxx = nod[i].a;
						nod[i].minn = nod[i].c;
						nod[i].middle = nod[i].b;
						nod[i].c1 = nod[i].maxx - nod[i].middle;
						nod[i].c2 = nod[i].middle - nod[i].minn;
						nod[i].maxxx = "a";
						nod[i].minnn = "c";
						nod[i].mid = "b";
					} else { //b<c<=a;
						nod[i].maxx = nod[i].a;
						nod[i].minn = nod[i].b;
						nod[i].middle = nod[i].c;
						nod[i].c1 = nod[i].maxx - nod[i].middle;
						nod[i].c2 = nod[i].middle - nod[i].minn;
						nod[i].maxxx = "a";
						nod[i].minnn = "b";
						nod[i].mid = "c";
					}
				} else { //b<=a<c
					nod[i].maxx = nod[i].c;//c最大
					nod[i].minn = nod[i].b;
					nod[i].middle = nod[i].a;
					nod[i].c1 = nod[i].c - nod[i].a;
					nod[i].c2 = nod[i].a - nod[i].b;
					nod[i].maxxx = "c";
					nod[i].minnn = "b";
					nod[i].mid = "a";
				}
			} else { //a<b
				if (nod[i].a >= nod[i].c) { //c<=a<b
					nod[i].maxx = nod[i].b;
					nod[i].minn = nod[i].c;
					nod[i].middle = nod[i].a;
					nod[i].c1 = nod[i].maxx - nod[i].middle;
					nod[i].c2 = nod[i].middle - nod[i].minn;
					nod[i].maxxx = "b";
					nod[i].minnn = "c";
					nod[i].mid = "a";
				} else {
					if (nod[i].b <= nod[i].c) { //a<b<=c
						nod[i].maxx = nod[i].c;
						nod[i].minn = nod[i].a;
						nod[i].middle = nod[i].b;
						nod[i].c1 = nod[i].maxx - nod[i].middle;
						nod[i].c2 = nod[i].middle - nod[i].minn;
						nod[i].maxxx = "c";
						nod[i].minnn = "a";
						nod[i].mid = "b";
					} else { //a<c<b
						nod[i].maxx = nod[i].b;
						nod[i].minn = nod[i].a;
						nod[i].middle = nod[i].c;
						nod[i].c1 = nod[i].maxx - nod[i].middle;
						nod[i].c2 = nod[i].middle - nod[i].minn;
						nod[i].maxxx = "b";
						nod[i].minnn = "a";
						nod[i].mid = "c";
					}
				}
			}

		}
		a1 = n / 2; //每个部门最多
		b1 = n / 2;
		c1 = n / 2;
		stable_sort(nod + 1, nod + n + 1, cmp);//按照选择紧急度来排序
		/*for (int i = 1; i <= n; i++) {
			cout << "a:" << nod[i].a << " " << "b:" << nod[i].b << " " << "c:" << nod[i].c << " " << "c1:" << nod[i].c1 << " " <<
			     "c2:" << nod[i].c2 << " " << endl;
		}*/
		for (int i = 1; i <= n; i++) {
			if (nod[i].maxxx == "a" && a1 != 0) {
				summ += nod[i].maxx;
				a1--;
			} else if (nod[i].maxxx == "b" && b1 != 0) {
				summ += nod[i].maxx;
				b1--;
			} else if (nod[i].maxxx == "c" && c1 != 0) {
				summ += nod[i].maxx;
				c1--;
			} else if (nod[i].maxxx == "a") { //不能选最优选
				if (nod[i].mid == "b" && b1 != 0) {
					summ += nod[i].middle;
					b1--;
				} else if (nod[i].mid == "c" && c1 != 0) {
					summ += nod[i].middle;
					c1--;
				} else {
					summ += nod[i].minn;
				}
			} else if (nod[i].maxxx == "b") {
				if (nod[i].mid == "a" && a1 != 0) {
					summ += nod[i].middle;
					a1--;
				} else if (nod[i].mid == "c" && c1 != 0) {
					summ += nod[i].middle;
					c1--;
				} else {
					summ += nod[i].minn;
				}
			} else if (nod[i].maxxx == "c") {
				if (nod[i].mid == "b" && b1 != 0) {
					summ += nod[i].middle;
					b1--;
				} else if (nod[i].mid == "a" && a1 != 0) {
					summ += nod[i].middle;
					a1--;
				} else {
					summ += nod[i].minn;
				}
			}
		}
		//清零
		cout << summ << '\n';
		summ = 0;
	}

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct one{
	int cha1, de1;
	int cha2, de2;
	int num;
}b[maxn];
int t, n, ans;
int a[maxn][5];
vector<int> d2, d3;
bool cmp(one x, one y) {
	if (x.cha1 == y.cha1) return x.cha2 < y.cha2;
	return x.cha1 > y.cha1;
}
bool cmp2(int x, int y) {
	return b[x].cha2 > b[y].cha2;
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	std::ios::sync_with_stdio (false);
	std::cin.tie(0); std::cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n; ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			ans += a[i][1];
			b[i].num = i;
			if (a[i][2] - a[i][1] >= a[i][3] - a[i][1]) b[i].cha1 = a[i][2] - a[i][1], b[i].de1 = 2, b[i].cha2 = a[i][3] - a[i][1], b[i].de2 = 3;
			else b[i].cha1 = a[i][3] - a[i][1], b[i].de1 = 3, b[i].cha2 = a[i][2] - a[i][1], b[i].de2 = 2;
		}
		sort(b+1, b+n+1, cmp);
//		for (int i = 1; i <= n; i++) {
//			cout << b[i].num << " " << b[i].cha1 << " " << b[i].de1 << " " << b[i].cha2 << " " << b[i].de2 << endl;
//		}
		int cnt = 0, s2 = 0, s3 = 0;
		while (cnt < n / 2) {
			cnt++;
			ans += b[cnt].cha1;
			if (b[cnt].de1 == 2) s2++, d2.push_back(b[cnt].num);
			else s3++, d3.push_back(b[cnt].num);
		}
		cnt++;
		while (b[cnt].cha1 > 0) {
			if (b[cnt].de1 == 2 && s2 < n / 2) ans += b[cnt].cha1, s2++;
			else if (b[cnt].de1 == 3 && s3 < n / 2) ans += b[cnt].cha1, s3++;
			else if (b[cnt].de2 <= 0) continue;
			else if (b[cnt].de2 == 2 && s2 < n / 2) ans += b[cnt].cha2, s2++;
			else if (b[cnt].de2 == 3 && s3 < n / 2) ans += b[cnt].cha2, s3++;
			else if (b[cnt].de1 == 2 && s3 < n / 2) {
				sort(d2.begin(), d2.end(), cmp2);
				for (int i = 0; i < d2.size(); i++) {
					if (b[d2[i]].cha2 + b[cnt].cha1 > b[d2[i]].cha1 + b[cnt].cha2 * (b[cnt].cha2 > 0)) {
						d3.push_back(d2[i]), d2[i] = cnt, ans += b[d2[i]].cha2 + b[cnt].cha1 - b[d2[i]].cha1, s3++;
						break;
					}
				}
			} else if (b[cnt].de1 == 3 && s2 < n / 2) {
				sort(d3.begin(), d3.end(), cmp2);
				for (int i = 0; i < d3.size(); i++) {
					if (b[d3[i]].cha2 + b[cnt].cha1 > b[d3[i]].cha1 + b[cnt].cha2 * (b[cnt].cha2 > 0)) {
						d2.push_back(d3[i]), d3[i] = cnt, ans += b[d3[i]].cha2 + b[cnt].cha1 - b[d3[i]].cha1, s2++;
						break;
					}
				}
			}
			cnt++; 
		}
		cout << ans << endl;
	}
	return 0;
}

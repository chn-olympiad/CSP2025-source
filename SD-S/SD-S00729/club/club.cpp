// 给我，破！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
// 18:14：看到最后一个大样例过的时候，我内心反而十分平静 
// 起码不用 afo 了吧，应该吧应该吧 
// freopen 
// 100+48+[0,100]+8=[156,256]，还没去年高呢，希望 T3 总司令能多给几分吧 
// 不过今年是不是难一点啊也不知道
// freopen
//freopen
// freopen("club.in", "w", stdout);
// freopen("club.out", "r", stdin);
// 18:19 再想一下 T3 部分分吧 
// 好吧脑子已经烧没了，所以还是得 afo 吗
// 所以总司令还会送 45 分吗
// 能不能多送点分啊，孩子快 afo 了呜呜呜 
// #include <bits\stdc++.h>
#include <bits/stdc++.h>
#define N 100010
using namespace std;
int T, n, a[N][4];
struct node {
	int id, num, num2;
	bool operator <(const node x) const {
		return num - num2 < x.num - x.num2;
	}
	bool operator >(const node x) const {
		return num - num2 > x.num - x.num2;
	}
};
void getrank(int vis, int &rk1, int &rk2, int &rk3) {
	if(a[vis][rk3] > a[vis][rk2]) swap(rk2, rk3);
	if(a[vis][rk2] > a[vis][rk1]) swap(rk1, rk2);
	if(a[vis][rk3] > a[vis][rk2]) swap(rk2, rk3);
}
int querynxt(int x, int vis) { // 查询 a[x] 中小于等于 vis 最大的那个 
	int ret = 0;
	for(int i = 1; i <= 3; i++) {
		if(i == vis) continue;
		if(a[x][i] <= a[x][vis] && (!ret || a[x][i] > a[x][ret]))
			ret = i;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T; 
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		priority_queue <node, vector <node>, greater <node> > p[4];
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			bool isfh = 0;
			int _nrk = 0, _nvis23 = 0, _nid = 0, _nnum = 0, _nnum23 = 0, _plus = -1000000000;
			int rk[4] = {0, 1, 2, 3};
			getrank(i, rk[1], rk[2], rk[3]);
//			for(int i = 1; i <= 3; i++) cout << rk[i] << ' '; cout << '\n';
			bool isok = 0;
			for(int j = 1; j <= 3; j++) {
				int nrk = rk[j];
				// 如果能直接塞进去就直接塞
				if(p[nrk].size() < n / 2) {
					/*p[nrk].push(node{i, a[i][nrk]});
					ans += a[i][nrk];*/
					if(a[i][nrk] > _plus) {
//						if(i == 3) cout << "!!!" << nrk << '\n';
						_plus = a[i][nrk];
						_nrk = nrk;
						isfh = 0;
					}
//					cout << "notfh goto" << nrk << '\n';
				// 否则尝试反悔，看是否更优
				} else {
					node tmp = p[nrk].top();
					int nid = tmp.id, nnum = tmp.num;
					int nvis2 = querynxt(nid, nrk);
					int nnum2 = tmp.num2;
//					cout << nid << ' ' << nnum << ' ' << nvis2 << ' ' << nnum2 << '\n';
//					cout << a[i][nrk] << '\n';
					if(nvis2 && p[nvis2].size() < n / 2 && nnum2 + a[i][nrk] - nnum > 0) {
						// 反悔更优，那么反悔
						/*p[nrk].pop(); p[nrk].push(node{i, a[i][nrk]});
						p[nvis2].push(node{nid, nnum2});
						ans = ans - nnum + nnum2 + a[i][nrk];
						isok = 1;*/
						if(nnum2 + a[i][nrk] - nnum > _plus) {
//							if(i == 7) cout << j << " in!!! " << nnum2 << ' ' << a[i][nrk] << ' ' << nnum << '\n';
							_plus = nnum2 + a[i][nrk] - nnum;
							isfh = 1;
							_nrk = nrk;
							_nvis23 = nvis2;
							_nid = nid;
							_nnum = nnum;
							_nnum23 = nnum2;
						}
//						cout << "fh: " << nid << "to2\n";
					} else if(nvis2) {
						int nvis3 = querynxt(nid, nvis2);
						int nnum3 = tmp.num2;
						if(nvis3 && p[nvis3].size() < n / 2 && nnum3 + a[i][nrk] - nnum > 0) {
							// 反悔更优，那么反悔
							/*p[nrk].pop(); p[nrk].push(node{i, a[i][nrk]});
							p[nvis3].push(node{nid, nnum3});
							ans = ans - nnum + nnum3 + a[i][nrk];
							isok = 1;*/
							if(nnum3 + a[i][nrk] - nnum > _plus) {
								_plus = nnum3 + a[i][nrk] - nnum;
								isfh = 1;
								_nrk = nrk;
								_nvis23 = nvis3;
								_nid = nid;
								_nnum = nnum;
								_nnum23 = nnum3;
							}
//							cout << "fh: " << nid << "to3\n";
						}
					}
				}
//				if(i == 7) cout << j << ": " << _plus << '\n';
			}
//			cout << isfh << ' ' << _nrk << ' ' << _nvis23 << ' ' << _nid << ' ' << _nnum << ' ' << _nnum23 << ' ' << _plus << '\n';
			if(isfh) {
				p[_nrk].pop(); p[_nrk].push(node{i, a[i][_nrk], a[i][querynxt(i, _nrk)]});
				p[_nvis23].push(node{_nid, _nnum23, a[i][querynxt(i, _nrk)]});
				ans = ans + _plus;
			} else {
				p[_nrk].push(node{i, a[i][_nrk], a[i][querynxt(i, _nrk)]});
				ans = ans + _plus;
			}
//			cout << ans << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
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
*/

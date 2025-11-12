//YN-S00247 欧阳语堂
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int s = 0; //测试组数
	cin >> s;
	int sum[100000];//新成员满意度数组
	int a[100000];
	//int b[100000];
	//int c[100000];
	//int aperson = 0;
	//int bperson = 0;
	//int cperson = 0;
	int n;//新成员数量
	for (int i = 0; i < s; i++) {
		int jishu = 0;
		cin >> n;
		for (int j = 0; j < 3 * n; j += 3) {
			cin >> sum[j];
			cin >> sum[j + 1];
			cin >> sum[j + 2];
			a[j] = sum[j];
			//cout << "a[j]=" << a[j] << endl;
		}
		int b = 0;
		while (b < 10000) {
			for (int y = 0; y < 10000; y++) {
				int canshu = a[y];
				if (a[y] < a[y + 1]) {
					a[y] = a[y + 1];
					a[y + 1] = canshu;
					//cout << "a[y]=" << a[y] << endl;
				}
			}
			b++;
		}
		for (int z = 0; z < n / 2; z++) {
			jishu =  jishu + a[z];
		}
		cout << jishu << endl;
	}

	return 0;
}
//YN-S00247 欧阳语堂
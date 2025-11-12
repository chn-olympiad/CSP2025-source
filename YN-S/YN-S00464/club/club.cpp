#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	int t, n, a[4], feeling, max = 1, num[4], min = 1, middle = 1;
	cin >> t >> n;;
	for (int o = 1; o <= t; o++) { //测试几组数据
		for (int i = 1; i <= n; i++) { //几个人
			for (int k = 0; k < 3; k++) {//每个人对三个组的满意度
				cin >> a[k];
//				if (a[1] < a[2] < a[3]) {
//					max = a[3];
//					middle = a[2];
//					min = a[1];
//					feeling = n / 2 * max + min + n / 2 - 1 * middle;
//				}
//				if (a[1] < a[3] < a[2]) {
//					max = a[2];
//					middle = a[3];
//					min = a[1];
//					feeling = n / 2 * max + min + n / 2 - 1 * middle;
//				}
//				if (a[2] < a[1] < a[3]) {
//					max = a[3];
//					middle = a[1];
//					min = a[2];
//					feeling = n / 2 * max + min + n / 2 - 1 * middle;
//				}
//				if (a[2] < a[3] < a[1]) {
//					max = a[1];
//					middle = a[3];
//					min = a[2];
//					feeling = n / 2 * max + min + n / 2 - 1 * middle;
//				}
//				if (a[3] < a[1] < a[2]) {
//					max = a[2];
//					middle = a[1];
//					min = a[3];
//					feeling = n / 2 * max + min + n / 2 - 1 * middle;
//				}
//				if (a[3] < a[2] < a[1]) {
//					max = a[1];
//					middle = a[2];
//					min = a[3];
//					feeling = n / 2 * max + min + n / 2 - 1 * middle;
//				}
				max = a[k];
				min = a[k];
				middle = a[k];
				if (a[k - 1] < max < a[k + 1])
					max = a[k + 1]; //最所多满意的组
				if (min < a[k] < a[k + 1])
					min = a[k - 1]; //最少满意的组
				if (min < a[k] < max)  //中等满意度的组
					middle = a[k];

			}
			feeling = n / 2 * max + min + n / 2 - 1 * middle;
		}
		cout << feeling << endl;
	}
	return 0;




}


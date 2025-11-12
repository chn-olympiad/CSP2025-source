#include <bits/stdc++.h>
using namespace std;
long long t, n, a[100005], b[100005], c[100005], cnt, m, sum;
long long mmax, minb, bb1, bb2, bb3, sum1, sum2, sum3, mmin = 20001, j;
//j是最小sum的标记，sum1是1,2的差，sum2是2,3的差，sum3是1,3的差，sum是最大和第二大的差，cnt是最终答案；

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		m = n / 2;
		for (int i = 1; i <= n; i++) {

			cin >> a[i] >> b[i] >> c[i];
			mmax = max(a[i], max(b[i], c[i]));
			cnt += mmax;





			if (a[i] == mmax and b[i] == mmax and c[i] == mmax) {
				sum1 = 0;
				sum2 = 0;
				sum3 = 0;
				sum = 0;
				minb = min(bb1, min(bb2, bb3));
				if (minb == bb1) {
					bb1++;
				} else if (minb == bb2) {
					bb2++;
				} else if (minb == bb3) {
					bb3++;
				}
			}//如果三个数相等就选人数最少的部门abc




			else if (a[i] == mmax and b[i] == mmax and c[i] != mmax) {
				sum1 = 0;
				sum2 = abs(b[i] - c[i]);
				sum3 = abs(a[i] - c[i]);
				sum = 0;
				minb = min(bb1, bb2);
				if (minb == bb1) {
					bb1++;
				} else if (minb == bb2) {
					bb2++;
				}
			}//如果两个数相等就选人数少的部门ab




			else if (a[i] == mmax and b[i] != mmax and c[i] == mmax) {
				sum1 = abs(a[i] - b[i]);
				sum2 = abs(b[i] - c[i]);
				sum3 = 0;
				sum = 0;
				minb = min(bb1, bb3);
				if (minb == bb1) {
					bb1++;
				} else if (minb == bb3) {
					bb3++;
				}
			}//如果两个数相等就选人数少的部门ac




			else if (a[i] == mmax and b[i] == mmax and c[i] != mmax) {
				sum1 = abs(a[i] - b[i]);
				sum2 = 0;
				sum3 = abs(a[i] - c[i]);
				sum = 0;
				minb = min(bb2, bb3);
				if (minb == bb2) {
					bb2++;
				} else if (minb == bb3) {
					bb3++;
				}
			}//如果两个数相等就选人数少的部门bc




			else if (a[i] == mmax and b[i] != mmax and c[i] != mmax) {
				sum = abs(mmax - max(b[i], c[i]));
				bb1++;
			}//选最大a




			else if (a[i] != mmax and b[i] == mmax and c[i] != mmax) {
				sum = abs(mmax - max(a[i], c[i]));
				bb2++;
			}//选最大b




			else if (a[i] != mmax and b[i] != mmax and c[i] == mmax) {
				sum = abs(mmax - max(a[i], b[i]));
				bb3++;
			}//选最大c

			if (sum < mmin) {
				mmin = sum;
				j = i;
			}



		}//记得给计数器归零





		if (bb1 <= m and bb2 <= m and bb3 <= m) {
			cout << cnt << "\n";
			cnt = 0;
		} else {
			if (bb1 > m) {
				//找到(最大的与第二大的差）最小的替换sum
				cout << cnt - max(a[j], max(b[j], c[j])) + (a[j] + b[j] + c[j] - max(a[j], max(b[j], c[j])) - min(a[j], min(b[j],
				        c[j]))) << "\n";
				cnt = 0;
			}
			if (bb2 > m) {
				//找到(最大的与第二大的差）最小的替换sum
				cout << cnt - max(a[j], max(b[j], c[j])) + (a[j] + b[j] + c[j] - max(a[j], max(b[j], c[j])) - min(a[j], min(b[j],
				        c[j]))) << "\n";
				cnt = 0;
			}
			if (bb3 > m) {
				//找到(最大的与第二大的差）最小的替换sum
				cout << cnt - max(a[j], max(b[j], c[j])) + (a[j] + b[j] + c[j] - max(a[j], max(b[j], c[j])) - min(a[j], min(b[j],
				        c[j]))) << "\n";
				cnt = 0;
			}
		}


	}
	return 0;
}
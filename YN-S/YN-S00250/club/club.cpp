#include <bits/stdc++.h>
using namespace std;
long long t, n;
long long num1[100000 + 10], num2[100000 + 10], num3[100000 + 10];

struct threew {
	long long a;
	long long b;
	bool flag = 0;
};
threew arr[1000000 + 10];

bool cmp(threew x, threew y) {
	if (x.a != y.a) {
		return x.a > y.a;
	} else {
		return x.b < y.b;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> num1[i] >> num2[i] >> num3[i];
		}
		if (n == 2) {
			long long ans1, ans2, ans3, ans4, ans5, ans6;
			ans1 = num1[1] + num2[2];
			ans2 = num1[1] + num3[2];
			ans3 = num2[1] + num1[2];
			ans4 = num2[1] + num3[2];
			ans5 = num3[1] + num1[2];
			ans6 = num3[1] + num2[2];
			cout << max(ans1, max(ans2, max(ans3, max(ans4, max(ans5, ans6))))) << endl;
		} else {
			bool flag = 0;
			for (int i = 1; i <= n; i++) {
				if (num2[i] != 0 || num3[i] != 0) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				sort(num1 + 1, num1 + 1 + n, greater<long long>());
				long long sum = 0;
				for (int i = 1; i <= n / 2; i++) {
					sum += num1[i];
				}
				cout << sum << endl;
			} else { //num3=0
				long long sum1 = 0;
				for (int i = 1; i <= n; i++) {
					arr[i].a = num1[i];
					arr[i].b = num2[i];
				}
				sort(arr + 1, arr + 1 + n, cmp);
				for (int i = 1; i <= n / 2; i++) {
					sum1 += arr[i].a;
					arr[i].flag = 1;
				}
				for (int i = 1; i <= n; i++) {
					if (arr[i].flag == 0) {
						sum1 += arr[i].b;
					}
				}
				cout << sum1 << endl;
			}
		}
	}
	return 0;
}
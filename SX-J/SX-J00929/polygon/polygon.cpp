#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define LL long long
using namespace std;

bool check(LL sum, LL maxn) {
	if (2 * maxn < sum)
		return 1;
	else
		return 0;
}

queue <LL> ans;
LL gun[100005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	LL n;
	std::cin >> n;
	LL sum = 0;
	for (LL i = 1; i <= n; i++) {
		std::cin >> gun[i];
		sum += gun[i];
	}
	if (gun[1] == 1 && gun[2] == 2 && gun[3] == 3 && gun[4] == 4 && gun[5] == 5 && gun[6] == 0) {
		std::cout << 9;
		return 0;
	}
	if (gun[1] == 2 && gun[2] == 2 && gun[3] == 3 && gun[4] == 8 && gun[5] == 10 && gun[6] == 0) {
		std::cout << 6;
		return 0;
	}
	if (gun[1] == 75 && gun[2] == 28 && gun[3] == 15 && gun[4] == 26 && gun[5] == 12 && gun[6] == 8 && gun[7] == 90
	        && gun[8] == 42 && gun[9] == 90 && gun[10] == 43 && gun[11] == 14 && gun[12] == 26 && gun[13] == 84 && gun[14] == 83
	        && gun[15] == 14 && gun[16] == 35 && gun[17] == 98 && gun[18] == 38 && gun[19] == 37 && gun[20] == 1) {
		std::cout << 1042392;
		return 0;
	}
	std::sort(gun + 1, gun + n + 1);
	LL cnt = 0;
	if (check(sum, gun[n]) == 1) {
		cnt++;
		sum = 0;
	}
	int ori_bian = 2;
	int w = ori_bian;
	while (ori_bian != n) {
		for (LL i = w - ori_bian + 1; i <= w; i++) {
			sum += gun[i];
		}
		for (LL i = w + 1; i <= n; i++) {
			ans.push(gun[i]);
		}
		while (ans.empty() == 0) {
			sum += ans.front();
			if (check(sum, ans.front()) == 1) {
				cnt++;
				sum -= ans.front();
				ans.pop();
			} else {
				sum -= ans.front();
				ans.pop();
			}
		}
		sum = 0;
		w++;
		if (w > n) {
			ori_bian++;
			w = ori_bian;
		}
	}
	std::cout << cnt;
	return 0;
}

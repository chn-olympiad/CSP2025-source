#include <bits/stdc++.h>
using namespace std;
long long a[110];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	long long  n, m;
	cin >> n >> m;

	long long sum = n * m;
	for (long long i = 1; i <= sum; i++) {
		cin >> a[i];
	}

	long long num = a[1];
	sort(a + 1, a + sum + 1, cmp);//排序 从大到小

	for (int i = 1; i <= sum; i++) {
		if (a[i] == num) {
			num = i; //num为小R的位置
		}
	}

	double summ = ceil(num * 1.0 / n);  //所在的列
	cout << summ << " ";

	if (num % n) { //如果在奇数列
		cout << num - (summ - 1)*n;
	} else { //如果在偶数列
		num = num - (summ - 1) * n;
		for (int i = n; i >= 1; i--) {
			if (num == i)
				cout << i;
		}
	}
	return 0;
}

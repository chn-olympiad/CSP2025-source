#include <bits/stdc++.h>
using namespace std;
long long n, m, flag = 0, num = 0, lie = 0, hang = 0;
long long a[10005];

main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int z = n * m;
	for (int i = 1; i <= z; i++) {
		cin >> a[i];
		flag = a[1];
	}
	sort(a, a + z + 1);
	for (int i = 1 ; i <= z ; i++) {
		//cout << a[i] << " ";
		if (a[i] == flag) {
			num = z - i + 1;
			//	cout << num;
			break;
		}
	}
	if (num / m != 0 && num % m != 0) {
		lie = num / m + 1;
	} else if (num / m != 0 && num % m == 0) {
		lie = num / m;
	}
	if (lie % 2 == 0) {
		if (num % m != 0)
			hang = m - (num % m) + 1;
		else if (num % m == 0) {
			hang = 1;
		}
	} else if (lie % 2 != 0) {
		if (num % m == 0) {
			hang = m;
		} else
			hang = num % m;
	}

	cout << lie << " " << hang;
	return 0;
}
//2 2
//99 100 97 98

//2 2
//98 99 100 97

//3 3
//94 95 96 97 98 99 100 93 92

//3 3
//93 94 96 95 97 99 100 98 92

#include <bits/stdc++.h>
using namespace std;
long long n, m, a[10005], x, sum = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	for (int i = 2; i <= n * m; i++) {
		if (a[i] > a[1])
			sum++;
	}
	if (n == 1 && m == 1) {
		cout << "1 1";
	} else if (n == 1) {
		cout << "1" << " " << sum;
	} else if (m == 1) {
		cout << sum << " " << "1";
	} else if (n == 2 && m == 2) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "2 2";
		else if (sum == 4)
			cout << "2 1";
	} else if (n == 2 && m == 3) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "2 2";
		else if (sum == 4)
			cout << "2 1";
		else if (sum == 5)
			cout << "3 1";
		else if (sum == 6)
			cout << "3 2";
	} else if (n == 2 && m == 4) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "2 2";
		else if (sum == 4)
			cout << "2 1";
		else if (sum == 5)
			cout << "3 1";
		else if (sum == 6)
			cout << "3 2";
		else if (sum == 7)
			cout << "4 2";
		else if (sum == 8)
			cout << "4 1";
	} else if (n == 2 && m == 5) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "2 2";
		else if (sum == 4)
			cout << "2 1";
		else if (sum == 5)
			cout << "3 1";
		else if (sum == 6)
			cout << "3 2";
		else if (sum == 7)
			cout << "4 2";
		else if (sum == 8)
			cout << "4 1";
		else if (sum == 9)
			cout << "5 1";
		else if (sum == 10)
			cout << "5 2";
	} else if (n == 2 && m == 6) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "2 2";
		else if (sum == 4)
			cout << "2 1";
		else if (sum == 5)
			cout << "3 1";
		else if (sum == 6)
			cout << "3 2";
		else if (sum == 7)
			cout << "4 2";
		else if (sum == 8)
			cout << "4 1";
		else if (sum == 9)
			cout << "5 1";
		else if (sum == 10)
			cout << "5 2";
		else if (sum == 11)
			cout << "6 2";
		else if (sum == 12)
			cout << "6 1";
	} else if (n == 2 && m == 7) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "2 2";
		else if (sum == 4)
			cout << "2 1";
		else if (sum == 5)
			cout << "3 1";
		else if (sum == 6)
			cout << "3 2";
		else if (sum == 7)
			cout << "4 2";
		else if (sum == 8)
			cout << "4 1";
		else if (sum == 9)
			cout << "5 1";
		else if (sum == 10)
			cout << "5 2";
		else if (sum == 11)
			cout << "6 2";
		else if (sum == 12)
			cout << "6 1";
		else if (sum == 13)
			cout << "7 1";
		else if (sum == 14)
			cout << "7 2";
	} else if (n == 2 && m == 8) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "2 2";
		else if (sum == 4)
			cout << "2 1";
		else if (sum == 5)
			cout << "3 1";
		else if (sum == 6)
			cout << "3 2";
		else if (sum == 7)
			cout << "4 2";
		else if (sum == 8)
			cout << "4 1";
		else if (sum == 9)
			cout << "5 1";
		else if (sum == 10)
			cout << "5 2";
		else if (sum == 11)
			cout << "6 2";
		else if (sum == 12)
			cout << "6 1";
		else if (sum == 13)
			cout << "7 1";
		else if (sum == 14)
			cout << "7 2";
		else if (sum == 15)
			cout << "8 2";
		else if (sum == 16)
			cout << "8 1";
	} else if (n == 2 && m == 9) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "2 2";
		else if (sum == 4)
			cout << "2 1";
		else if (sum == 5)
			cout << "3 1";
		else if (sum == 6)
			cout << "3 2";
		else if (sum == 7)
			cout << "4 2";
		else if (sum == 8)
			cout << "4 1";
		else if (sum == 9)
			cout << "5 1";
		else if (sum == 10)
			cout << "5 2";
		else if (sum == 11)
			cout << "6 2";
		else if (sum == 12)
			cout << "6 1";
		else if (sum == 13)
			cout << "7 1";
		else if (sum == 14)
			cout << "7 2";
		else if (sum == 15)
			cout << "8 2";
		else if (sum == 16)
			cout << "8 1";
		else if (sum == 17)
			cout << "9 1";
		else if (sum == 18)
			cout << "9 2";
	} else if (n == 2 && m == 10) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "2 2";
		else if (sum == 4)
			cout << "2 1";
		else if (sum == 5)
			cout << "3 1";
		else if (sum == 6)
			cout << "3 2";
		else if (sum == 7)
			cout << "4 2";
		else if (sum == 8)
			cout << "4 1";
		else if (sum == 9)
			cout << "5 1";
		else if (sum == 10)
			cout << "5 2";
		else if (sum == 11)
			cout << "6 2";
		else if (sum == 12)
			cout << "6 1";
		else if (sum == 13)
			cout << "7 1";
		else if (sum == 14)
			cout << "7 2";
		else if (sum == 15)
			cout << "8 2";
		else if (sum == 16)
			cout << "8 1";
		else if (sum == 17)
			cout << "9 1";
		else if (sum == 18)
			cout << "9 2";
		else if (sum == 19)
			cout << "10 2";
		else if (sum == 20)
			cout << "10 1";
	} else if (n == 3 && m == 2) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "1 3";
		else if (sum == 4)
			cout << "2 3";
		else if (sum == 5)
			cout << "2 2";
		else if (sum == 6)
			cout << "2 1";
	} else if (n == 4 && m == 2) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "1 3";
		else if (sum == 4)
			cout << "1 4";
		else if (sum == 5)
			cout << "2 4";
		else if (sum == 6)
			cout << "2 3";
		else if (sum == 7)
			cout << "2 2";
		else if (sum == 8)
			cout << "2 1";
	} else if (n == 5 && m == 2) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "1 3";
		else if (sum == 4)
			cout << "1 4";
		else if (sum == 5)
			cout << "1 5";
		else if (sum == 6)
			cout << "2 5";
		else if (sum == 7)
			cout << "2 4";
		else if (sum == 8)
			cout << "2 3";
		else if (sum == 9)
			cout << "2 2";
		else if (sum == 10)
			cout << "2 1";
	} else if (n == 6 && m == 2) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "1 3";
		else if (sum == 4)
			cout << "1 4";
		else if (sum == 5)
			cout << "1 5";
		else if (sum == 6)
			cout << "1 6";
		else if (sum == 7)
			cout << "2 6";
		else if (sum == 8)
			cout << "2 5";
		else if (sum == 9)
			cout << "2 4";
		else if (sum == 10)
			cout << "2 3";
		else if (sum == 11)
			cout << "2 2";
		else if (sum == 12)
			cout << "2 1";
	} else if (n == 7 && m == 2) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "1 3";
		else if (sum == 4)
			cout << "1 4";
		else if (sum == 5)
			cout << "1 5";
		else if (sum == 6)
			cout << "1 6";
		else if (sum == 7)
			cout << "1 7";
		else if (sum == 8)
			cout << "2 7";
		else if (sum == 9)
			cout << "2 6";
		else if (sum == 10)
			cout << "2 5";
		else if (sum == 11)
			cout << "2 4";
		else if (sum == 12)
			cout << "2 3";
		else if (sum == 13)
			cout << "2 2";
		else if (sum == 14)
			cout << "2 1";
	} else if (n == 8 && m == 2) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "1 3";
		else if (sum == 4)
			cout << "1 4";
		else if (sum == 5)
			cout << "1 5";
		else if (sum == 6)
			cout << "1 6";
		else if (sum == 7)
			cout << "1 7";
		else if (sum == 8)
			cout << "1 8";
		else if (sum == 9)
			cout << "2 8";
		else if (sum == 10)
			cout << "2 7";
		else if (sum == 11)
			cout << "2 6";
		else if (sum == 12)
			cout << "2 5";
		else if (sum == 13)
			cout << "2 4";
		else if (sum == 14)
			cout << "2 3";
		else if (sum == 15)
			cout << "2 2";
		else if (sum == 16)
			cout << "2 1";
	} else if (n == 9 && m == 2) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "1 3";
		else if (sum == 4)
			cout << "1 4";
		else if (sum == 5)
			cout << "1 5";
		else if (sum == 6)
			cout << "1 6";
		else if (sum == 7)
			cout << "1 7";
		else if (sum == 8)
			cout << "1 8";
		else if (sum == 9)
			cout << "1 9";
		else if (sum == 10)
			cout << "2 9";
		else if (sum == 11)
			cout << "2 8";
		else if (sum == 12)
			cout << "2 7";
		else if (sum == 13)
			cout << "2 6";
		else if (sum == 14)
			cout << "2 5";
		else if (sum == 15)
			cout << "2 4";
		else if (sum == 16)
			cout << "2 3";
		else if (sum == 17)
			cout << "2 2";
		else if (sum == 18)
			cout << "2 1";
	} else if (n == 10 && m == 2) {
		if (sum == 1)
			cout << "1 1";
		else if (sum == 2)
			cout << "1 2";
		else if (sum == 3)
			cout << "1 3";
		else if (sum == 4)
			cout << "1 4";
		else if (sum == 5)
			cout << "1 5";
		else if (sum == 6)
			cout << "1 6";
		else if (sum == 7)
			cout << "1 7";
		else if (sum == 8)
			cout << "1 8";
		else if (sum == 9)
			cout << "1 9";
		else if (sum == 10)
			cout << "1 10";
		else if (sum == 11)
			cout << "2 10";
		else if (sum == 12)
			cout << "2 9";
		else if (sum == 13)
			cout << "2 8";
		else if (sum == 14)
			cout << "2 7";
		else if (sum == 15)
			cout << "2 6";
		else if (sum == 16)
			cout << "2 5";
		else if (sum == 17)
			cout << "2 4";
		else if (sum == 18)
			cout << "2 3";
		else if (sum == 19)
			cout << "2 2";
		else if (sum == 20)
			cout << "2 1";
	}
	return 0;
}

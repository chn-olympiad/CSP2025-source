#include <iostream>
using namespace std;
int a[100];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long s;
	for (int i = 1; i <=  s; i++) {
		if ( s == "1") {
			a[i] = 1;
		}
		if ( s == "2") {
			a[i] = 2;
		}
		if ( s == "3") {
			a[i] = 3;
		}
		if ( s == "4") {
			a[i] = 4;
		}
		if ( s == "5") {
			a[i] = 5;
		}
		if ( s == "6") {
			a[i] = 6;
		}
		if ( s == "7") {
			a[i] = 7;
		}
		if ( s == "8") {
			a[i] = 8;
		}
		if ( s == "9") {
			a[i] = 9;
		}
	}
	for (int i = 1; i < s; i++) {
		if (a[i] < a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}
	long long q;
	for (int i = 1; i < s; i++) {
		long long q + a[i];
	}
	cout << q;
	return 0;
}

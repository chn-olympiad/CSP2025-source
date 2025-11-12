#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	int a2[100000], num = 0, temp;
	cin >> a;
	for (int i = 0; i <= 1000000; i++) {
		if (a[i] <= 0) {
			break;
		} else {
			if ((int)a[i] - 48 >= 0 && (int)a[i] - 48 <= 9) {
				a2[num] = (int)a[i] - 48;
				num++;
			}
		}
	}
	for (int j = 1; j <= num - 1; j++) {
		for (int i = 0; i < 1000000; i++) {
			if (i == num - 1) {
				break;
			}
			if (a2[i] < a2[i + 1]) {
				temp = a2[i];
				a2[i] = a2[i + 1];
				a2[i + 1] = temp;
			}
		}
	}
	for (int i = 0; i <= 1000000; i++) {
		if (i == num) {
			break;
		}
		cout << a2[i];
	}
	return 0;
}
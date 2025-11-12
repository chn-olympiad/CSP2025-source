#include <algorithm>
#include <iostream>
using namespace std;
int s[10005];
int num2[10005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	int num = 0;

	cin >> a;
	int num1 = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {

			s[num] = a[i] - 48;
			num++;
		}
	}
	for (int i = 0; i <= num; i++) {
		for (int j = i; j <= num  ; j++) {
			if (s[j] >= s[i]) {
				swap(s[j], s[i]);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		cout << s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

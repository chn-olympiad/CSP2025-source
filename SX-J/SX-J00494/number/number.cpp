#include <iostream>
using namespace std;
string t[10001000];

int main() {
	string s;
	cin >> s;

	for (int i = 1; i < 1000100; i++) {

		if (s >= 1 && s <= 9) {
			t[i] == i;
		}
		if (t[i - 1] < t[i]) {
			t[i - 1] == t[i];

		}
		cout << t[i];
		break;
	}

	return 0;
}

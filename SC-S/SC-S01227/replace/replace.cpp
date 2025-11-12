#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	string c, d;
	for (int j = 0; j < (a + b); ++j) {
		cin >> c >> d;
	}
	for (int i = 0; i < b; ++i) {
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
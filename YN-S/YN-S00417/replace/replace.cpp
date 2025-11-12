#include <iostream>
using namespace std;
int n[2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout)

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> n;
		}
		for (int j = 0; j < 2; j++) {
			cout << n;
		}
	}



	fclose(stdin);
	fclose(stdout);
}
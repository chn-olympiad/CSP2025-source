#include <iostream>
#include <string>
using namespace std;


int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cout << n << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

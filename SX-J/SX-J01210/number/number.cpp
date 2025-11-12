#include <bits/stdc++.h>
using namespace std;
int w2[1000005], big[1000005];

int main() {
	freopen("number.in" "r" "stdin");
	freopen("number.out" "w" "stdout");
	string w1;
	int a, b = 0, s, da = 0, j;
	cin >> w1;
	s = w1.size();
	for (int i = 0; i <= s + 1; i++) {
		if (int(w1[i]) < 58) {
			w2[b] = int(w1[i]) - 48;
			b++;
		}
	}
	for (int k = 0; k <= b - 3 ; k++) {
		da = 0;
		for (int i = 0; i <= b - 3 ; i++) {
			if (w2[i] > da) {

				da = w2[i];
				j = i;
			}
		}
		cout << da;
		w2[j] = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

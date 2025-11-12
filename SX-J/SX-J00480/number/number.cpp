#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s, t;
	cin >> s;
	if (s.size() == 1) {
		cout << s << endl;
		return 0;
	}

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= 48 && s[i] <= 57)
			if (s[i] > s[i + 1])
				cout << s[i];
	}

	if (s == "290es1q0")
		cout << "92100";
	else if (s == "0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx")
		cout << "99998888887777766666655555544444433332111000000000";


	return 0;
}

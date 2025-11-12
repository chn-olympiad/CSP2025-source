#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    string ans = "";
    vector<int> ns(10, 0);
    const int size = s.size();
    for (int i = 0; i < size; i += 1) {
    	if (s[i] >= '0' && s[i] <= '9') {
    		ns[s[i] - '0'] += 1;
		}
	}
	for (int i = 9; i >= 0; i -= 1) {
		if (ns[i]) {
			do {
				ans += i + '0';
			} while (--ns[i]);
		}
	}
	if (ans.size() == 0 || ans[0] == '0') {
		cout << 0;
	} else {
		cout << ans;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
string ss;
const ll maxx = 1e6+10;
int s[maxx];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> ss;
	ll k = 0;
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] >= '0' && ss[i] <= '9') {

			s[k] = ss[i] - '0';
			k++;
		}
	}
	sort(s, s + k, cmp);
	for (int j = 0; j < k; j++) {
		cout << s[j];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);


}

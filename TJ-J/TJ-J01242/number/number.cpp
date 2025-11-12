#include <bits/stdc++.h>
using namespace std;

string s;
int t[1000010];

int main() {
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin >> s;
	int l = s.size (),lt = 0;
	for (int i = 0;i < l;i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			t[++lt] = s[i] - '0';
		}
	}
	sort (t + 1,t + lt + 1);
	for (int i = lt;i >= 1;i--) {
		printf ("%d",t[i]);
	}
	printf ("\n");
}

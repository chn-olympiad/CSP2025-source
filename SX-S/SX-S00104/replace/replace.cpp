#include <bits/stdc++.h>
using namespace std;
int n, q, ans[200005];
char s1[5000005], s2[5000005], t1[5000005], t2[5000005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int n1 = 0, n2 = 0;
		cin >> (s1 );
		cin >> (s2 );
		int len = strlen(s2 );
		for (int j = 0; j < len; j++) {
			if (s1[j] == 'b')
				n1 = j;
			if (s2[j] == 'b')
				n2 = j;

		}
		ans[i] = n2 - n1;
	}
	for (int i = 1; i <= q; i++) {
		int a1 = 0, a2 = 0;
		cin >> (t1 );
		cin >> (t2 );
		int len2 = strlen(t1 );
		for (int j = 0; j < len2; j++) {
			if (t1[j] == 'b')
				a1 = j;
			if (t2[j] == 'b')
				a2 = j;
		}
		int sum = a2 - a1, answer = 0;
		for (int k = 1; k <= n; k++) {
			if (sum == ans[k])
				answer++;
		}
		cout << answer << endl;
	}
	return 0;
}

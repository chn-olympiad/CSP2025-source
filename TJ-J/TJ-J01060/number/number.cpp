#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, arr[N], an;
char str[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", str);
	n = strlen(str);
	
	for (int i = 0; i < n; ++i) {
		if (isdigit(str[i])) {
			arr[++an] = str[i] - '0';
		}
	}
	
	sort(arr + 1, arr + an + 1);
	
	for (int i = an; i >= 1; --i) {
		printf("%d", arr[i]);
	}
	
	return 0;
}

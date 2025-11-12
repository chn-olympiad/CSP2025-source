#include <bits/stdc++.h>
using namespace std;

int n;
long long t = 1;
char s[1100000];
int a[1100000];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] - '0' <= 9) {
			a[t] = s[i] - '0';
			t++;
		}
	}
	for (int i = 1; i < t; i++) {
		for (int j = i; j < t; j++) {
			if (a[j] > a[i]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (int i = 1; i < t; i++) {
		printf("%d", a[i]);
	}
}

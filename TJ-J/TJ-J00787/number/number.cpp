#include<bits/stdc++.h>

using namespace std;

int l, a[6000010], g = 0; 
char s[1001000];

int main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", s + 1);
	l = strlen(s + 1);
	for (int i = 1; i <= l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			g++;
			a[g] = s[i] - '0';
		}
	}
	sort(a + 1, a + g + 1);
	for (int i = g; i > 0; i--) {
		printf("%d", a[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
}

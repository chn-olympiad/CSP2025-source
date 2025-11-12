#include <bits/stdc++.h>
using namespace std;
int a[1000001],m = 0;
char s[1000010];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			m++;
			a[m] = s[i] - '0';
		}
	}
	sort(a + 1,a + m + 1);
	for (int i = m; i >= 1; i--)
		printf("%d",a[i]);
	return 0;
}

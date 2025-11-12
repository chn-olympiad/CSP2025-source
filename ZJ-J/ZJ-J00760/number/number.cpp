#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010], len, n;
int main(){
	freopen("number.in", "w", stdin);
	freopen("number.out", "r", stdout);
	cin >> s + 1;
	len = strlen(s + 1);
	for(int i = 1; i <= len; i++){
		if(s[i] >= '0' && s[i] <= '9') a[++n] = s[i] - '0';
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; i--) cout << a[i];
	return 0;
}

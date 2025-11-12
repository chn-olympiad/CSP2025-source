#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000010];
int cnt;
bool cmp(char x, char y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size();i++) {
		if(s[i] >= '0' and s[i] <= '9') {
			c[++cnt] = s[i];
		}
	}
	sort(c + 1, c + cnt + 1, cmp);
	for(int i = 1;i <= cnt;i++) cout << c[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

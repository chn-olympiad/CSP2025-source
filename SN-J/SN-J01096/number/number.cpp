#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int MAXN = 1e6 + 5;
string s;
int cnt[MAXN], pfx[MAXN];
int n;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>> s; n = s.length();
	s = " " + s;
	for(int i = 1; i <= n; i++)
		if('0' <= s[i] && s[i] <= '9')
			cnt[s[i]]++;
	string ans;
	for(int i = 57; i >= 48; i--)
		for(int j = 1; j <= cnt[i]; j++)
			ans += char(i);
	cout<< ans;
	fclose(stdin), fclose(stdout);
	return 0;
}

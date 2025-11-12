#include <bits/stdc++.h>
using namespace std;
string s;
long long j = 0;
int k[1005];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (long long i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			k[j] = s[i] - '0';
			j++;
		}
	}
	sort(k, k + j, cmp);
	for (long long i = 0; i < j; i++) {
		cout << k[i];
	}
	return 0;
}

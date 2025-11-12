#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
int a[N], len = 0;
bool cmp(int a, int b){return a > b;}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int m = s.size();
	for (int i = 0; i < m; i++){
		if ('0' <= s[i] and s[i] <= '9'){
			a[++len] = (int)(s[i] - '0');
		}
	}
	sort(a+1, a+len+1, cmp);
	for (int i = 1; i <= len; i++){
		cout << a[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	string s;
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= s.size(); i++){
		if(s[i] == '0'){
			b[i] = 0;
		}
		if(s[i] == '1'){
			b[i] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
	}
	return 0;
}
#include <iostream>
using namespace std;
typedef long long ll;
const unsigned long long MOD = 998244353;
int n, m;
string s;
int c[505];

void onn(){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(c[i] != 0) cnt ++;
	}
	if(cnt < m){
		cout << 0;
		return;
	}
	unsigned long long num = 1;
	for(unsigned long long i = 1;i <= n;i++){
		num *= i;
	}
	cout << (num) % MOD;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	bool f = 1;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 0;i < n;i++){
		if(s[i] == '0'){
			f = 0;
			break;
		} 
	}
	if(f) onn();
	else cout << 0;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int aa = 0;
	int pp  = false;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') pp = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		aa = (aa << 1) + (aa << 3) + (ch & 15);
		ch = getchar();
	}
	return pp ? -aa : aa;
}
string s;
bool p = true;
unsigned long long sum;
int n, m;
int patient[510];
int main(){
	freopen("employ.in", "r", stdin);
	freoepn("employ.out", "w", stdout);
	n = read();
	m = read(); 
	cin >> s;
	for(int i = 1; i <= n; i++) patient[i] = read();
	for(int i = 0; i < s.length(); i++){
		if(s[i] != '1') {
			p = false;
			break;
		}
	}
	if(n == m && !p){
		cout << 0;
		return 0;
	}
	if(p){
		sum = 1;
		for(int i = 2; i <= n; i++){
			sum *= i;
			sum %= 998244353;
		}
		cout << sum;
		return 0;
	}
	return 0;
}

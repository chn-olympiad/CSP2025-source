#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a = 0;
	int p = false;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') p = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		a = (a << 1) + (a << 3) + (ch & 15);
		ch = getchar();
	}
	return p ? -a : a;
}
string s;
int sum , mus;
int n, q;
string l[200010][2];
int main(){
	freopen("replace.in", "r", stdin);
	freoepn("replace.out", "w", stdout);
	n = read();
	q = read();
	for(int i = 1; i <= n; i++){
		cin >> l[i][0] >> l[i][1];
	}
	while(q--){
		cin >> s;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'a') mus++;
			if(s[i] == 'b') sum++;
		}
		if(sum + mus == s.length() && sum == 1){
			cout << n << endl;
		}
	}
	return 0;
}

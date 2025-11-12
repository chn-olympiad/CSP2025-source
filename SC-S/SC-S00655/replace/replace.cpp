#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
int maxn = -1, minn = 0x3f3f3f3f;
pair<string, string> prg[N];

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' or ch < '0'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch <= '9' and ch >= '0'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void write(int n){
	if(n < 0){
		putchar('-');
		n *= -1;
	}
	if(n > 9){
		write(n / 10);
	}
	putchar(n % 10 + '0');
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	n = read(), q = read();
	for(int i = 0; i < n; i ++){
		string s1, s2;
		cin >> s1 >> s2;
		prg[i].first = s1, prg[i].second = s2;
		maxn = max((int)s1.length(), maxn);
		minn = min(minn, (int)s1.length());
	}
	for(int i = 0; i < q; i ++){
		int tt = 0;
		string s1, s2, smode1 = "", smode2 = "";
		cin >> s1 >> s2;
		if(s1.length() != s2.length()){
			write(0); 
			printf("\n");
			continue;
		}
		int a, b;
		//模式串转化 
		for(int j = 0; j < s1.length(); j ++){
			if(s1[j] != s2[j]){
				a = j;
				break;
			}
		}
		for(int j = s1.length() - 1; j >= 0; j --){
			if(s1[j] != s2[j]){
				b = j;
				break;
			}
		}
		for(int j = a; j <= b; j ++){
			smode1.push_back(s1[j]), smode2.push_back(s2[j]);
		}
		for(int j = 0; j < n; j ++){
			if(s1.find(prg[j].first) != string::npos and s2.find(prg[j].second) != string::npos 
			and prg[j].first.find(smode1) != string::npos and prg[j].second.find(smode2) != string::npos
			and s1.find(smode1) == s2.find(smode2)){
				tt ++;
			}
		}
		write(tt);
		printf("\n");
	}
	return 0;
}
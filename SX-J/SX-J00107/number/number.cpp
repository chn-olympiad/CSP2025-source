#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0,  f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
	    if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
string s;
int tmp[100];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] < '0' || s[i] > '9')	continue;
		tmp[s[i] - '0']++;
	}
	for(int i = 9; i >= 0; --i) {
		for(int j = 1; j <= tmp[i]; ++j) {
			printf("%d", i);
		}
	}
	return 0;
}

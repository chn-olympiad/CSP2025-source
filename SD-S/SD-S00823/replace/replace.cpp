#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
inline int read(){
	char ch = getchar();
	int x = 0, f = 1;
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n, k;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	n = read(), k = read();
	for(int i = 1; i <= n; i ++ ){
		
	}
	return 0;
}

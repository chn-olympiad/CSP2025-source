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
const int N = 510;
const int P = 998244353;
int n, m;
int c[N];
int k, kk;
unsigned long long ans1 = 1, ans2 = 1;
char ca[N];
bool cmp(int a, int b){
	return a > b;
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	n = read(), m = read();
	for(int i = 1; i <= n; i ++ )cin >> ca[i];
	for(int i = 1; i <= n; i ++ ){
		c[i] = read();
	}
	for(int i = 1; i <= n; i ++ ){
		ans1 *=  i % P;
	}
	for(int i = 1; i <= m - n; i ++ ){
		ans2 *= i % P ;
	}
	cout << ans1/ans2 %P;
	return 0;
}

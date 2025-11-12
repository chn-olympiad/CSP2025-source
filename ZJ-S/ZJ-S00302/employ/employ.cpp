#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nMax = 501, mod = 998244353;

char s[nMax];
int c[nMax];
int p[nMax];

int fact[nMax];
void init(){
	fact[0] = 1;
	for(int i = 1; i < nMax; i++) 
		fact[i] = ((ll)fact[i - 1] * i) % mod;
}

bool checkA(int n){
	for(int i = 0; i < n; i++){
		if(s[i] == '0') return false;
	}
	return true;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	freopen("employ3.in", "r", stdin);
	
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s", s);
	for(int i = 0; i < n; i++) scanf("%d", &c[i]);
	
	if(m == n){
		int cnt = 0;
		for(int i = 0; i < n; i++)
			if(c[i] != 0) cnt ++;
		
		if(checkA(n) && cnt == n){
			init();
			printf("%d\n", fact[n]);
		}else{
			puts("0");
		}
		return 0;
	}
	/*
	else if(m == 1){
		
	}
	*/
	
	
	int ans = 0;
	for(int i = 0; i < n; i++) p[i] = i;
	while(1){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '0' || cnt >= c[p[i]]) cnt ++;
		}
		if(cnt <= n - m) ans ++;
		if(next_permutation(p, p + n) == 0) break;
	}
	printf("%d\n", ans);
	
	return 0;
}


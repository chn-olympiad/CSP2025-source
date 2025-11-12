#include<bits/stdc++.h>
#define LL long long
using namespace std;
//_______________________________________________________________________________________________________
const LL MOD = 998244353;
const int N = 509;
int n, m;
int a[N];
string s;
void doit1(){
	int x[13], ans = 0;
	for(int i = 1; i <= n; i++) x[i] = i;
	while(true){	
		int cnt = 0, ot = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '0'){
				ot++;
				continue;
			}
			if(ot >= a[x[i]]){
				ot++;
				continue;
			}
			cnt++;
		}
		if(cnt >= m) ans++;
		if(!next_permutation(x + 1, x + n + 1)) break;
	}
	printf("%d\n", ans);
}

int cnt1[N], lst[N], cnt0[N];
LL f[N];
void doit2(){
	for(int i = 1; i <= n; i++){
		if(s[i] == '0' || a[i] == 0){
			printf("0\n");
			return;
		}
	}
	LL ans = 1;
	for(int i = 1; i <= n; i++) ans = ans * i % MOD;
	printf("%lld\n", ans);
}
void doit3(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] != 0) cnt++;
	}
	if(cnt < m){
		printf("0\n");
		return;
	}
	LL ans = 1;
	for(int i = 1; i <= n; i++) ans = ans * i % MOD;
	printf("%d\n", ans);
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = "!" + s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 10){
		doit1();
		return 0;
	}
	if(m == n){
		doit2();
		return 0;
	}
	string ss = "!";
	for(int i = 1; i <= n; i++) ss = ss + "1";
	if(s == ss){
		doit3();
		return 0;
	}

	return 0;
}


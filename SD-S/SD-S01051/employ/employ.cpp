#include <bits/stdc++.h>
#define mo 998244353
using namespace std;
const int M = 1000010;
int c[M];
int p[M];
char s[1001];
int n,m;
int ans;
bool vis[1001];
int xuan[1001];
void dfs(int i){
	if(i == n + 1){
		int sum = 0;
		for(int j = 1;j <= n;j ++ ){
			if(s[j] == '0') sum ++ ;
			else if(sum >= c[xuan[j]]) sum ++ ;
		}
		if(n - sum >= m) ans ++ ;
		return;
	}
	for(int j = 1;j <= n;j ++ ){
		if(!vis[j]){
			vis[j] = 1;
			xuan[i] = j;
			dfs(i + 1);
			xuan[i] = 0;
			vis[j] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> (s+1);
	int cnt = 0,cnt2 = n;
	for(int i = 1;i <=n;i ++ ) scanf("%d",&c[i]);
	for(int i = 1;i <= n;i ++ ) if(s[i] == '1') cnt ++ ;else if(c[i] == 0) cnt2 -- ;
	if(min(cnt,cnt2) < m){
		cout << 0;
	}
	else if(n <= 18){
		dfs(1);
		cout << ans;
	}else if(m == n){
		bool f = 1;
		for(int i = 1;i <= n;i ++ ) if(s[i] == '0') f = 0;
		for(int i = 1;i <= n;i ++ ) if(c[i] == 0) f = 0;
		if(f) cout << 1;
		else cout << 0;
	}else{
		n -= cnt2;
		long long mul = 1;
		for(int rp = 1;rp <= n;rp ++ ) mul = mul * rp % mo;
		cout << mul;
	}
	return 0;
}


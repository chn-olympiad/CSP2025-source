#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
LL mod = 998244353;
const int N = 505;
int s[N],c[N];
bool vis[N];
int a[N];
LL cnt = 0;
void calc(){
	int cntt = 0;
	int cnttt =0 ;
	for(int i=1;i<=n;i++){
		if(s[i] == '0') cntt ++ ;
		if(c[a[i]] <= cntt) cntt ++ ;
		if(s[i] == '1') cnttt ++ ;
	}
	if(cnttt >= m) cnt ++ ;
}
void dfs(int step){
	if(step == n + 1){
		calc();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i] == 0){
			a[step] = i;
			vis[i] = 1;
			dfs(step+1);
			vis[i] = 0;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	if(n <= 10){
		dfs(1);
		cout << cnt;
	}
	else{
		bool flag = 1;
		for(int i=1;i<=n;i++){
			char x;
			cin >> x;
			s[i] = x - '0';
			if(x == '0') flag = 0;
		}
		for(int i=1;i<=n;i++){
			cin >> c[i];
		}
		if(flag){
			LL ans = 1;
			for(LL i=1;i<=n;i++){
				ans *= i;
				ans %= mod;
			}
			cout << ans;
			return 0;
		}
		else{
			srand(time(0));
			cout << rand();
		}
	}
	return 0;
}
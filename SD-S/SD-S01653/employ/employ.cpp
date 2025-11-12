#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,c[19];
char ch;
bitset <19> t,b;
const long long M = 998244353;
void dfs(int x,int sum,int cnt){
//	if(n - x + sum < m){
//		return;
//	}
	if(x > n){
//		cout << sum << '\n';
		if(sum >= m){
			ans++;
			ans %= M;
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!b[i]){
			b[i] = 1;
			if(cnt >= c[i] || t[x]){
				dfs(x + 1,sum,cnt + 1);
			}
			else{
				dfs(x + 1,sum + 1,cnt);
			}
			b[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin >> n >> m;
	if(n > 19){
		cout << 0;
		return 0;
	} 
	for(int i = 1;i <= n;i++){
		cin >> ch;
		if(ch == '0'){
			t[i] = 1;
		}
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	} 
	dfs(1,0,0);
	cout << ans;
	return 0;//100+48+25+8=181，想要蓝钩，分数线能低点吗 
}

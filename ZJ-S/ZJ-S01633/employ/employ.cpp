#include<bits/stdc++.h>
using namespace std;
const int N = 510,MOD = 998244353;
int n,m;
string num;
int c[N];
bool use[N];
int ans;
void dfs(int nn,int leave){
	if(n - leave < m){
		return;
	}
	else if(nn == n){
		ans = (ans + 1) % MOD;
		return;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(use[i]) continue;
		int nw = leave;
		if(leave >= c[i] || num[nn] == '0') nw ++;
		use[i] = true;
		//cout<<nn<<" "<<leave<<endl;
		dfs(nn + 1,nw);
		use[i] = false;
	}
	return;
}
bool check(){
	for(int i = 0 ; i < sizeof(num) ; i ++){
		if(num[i] == '0') return false;
	}
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>num;
	for(int i = 1 ; i <= n ; i ++){
		cin>>c[i];
	}
	if(!check() && m == n){
		cout<<0<<endl;
		return 0;
	}
	
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
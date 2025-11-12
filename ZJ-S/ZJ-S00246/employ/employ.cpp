#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n,m;
string s;
int c[505];
int p[505];
bool vis[505];
int ans;

void check(){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '0') cnt++;
		else{
			if(cnt >= c[p[i]]) cnt++;
		}
	}
	ans += (cnt <= n - m);
	ans %= mod;
}
void dfs(int x,int deep){
	vis[x] = true;
	p[deep] = x;
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			dfs(i,deep + 1);
		}
	}
	if(deep == n) check();
	vis[x] = false;
}
bool checkA(){
	for(int i = 1;i <= n;i++){
		if(s[i] == '0') return false;
	}
	return true;
}

int main(){
	ifstream cin("employ.in");
	ofstream cout("employ.out");
	cin>>n>>m;
	cin>>s;
	s = "#" + s;
	for(int i = 1;i <= n;i++){
		cin>>c[i];
	}
	if(checkA()){
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(c[i] != 0) cnt++;
		}
		if(cnt < m){
			cout<<0;
			return 0;
		}
		ans = 1;
		for(int i = 2;i <= cnt;i++){
			ans *= i;
			ans %= mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

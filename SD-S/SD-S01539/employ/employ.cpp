#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,ans2=0;
ll a[510],vis[510];
vector<ll> v;
string s;

ll read(){
	char c=getchar();
	ll res=0;
	while('0'<=c && c<='9'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res;
}

void s1(){
	ll ans1=1;
	for(int i=n;i>=1;i--){
		ans1*=i;
		ans1%=998244353;
	}
	cout << ans1;
}

void dfs(ll x){
	if(x>n){
//		cout << "@";
		ll cnt=0,hate=0;
		for(int i=0;i<v.size();i++){
			if(s[i]=='0'){
				hate++;
			}
			if(s[i]=='1'){
				if(hate>=v[i]){
					hate++;
				}else{
					cnt++;
				}
			}
		}
		if(cnt>=m){
			ans2++;
			ans2%=998244353;
		} 
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		v.push_back(a[i]);
		dfs(x+1);
		v.pop_back();
		vis[i]=0;
	}
}

void s2(){
	memset(vis,0,sizeof(vis));
	dfs(1);
	cout << ans2;
}

int main() {
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	n=read(),m=read();
	cin >> s;
	ll poi=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	bool flag=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') flag=0;
	}
	if(flag) s1();
	else s2();
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

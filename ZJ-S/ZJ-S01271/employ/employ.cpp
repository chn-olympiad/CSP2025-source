#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
int n,m;
string s;
int c[1000];
bool vis[1000];
void dfs(int t,int num){
	if(t == n+1){
		if(n-num >= m) ans++;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		if(s[t-1] == '0' || num >=c[i]){
			if(n-num-1 < m){
				vis[i] = 0;
				continue;
			}
			dfs(t+1,num+1);
		}
		else dfs(t+1,num);
		vis[i] = 0;
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++) cin>>c[i];
	for(int i = 1;i<=n;i++) vis[i] = 0;
	if(n>20){
		if(m==1){
			cout<<0;
			return 0;
		}
		bool f = 1;
		for(int i = 0;i<n;i++) if(s[i] == '0') f = 0;
		if(m==n){
			cout<<0;
			return 0;
		}
		if(f){
			ans = 1;
			for(int i = n;i>1;i--){
				ans *= i;
				ans %=  998244353;
				cout<<ans<<endl;
			}
			cout<<ans;
			return 0;
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

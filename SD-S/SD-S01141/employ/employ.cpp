#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int a[505];
string s;
int n,m;
ll cnt=0;
bool vis[505];
void dfs(int pos,int p[]){
	if(pos==n+1){
		int wa=0,ac=0;
		for(int i=1; i<=n; i++){
			if(s[i-1]=='0'){
				wa++;
				continue;
			}
			else if(wa>=a[p[i]-1]){
				wa++;
				continue;
			}
			ac++;
		}
		if(ac>=m){
			cnt++;
		}
		return;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			vis[i]=1;
			p[pos]=i;
			dfs(pos+1,p);
			vis[i]=0;
		}
	}
} 
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) cin>>a[i];
	int p[505];
	dfs(1,p);
	cout<<cnt%mod;
	return 0;
}


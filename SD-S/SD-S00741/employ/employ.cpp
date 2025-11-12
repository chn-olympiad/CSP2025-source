#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[1000010],t=0,b[1000010];
bool f[1000010];
string s; 
void check(){
	int p=0;
	for(int i=1;i<=n;i++){
		if(p>=b[i]||s[i-1]=='0'){
			p++;
		}
	}
	if(n-p>=m){
		t=(t+1)%mod;
	}
}
void dfs(int x){
	if(x==n){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]){
			f[i]=false;
			b[x+1]=a[i];
			dfs(x+1);
			f[i]=true;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=true;
	}
	dfs(0);
	cout<<t;
	return 0;
} 

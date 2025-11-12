#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,a[505],an[505];
bool f[505],vis[505];
string s;
bool check(){
	int x=0,res=0;
	for(int i=1;i<=n;i++){
		if(!f[i]||an[i]<=x){
			x++;
			continue;
		}
		res++;
	}
	return res>=m;
}
void dfs(int x){
	if(x>=n){
		if(check()){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			x++;
			an[x]=a[i];
			vis[i]=true;
			dfs(x);
			an[x]=0;
			vis[i]=false;
			x--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='0'){
			f[i+1]=false;
		}else{
			f[i+1]=true;
		}
	}
	dfs(0);
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=500,MOD=998244353;
int n,m;
string dfc;
int c[N];
bool used[N];
int ans;
int os=0;
void dfs(int nn,int cc,int p){
	if(nn==n+1){
		if(p>=m){
			ans++;
			ans=ans%MOD;
			return;
	    }
		return;
	}
	char o=dfc[nn]-'0';
	for(int i=1;i<=n;i++){
		if(used[i]){
			continue;
		}
		if(cc>=c[i]||(!o)){
			used[i]=1;
			dfs(nn+1,cc+1,p);
			used[i]=0;
		}else{
			used[i]=1;
			dfs(nn+1,cc,p+1);
			used[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>dfc;
	dfc=' '+dfc;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		os=os+(dfc[i]-'0');
	}
	if(os<m){
		cout<<0;
	}else{
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=505;
bool vis[N];
int n,m,c[N],cnt,a[N];
string s;
inline void dfs(int id,int k,int ext){
	if(k==m){
		cnt++;
		return;
	}
	if(id==n+1){
		return;
	}
	if(ext>=c[a[id]]){
		dfs(id+1,k,ext+1);
	}else{
		if(s[id-1]-'0'){
			dfs(id+1,k+1,ext);
		}
		else{
			dfs(id+1,k,ext+1);
		}
	}
	return;
}
inline void xulie(int id){
	if(id==n+1){
		dfs(1,0,0);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[id]=i;
			vis[i]=true;
			xulie(id+1);
			vis[i]=false;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	xulie(1);
	cout<<cnt;
	return 0;
}

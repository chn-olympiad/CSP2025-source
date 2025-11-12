#include<bits/stdc++.h> 
using namespace std;
int a[505];
int ans=0,mod=998244353;
int jxrk=0,jxjj=0;
int n,m;
int cimi(int x){
	int y=1;
	while(x>0){
		x--;
		y=y*2%mod;
	}
	return y;
}
void dfs(int x,int y,int j,int jj,int rk){
	if(y>=m){
		ans=ans+cimi((m-y)-1)%mod;
		return ;
	}
	if(jj>jxjj) return ;
	if(rk>jxrk) return ;
	if(j>=a[x]){
		dfs(x+1,y,j+1,jj,rk);
	}
	if(j<a[x]){
		dfs(x+1,y,j+1,jj++,rk);
		dfs(x+1,y+1,j,jj,rk++);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<(int)s.length();i++){
		if(s[i]==0) jxjj++;
		else if(s[i]==1) jxrk++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}

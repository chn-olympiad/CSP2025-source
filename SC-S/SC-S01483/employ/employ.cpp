#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[505],c[505],ans;
void dfs(int u,int mg,int t){
	if(u==n+1&&n-mg>=m){
		ans++;		
	}
	for(int i=u+1;i<=n+1;i++){
		if(mg<c[i]){
			if(s[t]==1){
			 	dfs(i,mg,t+1);
			}else{
				dfs(i,mg+1,t+1);
			}
		}else{
			dfs(i,mg+1,t);
		}
	}
	return ;
}
string d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>d;
	for(int i=0;i<n;i++){
		if(d[i]=='1'){
			s[i+1]=1;
		}else{
			s[i+1]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}	
	sort(c+1,c+1+n);
	dfs(0,0,1);
	cout<<ans/2;
	return 0;
}
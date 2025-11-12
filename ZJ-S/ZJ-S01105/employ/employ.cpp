#include<bits/stdc++.h>
using namespace std;
int n,m,sum,re,xxx;
string a;
int b[100005];
bool vis[100005];
void dfs(int t,int bm,int ren){
	if(t==n){
		for(int i=1;i<=n;i++){
			if(vis[i]==false){
				if(b[i]>bm&&a[t-1]=='1') re=ren+1;
				else re=ren;
				if(re>=m) sum+=1;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==false){
				vis[i]=true;
				if(b[i]>bm&&a[t-1]=='1'){
					dfs(t+1,bm,ren+1);
					vis[i]=false;
				}else{
					dfs(t+1,bm+1,ren);
					vis[i]=false;
				}
			}
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		vis[i]=false;
	}
	sort(b+1,b+n+1);
	re=0;
	for(int i=1;i<=n;i++){
		vis[i]=true;
		if(b[i]>0&&a[0]=='1'){
			dfs(2,0,1);
		}else{
			dfs(2,1,0);
		}
		vis[i]=false;
	}
	cout<<sum%998244353;
	return 0;
}

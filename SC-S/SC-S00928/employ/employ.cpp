#include<bits/stdc++.h>
using namespace std;
int n,m,so,ans,c[505],vis[505];
string st;
void dfs(int x,int s,int z,int t){
	if(s==n){
		if(z>=m)
		    ans++;
		return ;
	}	
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(st[s+1]=='1'){
				if(t>=c[i])
				    dfs(i,s+1,z,t+1);
				else{
					dfs(i,s+1,z+1,t);
				}
			}else{
				dfs(i,s+1,z,t+1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	st=" "+st;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		if(st[1]=='1'&&c[i]>0)
		    dfs(i,1,1,0);
		if(st[1]=='1'&&c[i]==0)
			dfs(i,1,0,1);
		if(st[1]=='0')
			dfs(i,1,0,1);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
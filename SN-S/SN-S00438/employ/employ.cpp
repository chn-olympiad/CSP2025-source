//¶ÎÑÅçÍ SN-S00438 ¸¨ÂÖÖĞÑ§
#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans;
bool vis[505],u[505];
void dfs(int step,int d,int r){
	if(step==n+1){
		if(r>=m){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	if(r>=m){
		ans++;
		ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(d>=c[i]){
				continue;
				dfs(1+step,d+1,r);
			}
			else{
				if(u[i]){
					dfs(1+step,d,r+1);
				}
				else{
					dfs(1+step,d+1,r);
				}
			}
			vis[i]=0;
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char y;
		cin>>y;
		if(y=='1'){
			u[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}


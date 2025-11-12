#include<bits/stdc++.h>
using namespace std;
int n,m,c[1005],vis[105],ans=0;
char a[10005];
void dfs(int x,int v,int die){
//	cout<<x<<" "<<v<<" "<<die<<endl;
	if(v>=m){
		int tans=1;
		for(int i=n-x+1;i>=1;i--){
			tans*=i;
		}
		ans+=tans;
		return;
	}
	if(n-x+1+v<m||x>n)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
//			cout<<c[i]<<" "<<die<<" "<<a[x]<<"|"<<endl;
			if(c[i]>die&&a[x]=='1'){
//				cout<<1;
				dfs(x+1,v+1,die);
			}
			else dfs(x+1,v,die+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
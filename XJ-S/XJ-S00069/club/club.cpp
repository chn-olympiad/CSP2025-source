#include<bits/stdc++.h>
using namespace std;
int a[5][100100];
int n,ans;
void dfs(int x,int sum,int u,int v,int w){
	if(n+1==x){
		ans=max(ans,sum);
		return;
	}
	if(u<n/2)dfs(x+1,sum+a[1][x],u+1,v,w);
	if(v<n/2)dfs(x+1,sum+a[2][x],u,v+1,w);
	if(w<n/2)dfs(x+1,sum+a[3][x],u,v,w+1);
}
int volue(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[1][i]>>a[2][i]>>a[3][i];
    }
    dfs(0,0,0,0,0);
    cout<<ans<<"\n";
    ans=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        volue();
    }
    return 0;
}

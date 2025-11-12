#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int t,n,m,a[N][4];
ll ans;
void dfs(int pos,int x,int y,int z,ll res){
	if(pos==n+1){
		ans=max(ans,res);
		return ;
	}
	if(x>0){
		dfs(pos+1,x-1,y,z,res+a[pos][1]);
	}
	if(y>0){
		dfs(pos+1,x,y-1,z,res+a[pos][2]);
	}
	if(z>0){
		dfs(pos+1,x,y,z-1,res+a[pos][3]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0LL;
		scanf("%d",&n);
		m=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		dfs(1,m,m,m,0LL);
		printf("%lld\n",ans);
	}
	return 0;
}
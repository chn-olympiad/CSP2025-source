#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,a[N][4],ans;
void dfs(int k,int x,int y,int z,int sum,int n){
	if(k==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(x+1<=n/2)dfs(k+1,x+1,y,z,sum+a[k][1],n);
	if(y+1<=n/2)dfs(k+1,x,y+1,z,sum+a[k][2],n);
	if(z+1<=n/2)dfs(k+1,x,y,z+1,sum+a[k][3],n);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans=0;
		dfs(1,0,0,0,0,n);
		cout<<ans<<"\n";
	}
	return 0;
}
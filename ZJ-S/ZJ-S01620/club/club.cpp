#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
int a[100005][4]={0};
void dfs(long long sum,int k,int x,int y,int z){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	if(x<n/2) dfs(sum+a[k][1],k+1,x+1,y,z);
	if(y<n/2) dfs(sum+a[k][2],k+1,x,y+1,z);
	if(z<n/2) dfs(sum+a[k][3],k+1,x,y,z+1);
}                 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		ans=0;
		dfs(0,1,0,0,0);
		cout<<ans;
	}
	return 0;
}
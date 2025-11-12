#include<bits/stdc++.h>
using namespace std;
int t,n,m;
struct p{
	int x,y,z;
}a[100001];
int dfs(int i,int x,int y,int z,long long ans){
	if(i>n){
		return ans;
	}
	if(x==m){
		if(y==m){
			ans+=dfs(i+1,x,y,z+1,ans)+a[i].z;
		}
		else if(z==m){
			ans+=dfs(i+1,x,y+1,z,ans)+a[i].y;
		}
		else{
			ans+=max(dfs(i+1,x,y,z+1,ans)+a[i].z,dfs(i+1,x,y+1,z,ans)+a[i].y);
		}
	}
	else if(y==m){
		if(z==m){
			ans+=dfs(i+1,x+1,y,z,ans)+a[i].x;
		}
		else{
			ans+=max(dfs(i+1,x,y,z+1,ans)+a[i].z,dfs(i+1,x+1,y,z,ans)+a[i].x);
		}
	}
	else if(z==m){
		ans+=max(dfs(i+1,x,y+1,z,ans)+a[i].y,dfs(i+1,x+1,y,z,ans)+a[i].x);
	}
	else{
		ans+=max(max(dfs(i+1,x,y,z+1,ans)+a[i].z,dfs(i+1,x+1,y,z,ans)+a[i].x),dfs(i+1,x,y+1,z,ans)+a[i].y);
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		long long ans=dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
}
#include<bits/stdc++.h> 
using namespace std;
int T,n,ans;
struct Node{
	int x,y,z;
}a[100005];
void dfs(int k,int sum,int ca,int cb,int cc){
	if(k==n+1){
		if(ca<=n/2&&cb<=n/2&&cc<=n/2){
			ans=max(ans,sum);
		}
		return ;
	}
	for(int i=k;i<=n;i++){
		dfs(k+1,sum+a[i].x,ca+1,cb,cc);
		dfs(k+1,sum+a[i].y,ca,cb+1,cc);
		dfs(k+1,sum+a[i].z,ca,cb,cc+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

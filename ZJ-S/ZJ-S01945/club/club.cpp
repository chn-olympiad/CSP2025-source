#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][5],ans=0;
void dfs(int pe,int sum,int aa,int b,int c){
	if(aa>n/2 || b>n/2 || c>n/2) return ;
	if(pe==n){
		ans=max(ans,sum);
		return ;
	}
	dfs(pe+1,sum+a[pe+1][1],aa+1,b,c);
	dfs(pe+1,sum+a[pe+1][2],aa,b+1,c);
	dfs(pe+1,sum+a[pe+1][3],aa,b,c+1);	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

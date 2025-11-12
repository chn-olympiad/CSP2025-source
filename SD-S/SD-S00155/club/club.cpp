#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,a[100005][3],it; 
ll maxx;
void dfs(int x,int r1,int r2,ll ans){
	if(x>=n){
		maxx=max(maxx,ans);
		return ;
	}
	if(r1+1<=it){
		dfs(x+1,r1+1,r2,ans+a[x][0]);
	}
	if(r2+1<=it){
		dfs(x+1,r1,r2+1,ans+a[x][1]);
	}if(x-r1-r2+1<=it){
		dfs(x+1,r1,r2,ans+a[x][2]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof a);
		maxx=-1;
		cin>>n;
		it=n/2;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		dfs(0,0,0,0);
		cout<<maxx<<"\n";
	}
	return 0;
} 

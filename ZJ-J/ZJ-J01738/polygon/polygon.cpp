#include<bits/stdc++.h>
using namespace std;
int n,i,ans,a[5010];
void dfs(int t,int s,int sum,int ma){
	if(t>n){
		if(s>=3&&sum>ma*2){
			ans++;
		}return ;
	}
	dfs(t+1,s+1,sum+a[t],max(ma,a[t]));
	dfs(t+1,s,sum,ma);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}dfs(1,0,0,0);
	cout<<ans;
}

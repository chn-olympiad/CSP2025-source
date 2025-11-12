#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,a[100005][5],cnt[5],maxn,num;
void dfs(int x,long long ans){
	if(x==n+1){
		maxn=max(maxn,ans);
		return;
	}
	for(int j=1;j<=3;j++){
		if(cnt[j]+1>num) continue;
		cnt[j]++;
		dfs(x+1,ans+a[x][j]);
		cnt[j]--;
	}
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
		num=n/2;
		maxn=0;
		dfs(1,0);
		cout<<maxn<<"\n";
	}
	return 0;
}

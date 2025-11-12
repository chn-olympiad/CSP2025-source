#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,ans;
int a[N][4],b[N],idx,cnt[4];
void dfs(int x,int sum){
	if(x>=n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<m){
			cnt[i]++;
			dfs(x+1,sum+a[x+1][i]);
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		ans=0;
		memset(cnt,0,sizeof cnt);
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
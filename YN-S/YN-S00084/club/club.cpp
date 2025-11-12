#include<bits/stdc++.h>
using namespace std;

const int scx=1e5+10;
int t,n;
int g[scx];
int a[scx][5];
int ans;
int cnt[5];

void dfs(int u,int sum){
	if(u>n){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(u+1,sum+a[u][i]);
			cnt[i]--;
		}
	}
}

int cnt00;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cnt00=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			g[i]=a[i][1];
			if(a[i][2]==a[i][3]&&a[i][2]==0){
				cnt00++;
			}
		}
		ans=0;
		if(cnt00==n){
			sort(g+1,g+1+n);
			for(int i=n;i>n/2;i--){
				ans+=g[i];
			}
		}else dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}

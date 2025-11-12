#include<bits/stdc++.h>
using namespace std;
int n,T,sum,ans;
int myd[100005][3];
int cnt[3];

void dfs(int st){
	if(st>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<3;i++){
		if(cnt[i]>=n/2) continue;
		cnt[i]++;
		sum+=myd[st][i];
		dfs(st+1);
		sum-=myd[st][i];
		cnt[i]--;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		memset(myd,0,sizeof(myd));
		ans=0;sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&myd[i][0],&myd[i][1],&myd[i][2]);
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout); 
}

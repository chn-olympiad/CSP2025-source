#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,mp[100005][4],r[4],rmax;
ll ans,cnt;//<=n/2
void dfs(int x){
	if (x==n+1){
		ans=max(ans,cnt);
		return;
	}
	for (int i=1;i<=3;i++){
		if (r[i]+1<=rmax){
			r[i]++;
			cnt+=mp[x][i];
			dfs(x+1);
			cnt-=mp[x][i];
			r[i]--;
		}
		dfs(x+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		rmax=n/2;
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&mp[i][1],&mp[i][2],&mp[i][3]);
		}
		dfs(1);
		printf("%lld\n",ans);
		ans=0;
		cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
}

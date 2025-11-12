#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll T,n,a[maxn][5],club[5],ans;
void dfs(int pos,ll sum){
	if(pos==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(club[i]*2+2<=n){
			club[i]++;
			dfs(pos+1,sum+a[pos][i]);
			club[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%lld",&a[i][j]);
		club[1]=club[2]=club[3]=ans=0;
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}

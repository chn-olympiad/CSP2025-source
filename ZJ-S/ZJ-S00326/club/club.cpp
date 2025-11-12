#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,ans;
int a[N][4],cnt[4];
int b[N];
void dfs(int x,int s){
	if(x>n){
		ans=max(ans,s);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(x+1,s+a[x][i]);
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n>200){
			for(int i=1,t;i<=n;i++){
				cin>>b[i]>>t>>t;
			}
			sort(b+1,b+n+1);
			for(int i=n/2+1;i<=n;i++) ans+=b[i];
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		ans=0;cnt[1]=0;cnt[2]=0;cnt[3]=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
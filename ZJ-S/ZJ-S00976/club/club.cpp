#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],b[N],cnt[5],ans;
bool f=1;
inline void dfs(int x,int s){
	if(x==n+1){
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]==n/2) continue;
		cnt[i]++;
		dfs(x+1,s+a[x][i]);
		cnt[i]--;
	}
}
inline bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		f=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			b[i]=a[i][1];
			if(a[i][2]!=0||a[i][3]!=0) f=0;
		}
		if(f){
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			printf("%d\n",ans);
			return 0;
		}
		ans=-1;
		cnt[1]=cnt[2]=cnt[3]=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	
	return 0;
}


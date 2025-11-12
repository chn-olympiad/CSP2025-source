#include<bits/stdc++.h>
using namespace std;
int n,a[5100];
int head[2000005],ver[2000005],Next[2000005],we[2000005],tot;
long long ans;
int dis[5100];
void add(int u,int v,int w){
	ver[++tot]=v;
	Next[tot]=head[u];
	we[tot]=w;
	head[u]=tot;
}
void dfs(int s,int cnt,int sum,int ma){
	if(cnt>=3){
		if(sum>ma*2){
			ans++;
			ans=ans%(long long)(998244353);
		}
	}
	for(int i=head[s];~i;i=Next[i]){
		int di=ver[i];
		dfs(di,cnt+1,sum+we[i],max(ma,we[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			add(i,j,a[j]);
			//cout<<i<<" "<<j<<" "<<a[j]<<"\n";
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i],a[i]);
	}
	printf("%lld\n",ans%(long long)(998244353));
	return 0;
} 

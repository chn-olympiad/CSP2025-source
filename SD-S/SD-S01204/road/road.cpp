#include<bits/stdc++.h>
using namespace std;
int N,M,K;
typedef pair<int,int> P;
struct node{
	int u,v,w;
}edge[1100010], edge1[1100010],edget[1100010];
int a[10010][15];
int c[15];
int fa[10010];
int tot;
int cnt;
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int l,int r){
	if(l>=r){
		return;
	}
	int mid=(l+r)>>1;
	merge(l,mid);
	merge(mid+1,r);
	int i=l,cnt=0,j;
	for(j=mid+1;j<=r&&i<=mid;j++){
		while(i<=mid&&edge1[i].w<=edge1[j].w){
			cnt++;
			edget[cnt+l-1]=edge1[i];
			i++;
		}
		cnt++;
		edget[cnt+l-1]=edge1[j];
	}
	while(i<=mid){
		cnt++;
		edget[l+cnt-1]=edge1[i];
		i++;
	}
	while(j<=r){
		cnt++;
		edget[cnt+l-1]=edge1[j];
		j++;
	}
	for(int k=l;k<=r;k++){
		edge1[k]=edget[k];
	}
}
bool cmp1(struct node x,struct node y){
	return x.w<y.w;
}
long long solve(){
	for(int i=1;i<=N+K;i++){
		fa[i]=i;
	}
	long long ans=0;
	int i=1,j=1;
	while(i<M&&j<cnt){
		if(edge[i].w<edge1[j].w){
		        if(find(edge[i].u)!=find(edge[i].v)){
			        fa[fa[edge[i].u]]=fa[edge[i].v];
			    ans+=edge[i].w;
		    }
		    i++;
		}
		else{
			if(find(edge1[j].u)!=find(edge1[j].v)){
				fa[fa[edge1[j].u]]=fa[edge1[j].v];
			    ans+=edge1[j].w;
			}
			j++;
		}
	}
	while(i<M){
		if(find(edge[i].u)!=find(edge[i].v)){
		    fa[fa[edge[i].u]]=fa[edge[i].v];
			ans+=edge[i].w;
		}
		i++;
	}
	while(j<cnt){
		if(find(edge1[j].u)!=find(edge1[j].v)){
			fa[fa[edge1[j].u]]=fa[edge1[j].v];
		    ans+=edge1[j].w;
		}
		j++;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=M;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	int g=0;
	sort(edge+1,edge+M+1,cmp1);
	for(int i=1;i<=K;i++){
		scanf("%d",&c[i]);
		if(c[i]==0){
			g++;
		}
		for(int j=1;j<=N;j++){
			scanf("%d",&a[j][i]);
		}
	}
	long long ans=1e18;
	int f=1;
	for(int i=1;i<=K;i++){
		f*=2;
	}
	if(g==K){
		long long maxn=0;
		cnt=0;
		for(int j=1;j<=K;j++){
			for(int k=1;k<=N;k++){
				edge1[++cnt].u=j+N;
				edge1[cnt].v=k;
				edge1[cnt].w=a[k][j];
			}
				
		}
		if(cnt>=1)merge(1,cnt);
		maxn+=solve();
		ans=min(ans,maxn); 
		printf("%lld\n",ans);
		fclose(stdin);
	    fclose(stdout);
		return 0;
	}
	for(int i=0;i<=f-1;i++){
		long long maxn=0;
		cnt=0;
		for(int j=1;j<=K;j++){
			if((i>>(j-1))&1){
				maxn+=c[j];
				for(int k=1;k<=N;k++){
					edge1[++cnt].u=j+N;
					edge1[cnt].v=k;
					edge1[cnt].w=a[k][j];
				}
				
			}
		}
		if(cnt>=1)merge(1,cnt);
		maxn+=solve();
		ans=min(ans,maxn); 
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


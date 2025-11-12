#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
struct node{
	int u,v,w;
}M[maxn],nM[maxn],fM[maxn];

int n;
int m;
int k;
int fa[10000+10];
int N[11][10000+10];
int len[1001][1001];

bool cmp(node x,node y){
	return x.w<y.w;
}

int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}

void merge(int a,int b){
	a=find(a);
	b=find(b);
	fa[a]=b;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		M[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>N[i][10001];
		for(int j=1;j<=n;j++){
			cin>>N[i][j];
		}
	}
	
	sort(M+1,M+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int tot=n;
	int cnt=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			len[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		if(find(M[i].u)!=find(M[i].v)){
			merge(M[i].u,M[i].v);
			tot--;
			nM[cnt++]={M[i].u,M[i].v,M[i].w};
			ans+=M[i].w;
			len[M[i].u][M[i].v]=M[i].w;
			len[M[i].v][M[i].u]=M[i].w;
			
		}
		if(tot==1){
			break;
		}
	}
	
	for(int i=1;i<=m;i++){
		M[i]=nM[i];
	}
	for(int i=1;i<=k;i++){
		
		int val=N[i][10001];
		if(val>ans)continue;
		for(int j=1;j<=cnt;j++){
			fM[j]=M[j];
		}
		int fcnt=cnt;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				int nb=N[i][j]+N[i][k];
				if(nb<len[k][j]){
					M[++cnt]={j,k,nb};
				}
			}
		}
		sort(M+1,M+1+cnt,cmp);
		for(int j=1;j<=n;j++){
			fa[j]=j;
		}
		tot=n;
		int ncnt=0;
		int nans=0;
		for(int j=1;j<=cnt;j++){
			if(find(M[j].u)!=find(M[j].v)){
				merge(M[j].u,M[j].v);
				tot--;
				nM[++ncnt]={M[j].u,M[j].v,M[j].w};
				nans+=M[j].w;
				len[M[j].u][M[j].v]=M[j].w;
				len[M[j].v][M[j].u]=M[j].w;	
			}
			if(tot==1){
				break;
			}
		}
		if(ans>val+nans){
			ans=nans+val;
			for(int j=1;j<=cnt;j++){
				M[j]=nM[j];
			}
			cnt=ncnt;
			
		}else{
			for(int j=1;j<=cnt;j++){
				M[j]=fM[j];
				len[fM[j].u][fM[j].v]=fM[j].w;
				len[fM[j].v][fM[j].u]=fM[j].w;
			}
			cnt=fcnt;
		}
		
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
const int MAXM=1000010;
struct Edge{
	int u,v;
	long long w;
};
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int n,m,k;
Edge edges[MAXM];
int a[15][MAXN];
int c[15];
bool A_lock=false;
int fa[MAXN];
int find_fa(int x){
	if(fa[x]==x)return fa[x];
	else{
		fa[x]=find_fa(fa[x]);
		return fa[x];
	}
}
void cnnt(int x,int y){
	fa[y]=find_fa(x);
}
int main(){
	long long ans=0;
	//cout<<0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cout<<0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
		//cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
	}
	int lst=-1;
	for(int i=0;i<k;i++){
		scanf("%d",&c[i]);
		if(c[i]>0)A_lock=true;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(lst!=-1 && a[i][j]==0 && c[i]==0)cnnt(j,lst);
			if(c[i]==0 && a[i][j]==0)lst=j;
		}
	}
	/*
	if(A_lock==false){
		cout<<"0"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
		
	}*/
	sort(edges,edges+n,cmp);
	for(int i=0;i<m;i++){
		if(find_fa(edges[i].u)==find_fa(edges[i].v))continue;
		else{
			ans+=edges[i].w;
			cnnt(edges[i].u,edges[i].v);
		}
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long fa[100100],ans,cnt,n,m,k,wk[15],w[15][100100];
struct edge{
	int u,v,w;
}edg[1000100];
bool cmp(edge a,edge b){
	return a.w<=b.w;
}
long long find(long long x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
bool checka(){
	for(int i=1;i<=k;i++){
		if(wk[i]!=0) return false;
	}
	return true;
}
void solvea(){
	long long minn=0,flag=0,idx=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			edg[++cnt].u=n+i;
			edg[cnt].v=j;
			edg[cnt].w=w[i][j];
		}
	}
	sort(edg+1,edg+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		minn=edg[i].w;
		if(find(edg[i].u)!=find(edg[i].v)){
			fa[find(edg[i].u)]=find(edg[i].v);
			ans+=minn;
		}
		flag=find(n);
		for(int j=idx;j<=n;j++){
			if(flag!=find(j)){
				idx=j;
				break;
			}
			if(j==n){
				cout<<ans<<endl;
				return ;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		edg[++cnt].u=u;edg[cnt].v=v;edg[cnt].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>wk[i];
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
		}
	}
	
	if(checka()){
		solvea();//bro的solvea有点暴力 。
		//完了，好像正确性也不大对 
		return 0;
	}
	if(k==0){
		sort(edg+1,edg+1+cnt,cmp);//特殊性质0 
		for(int i=1;i<=cnt;i++){
			if(find(edg[i].u)!=find(edg[i].v)){
				fa[find(edg[i].u)]=find(edg[i].v);
				ans+=edg[i].w;;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
4 6 1
1 2 100
2 3 100
3 4 100
1 4 10
2 4 10
3 4 10
0 1 1 1 1
*/
//byd这电脑读不进去16MB的大洋梨 

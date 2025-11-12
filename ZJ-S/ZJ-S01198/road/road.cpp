#include<bits/stdc++.h>
using namespace std;
struct p{
	int to,dis;
};
vector<p>eg[10025];
vector<int>a;
int n,m,k,ans,all=1;
int v[10025];
void prim(int id){
	v[id]=1;
	int minid=0,minn=0x3f3f3f3f;
	for(int i=1;i<=n+k;i++){
		if(v[i]==0)continue;
		int lj=eg[i].size();
		for(int j=0;j<lj;j++){
			if(v[eg[i][j].to]==0){
				if(minn>eg[i][j].dis-(i>n?a[i-1-n]:0)){
					minn=eg[i][j].dis,minid=eg[i][j].to;
				}
			}
		}
	}
	cout<<minn<<endl;
	ans+=minn;
	if(minid<=n&&minid!=0){
		all++;
	}
	if(minid==0||all==n)return ;
	else{
		prim(minid);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,vis;
		scanf("%d%d%d",&u,&v,&vis);
		eg[u].push_back(p{v,vis});
		eg[v].push_back(p{u,vis});
	}
	for(int i=1;i<=k;i++){
		int tag;
		scanf("%d",&tag);
		int minid=0,minn=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			int l;
			scanf("%d",&l);
			a.push_back(l);
			if(minn>l){
				minid=j,minn=l;
			}
			eg[m+i].push_back(p{j,l+tag});
			eg[j].push_back(p{m+i,l+tag});
		}
	}
	prim(1);
	printf("%d",ans);
}

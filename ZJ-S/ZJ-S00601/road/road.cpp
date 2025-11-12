#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e4+7;
int n,m,k;
int fa[Maxn];
pair<int,vector<int> > vill[11];
struct Node{
	int u,v,w;
};
bool cmp(Node x,Node y){return x.w<y.w;}
vector<Node> Way;
vector<Node> way;
int find(int dis){
	return fa[dis]==dis?dis:fa[dis]=find(fa[dis]);
}
void build(int u,int v){
	fa[find(u)]=find(v);
}
int kl(){
	for(int j=1;j<=n;j++)fa[j]=j;
	sort(way.begin(),way.end(),cmp);
	int ans=0;
	for(int i=0;i<way.size();i++){
		if(find(way[i].u)!=find(way[i].v)){
			ans+=way[i].w;
			build(way[i].u,way[i].v);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(find(i)!=find(j))return INT_MAX;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		Node a;
		a.u=u;
		a.v=v;
		a.w=w;
		Way.push_back(a);
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&vill[i].first);
		for(int j=1;j<=n;j++){
			int w;
			scanf("%d",&w);
			vill[i].second.push_back(w);
		}
	}
	int minn=INT_MAX;
	for(int i=0;i<pow(2,k);i++){
		
		int t=0;
		int te=i;
		for(int j=0;j<Way.size();j++)way.push_back(Way[j]);
		int j=1;
		while(te){
			if(te&1){
				t+=vill[j].first;
				for(int k=1;k<n;k++){
					for(int l=k+1;l<=n;l++){
						Node a;
						a.u=k;
						a.v=l;
						a.w=vill[j].second[k-1]+vill[j].second[l-1];
						way.push_back(a);
					}
				}
			}
			te>>=1;
			j++;
		}
		t+=kl();
		minn=min(minn,t);
	}
	printf("%d",minn);
	return 0;
}

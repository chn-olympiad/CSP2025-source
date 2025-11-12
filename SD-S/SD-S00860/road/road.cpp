#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e4+10;
int fa[maxn];
int a[maxn*2][maxn];
int c[maxn],ans;
bool flag;
struct edge{
	int u,v,w,flag;
};
bool cmp(edge a,edge b){
	return a.w<b.w;
}
vector<edge> p;
int n,m,k;
int find(int x){
	if(fa[x]==x) return x;
	else return  fa[x] = find(fa[x]);
}
void merge(int x,int y){
	int fx= find(x);
	int fy = find(y);
	if(fx!=fy) fa[fx] = fy;
}
/*void kruskal2(int z){
		for(int j = 1;j<=m;j++){
			int w = a[z][j];
			edge a = {z+n,j,w,c[z]};
			edge b = {j,z+n,w,c[z]};
			p.push_back(a);
			p.push_back(b);
		}
	sort(p.begin(),p.end(),cmp);
	//for(int i = 0;i<p.size();i++)
	//cout<<p[i].u<<" "<<p[i].v<<" "<<p[i].w<<endl;
	for(int z = 0;z<p.size();z++){
		if(find(p[z].u)!=find(p[z].v)){
			merge(p[z].u,p[z].v);
			ans[z]+=p[z].w;
		}
	}
	ans[z]+=c[z];
}
*/
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)
		fa[i] = i;
	for(int i = 1;i<=m;i++){
		int u1,v1,w1;
		cin>>u1>>v1>>w1;
		edge a = {u1,v1,w1,0};
		edge b = {v1,u1,w1,0};
		p.push_back(a);
		p.push_back(b);
	}
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=m;j++){
			int w = a[i][j];
			edge a = {i+n,j,w,c[i]};
			edge b = {j,i+n,w,c[i]};
			p.push_back(a);
			p.push_back(b);
		}
	}
	sort(p.begin(),p.end(),cmp);
	//for(int i = 0;i<p.size();i++)
	//cout<<p[i].u<<" "<<p[i].v<<" "<<p[i].w<<endl;
	for(int i = 0;i<p.size();i++){
		if(find(p[i].u)!=find(p[i].v)){
			merge(p[i].u,p[i].v);
			ans+=p[i].w;
		}
	}
/*	for(int z = 1;z<=k;z++){
		kruskal2(z);
}*/
	
	cout<<ans;
	return 0;
}


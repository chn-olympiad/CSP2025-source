#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5,M=3e6+5;
struct edge{
	int x,y,w;
	bool operator < (const edge &q) const{
		return w<q.w;
	}
};
vector<edge> v;
int n,m,k;
int fa[N],c[N];
int ask(int x){
	if(x==fa[x]) return x;
	else return fa[x]=ask(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d %d %d",&x,&y,&z);
		v.push_back({x,y,z});
	}
	for(int i=1;i<=k;i++){
		fa[i+n]=i+n;
		scanf("%d",&c[n+i]);
		for(int j=1;j<=n;j++){
			fa[j]=j;
			int x;scanf("%d",&x);
			v.push_back({i+n,j,x});
		}
	}
	sort(v.begin(),v.end());
	long long ans=0;
	for(int i=0;i<v.size();i++){
		edge t=v[i];
		int rx=ask(t.x),ry=ask(t.y);
		if(rx==ry) continue;
		ans+=t.w,fa[rx]=ry;
	}
	cout<<ans;
	return 0;
}

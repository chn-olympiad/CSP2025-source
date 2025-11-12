#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e6+5,N=2e4+5,MAX=4e18;
struct yrd{
	int u,v,w;
};
vector<yrd> edge,edge2;
vector<yrd> new_edge[15];
int f[N],k,n,c[15],a[15][N];
int ch[15],lim[15];
int ans=MAX,pre;
bool cmp(yrd a,yrd b){
	return a.w<b.w;
}
int getfa(int a){
	if (a==f[a]){
		return a;
	}
	return f[a]=getfa(f[a]);
}
void merge(int a,int b){
	int fa=getfa(a),fb=getfa(b);
	f[fa]=fb;
}
void init(){
	for (int i=1;i<=k;i++){
		int mn=MAX,mnpos;
		for (int j=1;j<=n;j++){
			if (a[i][j]<=mn){
				mn=min(mn,a[i][j]);
				mnpos=j;
			}
		}
		for (int j=1;j<=n;j++){
			if (j==mnpos){
				continue;
			}
			new_edge[i].push_back((yrd){mnpos,j,a[i][j]});
		}
		c[i]+=mn;
		if (c[i]==0){
			lim[i]=1;
		}
		if (c[i]>=pre){
			lim[i]=-1;
		}
	}
}
int work(){
	int tmp=0,edcnt=0;
	for (int i=1;i<=n;i++){
		f[i]=i;
	}
	vector<yrd> tmpe=edge;
	for (int i=1;i<=k;i++){
		if (ch[i]){
			for (auto j:new_edge[i]){
				tmpe.push_back(j);
			}
			tmp+=c[i];
		}
	}
	sort(tmpe.begin(),tmpe.end(),cmp);
	for (int i=0;i<tmpe.size();i++){
		if (edcnt==n-1){
			break;
		}
		if (getfa(tmpe[i].u)!=getfa(tmpe[i].v)){
			tmp+=tmpe[i].w;
			merge(tmpe[i].u,tmpe[i].v);
			edcnt++;
		}
	}
	return tmp;
}
void dfs(int p){
	if (p==k+1){
		//cout<<p<<'\n';
		ans=min(ans,work());
		return;
	}
	if (lim[p]!=-1){
		ch[p]=1;
		dfs(p+1);
	}
	if(lim[p]!=1){
		ch[p]=0;
		dfs(p+1);
	}
}
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge2.push_back((yrd){u,v,w});
	}
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int tmp=0,edcnt=0;
	for (int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(edge2.begin(),edge2.end(),cmp);
	for (int i=0;i<edge2.size();i++){
		if (edcnt==n-1){
			break;
		}
		if (getfa(edge2[i].u)!=getfa(edge2[i].v)){
			tmp+=edge2[i].w;
			merge(edge2[i].u,edge2[i].v);
			edge.push_back(edge2[i]);
			edcnt++;
		}
	}
	pre=tmp;
	//cout<<pre<<'\n';
	init();
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}

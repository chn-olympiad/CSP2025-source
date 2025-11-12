#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 500005
const int inf=1e18+7;
int n,m,k,/*cnt,*/ans=inf;
struct node {
	short u,v;
	signed w;
	bool operator <(const node y) const {
		return w<y.w;
	}
}_rd[1000006];
std::vector<node>vec[12],rvec;
int cst[12];
struct bingchajijiaoshalaizhe {
	int fa[20004],cnt;
	void Init(int len=n+k) { for(int i=1;i<=len;i++) fa[i]=i; cnt=0; }
	int F(int x) { return (fa[x]==x?x:fa[x]=F(fa[x])); }
	void Mg(int x,int y) { fa[fa[x]]=fa[y],cnt++; } // mo ren F guo
}dsu;
void dfs(int x=0,int y=0,std::vector<node>v=rvec,int S=0) {
	if(x==k) {
		dsu.Init();
		for(int i=0;i<v.size();i++) {
			if(dsu.F(v[i].u)!=dsu.F(v[i].v))
				dsu.Mg(v[i].u,v[i].v),y+=v[i].w;
		}
		// std::cout<<dsu.cnt<<' '<<y<<' '<<v.size()<<' '<<S<<'\n';
		ans=std::min(ans,y);
		return ;
	}
	dfs(x+1,y,v,S*10);
	std::vector<node>nxt; nxt.clear();
	int z=0;
	for(int i=0;i<n;i++) {
		while(z!=v.size()&&v[z]<vec[x+1][i])
			nxt.push_back(v[z++]);
		nxt.push_back(vec[x+1][i]);
	} while(z!=v.size()) nxt.push_back(v[z++]);
	// std::cout<<v.size()<<' '<<x<<' '<<nxt.size()<<'\n';
	dfs(x+1,y+cst[x+1],nxt,S*10+1);
	return ;
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::cin>>n>>m>>k;
	for(int i=1;i<=m;i++) std::cin>>_rd[i].u>>_rd[i].v>>_rd[i].w;
	std::sort(_rd+1,_rd+m+1),dsu.Init();
	for(int i=1;i<=m;i++) if(dsu.F(_rd[i].u)!=dsu.F(_rd[i].v)) dsu.Mg(_rd[i].u,_rd[i].v),rvec.push_back(_rd[i]);
	// std::cout<<rvec.size()<<'\n';
	for(int i=1;i<=k;i++) {
		std::cin>>cst[i];
		for(int j=1,w;j<=n;j++) std::cin>>w,vec[i].push_back(node{n+i,j,w});
		std::sort(vec[i].begin(),vec[i].end());
	}
	dfs();
	std::cout<<ans<<'\n';
	return 0;
}
// gui bing hai zai zhui wo
// csps fa bu fa dai ma lai zhe?
// wei shen me zhe ge kao chang hui zai shou shang sui ji shua xin chong zi a
// wo jue dui bu yao lai zhe li shang da xue
// /zhuakuang

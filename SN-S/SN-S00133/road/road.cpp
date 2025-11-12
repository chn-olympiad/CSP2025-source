#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,t,k;
const int maxn=1e4+5;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=0x3f3f3f3f3f3f3f3fll;
vector<pair<int,int> >vc[maxn];
int fa[maxn];
int c[maxn];
vector<pair<int,int> >vc2[maxn];
//XTBT
//14:54
//开T2，T1有点难受，过会在写
//不是你要出你就出板子嘛，改什么真的是
//滚回去打T1 
//T1疑似也只会暴力，感觉要4个暴力离场了
//17:21
//再看T3
//17:24
//T3不会，只能T2了 
//17:38
//MD今天之后滚回去练码力（只要不AFO） 
//17:51
//憋屈到不能再憋屈的死法：不会写小根堆 
//AFO
//MD****不会写小根堆也是神人了 
//18:03
//貌似会T2了
//MD有生之年能唐成这样也是神人了
//555
//555
//555
//555
//啊啊啊啊啊
//今晚回去测，我要是T2过了就彻底疯了 
//我应该是创****史第一最多的入了 
//史上第一个因为没背STL而挂大分的 
//唐如糖，招如笑
//啊啊啊啊啊啊啊啊啊
//**最后还是成重庆了qwq
//这是**吗
//希望2=吧…… 
priority_queue<pair<int,int>,vector<pair<int,int>> >q;
int w[maxn];
struct cxh{
	int a;
//	bool oprea <(int a,cxh a){
//		return a<x.a;
//	}
}; 
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void hb(int x,int y){
	x=find(x),y=find(y);
	fa[y]=x;
}
//void dfs(int p){
//	for(int i=1;i<=n;i++)
//}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	//freopen("jmcakioi.txt","w",stdout);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vc[u].push_back({v,w});
		vc[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			vc2[i].push_back({j,w});
		}
	}
//5 6 0
//1 2 2
//2 4 5
//2 5 1
//4 5 1
//1 3 3
//3 5 1
if(k==0){
	int cnt=0;int ans=0;
	q.push({0,1});
	bool o=0;
	while(!q.empty()){
		if(o)break;
		pair<int,int>p=q.top();q.pop();
		int w=p.first,u=p.second;
		cout<<u<<" "<<w<<endl;
		for(int i=0;i<(int)vc[u].size();i++){
			int v=vc[u][i].first;
			int uu=find(u),vv=find(v);
			if(uu==vv)continue;
			q.push({vc[u][i].second+w,v});
			cnt++;
			if(cnt==n-1){
				ans=w+vc[u][i].second;o=1;break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
else {
//	dfs(1);
}
	
	return 0;
}


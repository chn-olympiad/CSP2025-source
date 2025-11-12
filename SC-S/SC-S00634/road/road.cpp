#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int maxn = 1e4+25;
const int maxm = 1e6+25;
int n,m,u,v,edgecnt,addedgecnt,w,k;
struct EDGE{
	int u,v,val;
	bool operator < (const EDGE& b) const {return val < b.val;}
}edge[maxm],addedge[maxm];
int dis[maxn][15],fa[maxn],pri[maxn];
long long ans=0x3f3f3f3f3f3f3f3f;

inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

inline void merge(int sm,int ms){
	fa[find(sm)]=find(ms);
}

inline int Kruscal(int stand){
	int sum=0,cnt1=1,cnt2=1,otherpri=0,limit=n-1;
	addedgecnt=0;
	for(int i=0;i<10;i++){
		fa[i+n+1]=-1;
		if(stand&(1<<i)){//选了第i+1个村庄 
			otherpri+=pri[i+1];
			for(int j=1;j<=n;j++){
				addedge[++addedgecnt].val=dis[j][i+1];
				addedge[addedgecnt].u=j;
				addedge[addedgecnt].v=i+n+1;
			}
			fa[i+n+1]=i+n+1; limit++;
		}
	}
	sort(addedge+1,addedge+addedgecnt+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	while(limit>0){
		if(edge[cnt1].val>addedge[cnt2].val && cnt2<=addedgecnt){
			if(find(addedge[cnt2].u)!=find(addedge[cnt2].v)){
				merge(addedge[cnt2].u,addedge[cnt2].v);
				limit--; sum+=addedge[cnt2++].val;
			}
			else cnt2++;
		}
		else if(cnt1<=edgecnt){
			if(find(edge[cnt1].u)!=find(edge[cnt1].v)){
				merge(edge[cnt1].u,edge[cnt1].v);
				limit--; sum+=edge[cnt1++].val;
			}
			else cnt1++;
		}
		
	}
	return sum+otherpri;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		edge[++edgecnt].u=u;
		edge[edgecnt].v=v;
		edge[edgecnt].val=w;
	}
	sort(edge+1,edge+edgecnt+1);
	for(int i=1;i<=k;i++){
		cin>>pri[i];
		for(int j=1;j<=n;j++) cin>>dis[j][i];
	}
	int temp=(1<<k);
	for(int i=0;i<temp;i++){
		ans=min(ans,Kruscal(i));
	}
	cout<<ans<<'\n';
	return 0;
}
/*
15:56 愉快开题 
15:59 最小生成树？
16:15 不能用kruscal,会爆空间,应该能用prim 
16:32 每次加入一些点跑kruscal,共(1+k)*k/2+1次,复杂度最大mlog(m)+1025*O(n+k)
16:47 稠密图，还是要用prim
16:50 考虑到最多添加k*n条边，即边最大仍为1e6数量级，可用Kruscal 
17:37 终于过掉所有样例了，求求评测姬给力点啊，求求了给过啊哥 
*/
// 32pts 做法 
// 2^k 枚举每个乡村是否城市化
// 跑一遍最小生成树 
// merge vector : O(nk) = 1e5
// kruskal : O(m) = 5e6
// calc : 1e7
// 枚举 : 1024 / 32
// tot : 1e10 / 3e8
// (1~4) + (5~12) + (17~20) = 64pts 
// (13~14) 特殊性质 A = 8pts 
#include<bits/stdc++.h>
using namespace std;
int read(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e4+100,M=1e6+10;
int fa[N];
void _init(){
	for(int i=0;i<N;++i)
		fa[i]=i;
	return;
} 
int _find(int x){
	if(x==fa[x])
		return x;
	fa[x]=_find(fa[x]);
	return fa[x];
}
void _merge(int u,int v){
	int uu=_find(u),vv=_find(v);
	if(uu!=vv)
		fa[uu]=vv; 
	return;
}
struct node{
	int u,v,w;
	friend bool operator<(const node cmp1,const node cmp2){
		return cmp1.w<cmp2.w;
	}
};vector<node>e,dis[15];
// 乡村的编号 n+1 ~ n+k 
int c[15];
vector<node>merge_vec(vector<node>a,vector<node>b){ // ok
	int l1=a.size(),l2=b.size();
	int i=0,j=0;
	vector<node>res;
	while(i<l1&&j<l2){
		if(a[i].w<b[j].w){
			res.push_back(a[i]);
			++i;
		}
		else{
			res.push_back(b[j]);
			++j;
		}
	}
	while(i<l1){
		res.push_back(a[i]);
		++i;
	}
	while(j<l2){
		res.push_back(b[j]);
		++j;
	}
	return res;
}
long long kruskal(int n,int k,int s){
	vector<node>vc=e;
	int ed=n;
	for(int i=1;i<=k;++i)
		if(s&(1<<(i-1))){
			vc=merge_vec(vc,dis[i]);
			++ed;
		}
	_init();
	long long sum=0;
	int cnt=0;
	for(auto nd:vc){
		int u=nd.u,v=nd.v,w=nd.w;
		if(_find(u)!=_find(v)){
			_merge(u,v);
			++cnt;
			sum+=w;
		}
		if(cnt==ed-1)
			break;
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		e.push_back({u,v,w});
	}
	sort(e.begin(),e.end());
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j){
			int d=read();
			dis[i].push_back({n+i,j,d});
		}
		sort(dis[i].begin(),dis[i].end());
	}
	if(1ll*m*(1<<k)>=1e8){
		int s=0;
		for(int i=0;i<k;++i)
			s+=(1<<i);
		printf("%lld\n",kruskal(n,k,s));
		return 0;
	}
	long long minn=kruskal(n,0,0);
	for(int s=0;s<(1<<k);++s){
		long long _cost=0;
		for(int i=1;i<=k;++i)
			if(s&(1<<(i-1)))
				_cost+=c[i];
		_cost+=kruskal(n,k,s);
		minn=min(minn,_cost);
	}
	printf("%lld\n",minn);
	return 0;
}
/*
Input #1:

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

Output #1:

13

Input #2:

4 4 3
1 2 3
1 4 5
2 3 7
3 4 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

(特殊性质 A) 

*/

/*

Debug:

for merge_vec: 

void debug(vector<node>v){
	for(auto i:v)
		cerr<<i.w<<" ";
	cerr<<"\n";
	return;
}


	
	vector<node>vc1={(node){0,0,5},(node){0,0,6},(node){0,0,7},(node){0,0,15}},vc2={(node){0,0,7},(node){0,0,9},(node){0,0,19}};
	
	vector<node>vc3=merge_vec(vc1,vc2);
	
	debug(vc3);
	
check ok!

*/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e4 +24;
const int M = 1e6+24;
const int Inf = 1e9+7; 
ll dis[N];
ll fee[M];
bool vis[N],mark1[M];
struct node{
	 int v,w,id;
};

struct node1{
	int distance,id,uid;	
	friend bool operator <(node1 x,node1 y){
		return x.distance < y.distance;
	}
};

priority_queue<node1> qq;
vector<node>a[N];

inline void Read(int &x){
	short f = 1;
	char  c = getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f = -f;
		}
		c = getchar();
	}
	x = 0;
	do{
		x = (x<<1)+(x<<3);
		x+=c-'0';
		c = getchar(); 
	}while(c<='9'&&c>='0');
	x*=f;
	return ;
} 

inline void Ad(int u,int v,int w,int id){
	a[u].push_back((node){v,w,id});
	return ;
}

inline void Uad(int u,int v,int w,int id){
	Ad(u,v,w,id);
	Ad(v,u,w,id);
	return ;
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	while(!qq.empty())qq.pop();
	int bcc_cnt  = 0;
	int n,m,k;
	ll ans = 0;
	Read(n);
	Read(m);
	Read(k);
	for(int i=1;i<=n+k+1;i++)dis[i] = Inf,vis[i]=0,a[i].clear();
	for(int i = 1;i<=m;i++)mark1[i] = 0;
		
	dis[n+k+1] = 0;
	for(int i = 1,x,y,z;i<=m;i++){
		bcc_cnt++;
		Read(x);
		Read(y);
		Read(z);
		fee[bcc_cnt]=z;
		Uad(x,y,z,bcc_cnt);
	}
	
	for(int i=1,c1;i<=k;i++){
		Read(c1);
		fee[++bcc_cnt]  = c1;
		Uad(n+k+1,n+i,c1,bcc_cnt);//建立超级边 
		for(int j = 1,x;j<=n;j++){
			Read(x);
			fee[++bcc_cnt ] = x;
			Uad(n+i,j,x,bcc_cnt);
		}
	}
	
	Uad(n+k+1,1,0,++bcc_cnt);//超级起点 
	//接下来跑一个dijiesitela
	vis[n+k+1] = 1;//标记 
	dis[1] = 0;
	node1 tmp ; 
	int to;
	qq.push((node1){0,1,bcc_cnt});//加入初始值
	while(!qq.empty()){
		do{
			tmp =  qq.top();
			qq.pop();
		}while(!qq.empty()&&vis[tmp.id]==1);//拿出没走过的，距离最小的点
		if(vis[tmp.id]==1)break;
		vis[tmp.id] = 1;
		mark1[tmp.uid] = 1;
		for(int i = 0;i<a[tmp.id].size();i++){
			to = a[tmp.id][i].v;
			if(dis[to] > dis[tmp.id] +  a[tmp.id][i].w){
				dis[to] = dis[tmp.id] +  a[tmp.id][i].w;
				qq.push((node1){dis[to],to,a[tmp.id][i].id});//加入边 
			}//松弛 
		}
	} 
	for(int i = 1;i<=bcc_cnt;i++){
		if(!mark1[i])continue;
		ans+=fee[i];
	}
	printf("%lld\n",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
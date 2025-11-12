#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

inline ll read(){
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
const ll MAXN=1030;
const ll MAXM=1000030;
ll n,m,k;
ll w[MAXN*2];//边权
ll he[MAXN];//每个点的第一边
ll ne[MAXM*2];//一条边的下一条
ll to[MAXN];
ll cnt=0;
ll MXmy;//最大花费
bool vst[MAXN];//用来标记所有节点是否都被访问
void add(ll u,ll v,ll _w){//添加一条边
	to[cnt]=v;
	ne[cnt]=he[u];
	he[u]=cnt;
	w[cnt]=_w;
	++cnt;
}
struct EG{
	//用于优先队列的边类型
	ll et;//目的地
	ll ew;//距离
	EG(ll dingto,ll dingew){
		et=dingto;
		ew=dingew;
	}
	EG(){
	}
	bool operator<(const EG&_hh)const{
		return ew>_hh.ew;
	
	}
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
// 	变量名注意不要和关键词重复
	memset(ne,-1,sizeof ne);
	memset(he,-1,sizeof he);
	memset(to,-1,sizeof to);
	cin>>n>>m>>k;
	//虽然可能修建之后才是最优解，不过我们可以不在意，我们一般认为修建更好
	//总共是n+k个节点
	ll sum=0;
	for (int i=1; i<=m; i++){
		ll ciu,civ,ciw;
		ciu=read();
		civ=read();
		ciw=read();
		sum+=ciu+civ+ciw;
		add(ciu,civ,ciw);
		add(civ,ciu,ciw);
	}
	
	//当价格全部为0的时候可以按照最小生成树来写
	for (int i=1; i<=k; i++){
		ll mon=read();
		ll cw;
		if (mon>sum*0.7){//太大了实在买不起
			for (int j=1; j<=n; j++)
				cw=read();	
		}
		else{
			
			MXmy+=mon;
			for (int j=1; j<=n; j++){
				cw=read();
				add(n+i,j,cw);
				add(j,n+i,cw);//当成一个新节点
			}
		}
	}
	priority_queue<EG> p;
	vst[1]=true;
	for (int i=he[1]; i!=-1; i=ne[i]){
		p.push(EG(to[i],w[i]));
	}
	while(!p.empty()){
		
		EG now=p.top();
		p.pop();
		//cout<<"这里是到达"<<now.et<<"边权为"<<now.ew<<endl;
		if (vst[now.et]){
			continue;
		}
		MXmy+=now.ew;
		vst[now.et]=1;
		for (int i=he[now.et]; i!=-1; i=ne[i]){
			if (!vst[to[i]]) p.push(EG(to[i],w[i]));
		}
	}
	cout<<MXmy<<endl;

	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4





*/

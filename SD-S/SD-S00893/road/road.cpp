//freopen
//.ans
//没有思路 打暴力了 
//???
//删了个log怎么跑飞起来了
//大样例跑0.6s？？？ 
//数据水了吧 kru神力？ 跑不满？
//复杂度是 O((m+kn)*2^k*a(n)) 啊 极限是 >= 2e9 的 
//神机加油  放过我（ 
//by Lament_Rain in 17:09 
//发现因为打的是暴力拍不了（
//哦原来不是极限数据啊
//那我寄了 excpet 75pts

//呱 差点没删注释 
//in 18:24
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Compassion{
	const int N=1.1e4+8,M=3.1e6+8;
	int fa[N],siz[N];
	bool cvis[M];
	void init(int n){
		for(int i=1;i<=n;i++){
			siz[i]=1;
			fa[i]=i;
		}
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	void add(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return;
		if(siz[x]<siz[y])swap(x,y);
		fa[y]=x;
		siz[x]+=y;
	}
	struct edge{
		int u,v,w;
	}e[M];
	bool cmp(edge a,edge b){
		return a.w<b.w;
	}
	int n,m,k,fi[12],ext[12][N];
	int kru(int f,int nown){
		int ans=f,cnt=0;
//		for(int i=1;i<=nowm;i++){
//			int u=e[i].u,v=e[i].v,w=e[i].w;
//			cout<<u<<' '<<v<<' '<<w<<' '<<'\n';
//		}
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(!cvis[i])continue;
			if(find(u)!=find(v)){
				add(u,v);
				ans+=w;
				cnt++;
//				cout<<u<<' '<<v<<' '<<w<<' '<<ans<<'\n';
			}
			if(cnt==nown-1){
				return ans;
			}
		}
		return INT_MAX;
	}
	void Foloron(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(0);
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
		for(int i=1;i<=k;i++){
			cin>>fi[i];
			for(int u=1;u<=n;u++){
				int w;
				cin>>w;
				m++;
				e[m]={i+n,u,w};
			}
		}
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(e[i].u<=n&&e[i].v<=n)cvis[i]=1;
			else {
				ext[e[i].u-n][e[i].v]=i;
			}
		}
		init(n+k+k);
		int S=(1<<(k))-1,ans=LLONG_MAX>>2;
		for(int s=0;s<=S;s++){
			init(n+k+k);
			vector<int> v;
			int f=0;
			for(int i=0;(1<<i)<=s;i++){
				if(s&(1<<i)){
					v.push_back(i+1);
					f+=fi[i+1];
				}
			}
			if(f>=ans)continue;
			int cnt=v.size();
			for(auto u:v){
				for(int i=1;i<=n;i++){
					cvis[ext[u][i]]=1;
				}
			}
		//	for(int i=1;i<=m;i++)if(cvis[i])cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
			ans=min(ans,kru(f,n+cnt));
			for(auto u:v){
				for(int i=1;i<=n;i++){
					cvis[ext[u][i]]=0;
				}
			}
		//	cout<<ans<<'\n';
		}
		cout<<ans;
	}
}
signed main(){
	Compassion::Foloron();
	return 0;
}
//摩耶，八。 
//我知道我的感受，我明白这都是我的错。 


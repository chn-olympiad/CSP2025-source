#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,long long>tu; 
int n,m,k,fa[10005],stk[10005],top,st[10005],ed[10005],tim,dep[10005],ff[10005];
long long dis[15][10005],ans,kkkk;
struct node{
	int u,v;
	long long w;
}E[1000005];
vector<int>g[10005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x])
		return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
inline void dfs(int u,int fa){
	dep[u]=dep[fa]+1; 
	st[u]=++tim;
	ff[tim]=u;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)
			continue;
		dfs(v,u);
	}
	ed[u]=tim; 
}
struct pp{
	long long minn;
	int x;
};
struct tree{
	pp tr[400005];
	void build(int rt,int l,int r,int x){
		if(l==r){
			tr[rt].minn=dis[x][ff[l]];
			tr[rt].x=l;
			return; 
		}
		int mid=l+r>>1;
		build(rt<<1,l,mid,x);
		build(rt<<1|1,mid+1,r,x);
		if(tr[rt<<1].minn<tr[rt<<1|1].minn){
			tr[rt].minn=tr[rt<<1].minn;
			tr[rt].x=tr[rt<<1].minn;
		}else{
			tr[rt].minn=tr[rt<<1|1].minn;
			tr[rt].x=tr[rt<<1|1].minn;
		}
	}
	pp query(int rt,int l,int r,int x,int y){
		if(x<=l&&r<=y)
			return tr[rt];
		int mid=l+r>>1;
		pp ans;
		ans.minn=1000000007;
		if(x<=mid){
			pp t=query(rt<<1,l,mid,x,y);
			if(ans.minn>t.minn){
				ans=t;
			}
		}
		if(mid<y){
			pp t=query(rt<<1|1,mid+1,r,x,y);
			if(ans.minn>t.minn){
				ans=t;
			}
		}
		return ans;
	}
	inline void change(int rt,int l,int r,int x,bool flag){
		if(l==r){
			if(flag)
				tr[rt].minn=1000000007;
			else
				tr[rt].minn=0;
			return;
		}
		int mid=l+r>>1;
		if(l<=mid)
			change(rt<<1,l,mid,x,flag);
		else
			change(rt<<1|1,mid+1,r,x,flag);
		if(tr[rt<<1].minn<tr[rt<<1|1].minn){
			tr[rt].minn=tr[rt<<1].minn;
			tr[rt].x=tr[rt<<1].minn;
		}else{
			tr[rt].minn=tr[rt<<1|1].minn;
			tr[rt].x=tr[rt<<1|1].minn;
		}
	}
}T[15];
bool cmpp(int x,int y){
	return max(dep[E[stk[x]].u],dep[E[stk[x]].v])<max(dep[E[stk[y]].u],dep[E[stk[y]].v]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&E[i].u,&E[i].v,&E[i].w);
	}
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fu=find(E[i].u),fv=find(E[i].v);
		if(fu==fv)
			continue;
		g[E[i].u].push_back(E[i].v);
		g[E[i].v].push_back(E[i].u);
		stk[++top]=i;
		ans+=E[i].w;
		fa[fu]=fv;
	}
	dfs(1,0);
//	for(int i=1;i<=top;i++)
//		cout<<stk[i]<<' ';
//	cout<<'*'<<'\n';
	sort(stk+1,stk+1+top,cmpp);
//	for(int i=1;i<=top;i++)
//		cout<<stk[i]<<' ';
//	cout<<'*'<<'\n';
	for(int j=1;j<=k;j++){
		long long minn=1000000007,sum=0;
		int x=0;
		scanf("%lld",&sum);
		for(int i=1;i<=n;i++){
			scanf("%lld",&dis[j][i]);
			if(minn>dis[j][i]){
				minn=dis[j][i];
				x=i;
			} 
		}
		dis[j][0]=x;
		dis[j][x]+=sum; 
	}
	for(int TT=1;TT<(1<<k);TT++){
		long long sum=0;
		for(int i=0;i<k;i++)
			if((1<<i)&TT){
				T[i+1].build(1,1,n,i+1);
				T[i+1].change(1,1,n,dis[i+1][0],0);
				sum+=dis[i+1][dis[i+1][0]];
			}
		for(int i=1;i<=top;i++){
			int u=E[stk[i]].u,v=E[stk[i]].v;
			long long w=E[stk[i]].w;
			if(dep[u]<dep[v])
				swap(u,v);
			pp t1,t2;
			int sss=0;
			t1.minn=1000000007;
			t2.minn=1000000007;
			for(int j=1;j<=k;j++){
				if((1<<(j-1))&TT){
					pp f1=T[j].query(1,1,n,st[u],ed[u]),f2=T[j].query(1,1,n,1,st[u]-1);
					if(ed[u]!=n){
						pp t=T[j].query(1,1,n,ed[u]+1,n);
						if(t.minn<f2.minn)
							f2=t;
					}
					if(f1.minn+f2.minn<=t1.minn+t2.minn){
						t1=f1;
						t2=f2;
						sss=j;
					}
				}
			}
			if(t1.minn+t2.minn<=w){
//				cout<<u<<' '<<v<<' '<<t1.minn<<' '<<t2.minn<<' '<<w<<'\n';
				sum+=t1.minn+t2.minn-w;
//				T[sss].change(1,1,n,t1.x,0);
				T[sss].change(1,1,n,t2.x,1);
			}
		}
//		cout<<sum<<' '<<TT<<"---->\n";
		if(sum<=0)
			kkkk=min(kkkk,sum);
	}
	printf("%lld",ans+kkkk);
	return 0;
}
/*
 */

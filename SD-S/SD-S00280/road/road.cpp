#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,to,nxt,w;
};
struct rp{
	int to,w;
}a[15][300005];
int n,m,k,tot1,tot,top,num,ans,fa[30005],cnt[30005],head[30005],c[15];
node mp1[3000005],mp[3000005],p[3000005];
void add1(int u,int v,int w){
	mp1[++tot1].to = v;
	mp1[tot1].u = u,mp1[tot1].w = w;
}
void add(int u,int v,int w){
	mp[++tot].to = v;
	mp[tot].nxt = head[u],mp[tot].w = w;
	mp[tot].u = u;
	head[u] = tot;
} 
int found(int x){
	if(fa[x] == x) return x;
	return fa[x] = found(fa[x]);
}
bool cmp(node x,node y){
	return x.w < y.w;
}
bool cmp1(rp x,rp y){
	return x.w < y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	int u,v,w;
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add1(u,v,w);
	}
	for(int i = 1;i <= k;i++){
		scanf("%lld",&c[i]);
		for(int j = 1;j <= n;j++){
			scanf("%lld",&a[i][j].w);
			a[i][j].to = j;
		}
	} 
	sort(mp1 + 1,mp1 + tot1 + 1,cmp);
	for(int i = 1;i <= tot1;i++){
		if(found(mp1[i].u) != found(mp1[i].to)){
			add(mp1[i].u,mp1[i].to,mp1[i].w);
			fa[found(mp1[i].u)] = found(mp1[i].to);
			num += mp1[i].w;
		}
	}
	ans = num;
	if(k == 0){
		printf("%lld",ans);
		return 0;
	}
	int s = 0,maxx = 0;
	for(int f = 1;f <= (1 << (k + 1) - 1);f++){
		num = s = 0;
		top = tot;
		for(int i = 1;i <= tot;i++) p[i].u = mp[i].u,p[i].to = mp[i].to,p[i].w = mp[i].w;
		for(int i = 1;i <= k;i++){
			if(f & (1 << (i - 1))){
				num += c[i],s++;
				for(int j = 1;j <= n;j++){
					p[++top].to = a[i][j].to;
					p[top].u = n + i,p[top].w = a[i][j].w;
				}
			}
		}
		sort(p + 1,p + top + 1,cmp);
		for(int i = 1;i <= n + k;i++) fa[i] = i;
		for(int i = 1;i <= top;i++){
			if(found(p[i].u) != found(p[i].to)){
				fa[found(p[i].u)] = found(p[i].to);
				num += p[i].w;
			}
		}
		ans = min(ans,num);
	}
	printf("%lld",ans);
	return 0;
} 

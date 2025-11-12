//road
//16点38分-- 16点48分 
//crx
/*

提交本 
估计得分:30

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,c[15],a[15][10010],k,head[10010],ans,f[10010],cnt;
bool b[15],ok;
struct edge{
	ll fr,t,w,next,s;
	bool operator > (const edge &o)const{
		return w>o.w;
	}
}e[4000010];
priority_queue <edge,vector<edge> ,greater<edge> > q;

void add(ll u,ll v,ll ww,ll sp){
	e[++cnt].next = head[u];
	head[u] = cnt;
	e[cnt].t = v;
	e[cnt].w = ww;
	e[cnt].fr = u;
	e[cnt].s = sp;
	q.push(e[cnt]);
	return ;
}

ll find(ll x){
	if(x == f[x])return x;
	f[x] = find(f[x]);
	return f[x];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		ll u,v,ww;
	scanf("%lld%lld%lld",&u,&v,&ww);
		add(u,v,ww,0);
//		add(v,u,ww);
//		q.push(e[cnt]);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i])ok=1;
		for(int j=1;j<=n;j++){
		scanf("%lld",&a[i][j]);
		}
		if(c[i] == 0){
			for(int j=1;j<=n;j++){
				for(int k=1;k<j;k++){
					if(j == k)continue;
					add(j,k,a[i][j]+a[i][k],0);//可以直接当新边 
//					q.push(e[cnt]);
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				for(int k=1;k<j;k++){
					if(j == k)continue;
					add(j,k,a[i][j]+a[i][k]+c[i],i);
//					q.push(e[cnt]);
				}
			}
		}
	}
//	if(k == 0)
	if(m>100000){
		while(!q.empty()){
			ll u=q.top().fr,v=q.top().t,ww=q.top().w,ss=q.top().s;
			q.pop();
			if(find(u) == find(v))continue;
			ans+=ww;
//			if(ss && !b[ss]){
//				b[ss]=1;
//				for(int j=1;j<=n;j++){
//					for(int k=1;k<j;k++){
//						if(j == k)continue;
//						add(j,k,a[ss][j]+a[ss][k],0);
//	//					q.push(e[cnt]);
//					}
//				}
//			}
			f[f[u]]=f[v];
		}
	}
	else{
		while(!q.empty()){
			ll u=q.top().fr,v=q.top().t,ww=q.top().w,ss=q.top().s;
			q.pop();
			if(find(u) == find(v))continue;
			ans+=ww;
			if(ss && !b[ss]){
				b[ss]=1;
				for(int j=1;j<=n;j++){
					for(int k=1;k<j;k++){
						if(j == k)continue;
						add(j,k,a[ss][j]+a[ss][k],0);
	//					q.push(e[cnt]);
					}
				}
			}
			f[f[u]]=f[v];
		}
	}
	
	cout<<ans<<'\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


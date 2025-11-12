#include<bits/stdc++.h>
using  namespace std;
#define ll long long
const int N= 1e4+10;
struct edge{
	ll u,v,w;
	int op,id;
}e[2000005];
priority_queue< pair<ll,int> >q;
ll a[N],f[N],c[20],cnt=1;
vector<int>ca[20];
ll ans;
bool st[2000005];
int find(int x){
	if(f[x]==x)return x;
	f[x]=find(f[x]);
	return f[x];
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		ll w;
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&w);
		e[i].op=0,e[i].id=i,e[i].w=w;
		q.push({-w,i});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
		}
		for(int j=1;j<=n;j++){
			for(int o=j+1;o<=n;o++){
				int w=a[j]+a[o];
				q.push({-w,++m});
				e[m].u=j,e[m].v=o,e[m].op=i,e[m].id=m,e[m].w=w;
			}
		}
	}
	int flag=0;
	while(!q.empty()){
		int u,v,w,op,id;
		int l=q.top().second;
		w=q.top().first,u=e[l].u,v=e[l].v,op=e[l].op,id=l;
		q.pop();
		if(c[op]){
			if(!st[id]){
				st[id]=1;
				ca[op].push_back(id);
				w-=c[op];
				q.push({w,id});
			}else{
				for(auto x:ca[op]){
					q.push({-e[x].w,x});
				}
				flag=c[op];
				c[op]=0;
			}
		}else if(st[id]){
			w+=c[op];
			q.push({w,id});
			st[id]=0;
		}else{
			int x=find(u);
			int y=find(v);
			if(x==y){
				flag=0;
				continue;
			}
			f[y]=x;
			if(flag)w-=flag,flag=0;
			ans+= -w;
			cnt++;
			if(cnt==n){
				break;
			}
		}
	} 
	printf("%lld",ans);
	return 0;
}
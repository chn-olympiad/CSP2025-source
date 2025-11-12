#include <bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int fa[N],n,m,k,cnt[12],sum[12],s5[N];
long long a[12];
bool c[12];
priority_queue <pair<long long,pair<int,int> >,vector<pair<long long,pair<int,int> > >,greater<> > q,q1;
int find(int k){
	if(fa[k]==k) return k;
	return fa[k]=find(fa[k]);
}
void hb(int x,int y){
	int fx=find(x);
	int fy=find(y);
	fa[fx]=fy,s5[fy]+=s5[fx];
}
long long zdl(){
	long long ans=0;
	while(!q.empty()){
		pair<long long,pair<int,int> > g=q.top();
		int u=g.second.first,v=g.second.second;
		long long s=g.first;
		q.pop();
		if(find(u)!=find(v)){
			hb(u,v);
			if(v-10000>0){
				v-=10000;
				if(c[v]) ans+=s,cnt[v]++,sum[v]+=s;
				else{
					ans+=s,cnt[v]++,sum[v]+=s;
					while(!q.empty()){
						pair<long long,pair<int,int> > g1=q.top();
						if(g1.second.first-10000==v || g1.second.second-10000==v){
							q1.push({g1.first-a[v],g1.second});
						}
						else q1.push({g1.first,g1.second});
						q.pop();
					}
					q=q1;
					while(!q1.empty())
						q1.pop();
				}
				c[v]=1;
				v+=10000;
			}
			else ans+=s;
			if(s5[find(u)]==n) break;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		fa[i]=i,s5[i]=1;
	for(int i=10001;i<=10000+k;i++)
		fa[i]=i;
	for(int i=1,u,v;i<=m;i++){
		long long s;
		scanf("%d%d%lld",&u,&v,&s);
		q.push({s,{u,v}});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		for(int j=1;j<=n;j++){
			long long s;
			int d=10000+i;
			scanf("%lld",&s);
			q.push({s+a[i],{j,d}});
		}
	}
	long long ans=zdl();
	for(int i=1;i<=k;i++){
		if(cnt[i]==1) ans-=sum[i];
	}
	cout<<ans<<'\n';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,k,k1,l,sum,ans=LLONG_MAX,y,r,cnt,u;
struct node{int a,b,x;}q[2000010];
bool cmp(node u,node w){return u.x<w.x;}
long long e[20],f[11000];
int find(int u){
	if(f[u]!=u) f[u]=find(f[u]);
	return f[u];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		scanf("%ld%ld%ld",&q[i].a,&q[i].b,&q[i].x);
	l=m;
	for(int i=1;i<=k;++i){
		cin>>e[i];
		for(int j=1;j<=n;++j){
			q[++l].a=i+n,q[l].b=j;
			scanf("%ld",&q[l].x);
		}
	}
	sort(q+1,q+l+1,cmp);
	for(int p=0;p<(1<<k);++p){
		sum=0,y=p,cnt=0,u=0;
		for(int i=1;i<=k;i++)
			if((p>>(i-1))%2==1)
				sum+=e[i],u++;
		for(int i=1;i<=n+k;++i) f[i]=i;
		for(int i=1;i<=l;++i){
			int f1=find(q[i].a),f2=find(q[i].b);
			if(f1!=f2&&(q[i].a<=n||((p>>(q[i].a-1-n))%2==1)))
				f[f1]=f2,sum+=q[i].x,cnt++;
			if(cnt==u+n-1) break;
		}	
		ans=min(sum,ans);
	}
	cout<<ans;
}
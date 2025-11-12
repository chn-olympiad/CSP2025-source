#include<bits/stdc++.h>
using namespace std;
long long n,m,k,lq,ans,f[11000];
int find(int x){
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
struct pp{
	int u,v,c;
}q[2100000];
bool ccp(pp x,pp y){
	return x.c<y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		q[++lq].u=u;
		q[lq].v=v;
		q[lq].c=c;
	}
	
	for(int i=1;i<=k;i++){
		int x,a[11000];
		cin>>x;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				q[++lq].c=a[i]+a[j];
				q[lq].u=i;
				q[lq].v=j;
			}
		}
	}
	
	sort(q+1,q+lq+1,ccp);
	
	for(int i=1;i<=lq;i++){
		if(find(q[i].u)!=find(q[i].v)){
			ans+=q[i].c;
			f[f[q[i].u]]=find(q[i].v);
		}
	}
	cout<<ans;
}

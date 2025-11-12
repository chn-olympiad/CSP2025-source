#include<bits/stdc++.h>
using namespace std;
long long n,m,k,g[15],ans=1e11,v,u,w,fa[101004],cnt=0,p[15][10005],q[15];
struct node{
	long long u,v,w;
};
node a[200005],l[200005];

int find(int x){
	if(x==fa[x]){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
bool cmp(node x,node y){
	return x.w<y.w;
}
long long kr(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	long long sum=0;
	memset(l,0,sizeof(l));
	for(int i=1;i<=m+cnt;i++){
		l[i].u=a[i].u;
		l[i].v=a[i].v;
		l[i].w=a[i].w;
	}
	sort(l+1,l+1+m+cnt,cmp);
	for(int i=1;i<=m+cnt;i++){
		int x=find(l[i].u);
		int y=find(l[i].v);
	//	cout<<l[i].u<<" "<<l[i].v<<" "<<l[i].w<<endl;
		if(x!=y){
			fa[x]=y;
			sum+=l[i].w;
			
		}
	}
	return sum;
}
void dg(int x){
	if(x==k+1){
		cnt=0;
		long long summ=0;
		for(int i=1;i<=k;i++){
			if(q[i]==1){
				for(int j=1;j<=n;j++){
					a[++cnt+m].u=n+i;
					a[cnt+m].v=j;
					a[cnt+m].w=p[n+i][j];
				}
				summ+=g[i];
			//	cout<<i<<" "; 
			}
		}
	//.	cout<<endl;
		ans=min(ans,kr()+summ);
		for(int i=m+1;i<=m+cnt;i++){
			a[i].u=0;
			a[i].v=0;
			a[i].w=0;
		}
		cnt=0;
		return;
	}
	for(q[x]=0;q[x]<=1;q[x]++){
		dg(x+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v>>u>>w;
		a[i].u=u;
		a[i].v=v;
		a[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>g[i];
		for(int j=1;j<=n;j++){
			cin>>p[n+i][j];
		}
	}
	int zzz=0;
	for(int i=1;i<=k;i++){
		if(g[i]==0){
			zzz++;
		}
	}
	if(zzz==k){
		cout<<0;
		return 0;
	} 
	dg(1);
	cout<<ans;
	return 0;
}

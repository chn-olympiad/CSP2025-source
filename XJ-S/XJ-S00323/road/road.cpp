#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,k;
const int N=1e4+10,K=15,M=1e6+10;
int p[N];
LL ans=0;
LL c[N],a[K][N];
struct Node{
	int u,v,w;
}edge[N];

bool cmp(Node x,Node y){
	return x.w<y.w;
}

bool st[N],st2[K];

int find(int x){
	if(x==p[x]){
		return x;
	}
	return p[x]=find(p[x]);
}

void solve(){
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		int pu=find(edge[i].u),pv=find(edge[i].v);
		if(pu!=pv){
			ans+=edge[i].w;
			p[pu]=pv;
		}
	}
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		p[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		st[edge[i].u]=true;
		st[edge[i].v]=true;
	}	
	if(k==0){
		solve();
		cout<<ans;
		return 0;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
		bool flag=false;
		LL res2=0;			
		int res=c[j];
		for(int i=1;i<=m;i++){
			int pu=find(edge[i].u),pv=find(edge[i].v);
			if(pu!=pv){
				int tmp=0;
				if(!flag){
					tmp+=c[j];
				}
				if(pu!=n+j)tmp+=a[j][edge[i].u];
				if(pv!=n+j)tmp+=a[j][edge[i].v];
				if(tmp<=edge[i].w){
					st2[j]=true;
					flag=true;
					ans+=tmp;
					p[pu]=n+j,p[pv]=n+j;
				}
			}
		}
	}
	solve();
	for(int i=1;i<=n;i++){
		if(!st[i]){
			LL minv=1e9;
			for(int t=1;t<=k;t++){
				if(st2[t]){
					minv=min(minv,a[t][i]);
				}
				else{
					LL tmp=1e9;
					for(int j=1;j<=n;j++){
						if(st[j]){
							tmp=min(tmp,a[t][j]);
						}
					}
					minv=min(minv,a[t][i]+tmp+c[t]);
				}
			}
			ans+=minv;			
		}
	}
	cout<<ans;
	return 0;
} 

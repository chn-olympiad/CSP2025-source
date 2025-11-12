#include<bits/stdc++.h>
#define int long long
#define bug cout<<"songge888"<<'\n';
using namespace std;
int n,m,k;
struct lyl{
	int u,v,w;
}ee[1000010],e[2000010],eee[2000010];
bool operator <(lyl a,lyl b){
	return a.w<b.w;
}
int c[15];
int a[15][100010];
int ont;
int cnt;
int fa[100110];
int val[15][100010];
int Find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=Find(fa[x]);
}
int tot;
int sum;
int ans=1e18;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		eee[i]={u,v,w};
	}
	sort(eee+1,eee+1+m);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>val[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
			
		int u=eee[i].u;
		int v=eee[i].v;
		int w=eee[i].w;
//			cout<<u<<' '<<v<<' '<<w<<'\n';
		int fu=Find(u);
		int fv=Find(v);
		if(fu==fv){
			continue;
		}
		ee[++tot]={u,v,w};
		cnt++;
		sum+=w;
		fa[fu]=fv;
		if(cnt==m-1){
			break;
		}
	}
	ans=min(ans,sum);
//	cout<<ans<<'\n';
//	cout<<tot<<'\n';
	
	m=tot;
	int M=(1<<k);
	for(int mask=1;mask<M;mask++){
		sum=0;
		ont=m;
		cnt=0;
		for(int i=1;i<=m;i++){
			e[i]=ee[i];
		}
		for(int j=0;j<k;j++){
			if((1<<j)&mask){// 表示选j 
				sum+=c[j+1]; 
				for(int i=1;i<=n;i++){
					e[++ont]={n+j+1,i,val[j+1][i]};
				}
			}
		}
		for(int i=1;i<=n+k+1;i++){
			fa[i]=i;
		}
		sort(e+1,e+1+ont);
//		cout<<mask<<' '<<ont<<'\n';
		for(int i=1;i<=ont;i++){
			
			int u=e[i].u;
			int v=e[i].v;
			int w=e[i].w;
//			cout<<u<<' '<<v<<' '<<w<<'\n';
			int fu=Find(u);
			int fv=Find(v);
			if(fu==fv){
				continue;
			}
			
			cnt++;
			sum+=w;
			fa[fu]=fv;
			if(cnt==n+k){
				break;
			}
		}
//		cout<<mask<<' '<<sum<<'\n';
//		cout<<mask<<' '<<sum<<'\n';
		if(sum<ans){
//			bug
		}
		ans=min(ans,sum);
	}
//	bug
	cout<<ans;
	return 0;
}
//17:18
// ac
// 终于过了 

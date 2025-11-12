#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,fa[10010],a[15][10010];
ll sum=1e18;
struct zk{
	int x,y;
	ll z;
};
vector<zk>e;
int find(int x){
	return(x==fa[x] ? x : fa[x]=find(fa[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int x,y;
			ll z;cin>>x>>y>>z;
			e.push_back((zk){x,y,z});
			e.push_back((zk){y,x,z});
		}
		sort(e.begin(),e.end(),[](const zk &A,const zk &B){
			return A.z<B.z;
		});
		int cnt=0;
		for(auto &a : e){
			int x=a.x,y=a.y;
			ll z=a.z;
			if(find(x)!=find(y)){
				fa[find(x)]=find(y);
				sum+=z;
				cnt++;
			}
			if(cnt==n-1)break;
		}
		cout<<sum;
	}else {
		for(int i=1;i<=m;i++){
			int x,y;
			ll z;cin>>x>>y>>z;
			e.push_back((zk){x,y,z});
			e.push_back((zk){y,x,z});
		}
		for(int i=1;i<=k;i++){
			for(int j=0;j<=n;j++)cin>>a[i][j];
		}
		for(int l=0;l<(1<<k);l++){
			vector<zk>g=e;
			int o=0,cnt=0;
			ll res=0;
			for(int i=1;i<=n+k;i++)fa[i]=i;
			for(int i=0;i<k;i++)if(l>>i&1){
				res+=a[i+1][0];o++;
				for(int j=1;j<=n;j++){
					g.push_back((zk){i+1+n,j,a[i+1][j]});
					g.push_back((zk){j,i+1+n,a[i+1][j]});
				}
			}
			if(res>sum)continue;
			sort(g.begin(),g.end(),[](const zk &A,const zk &B){
				return A.z<B.z;
			});
			for(auto &a : g){
				int x=a.x,y=a.y;
				ll z=a.z;
				if(find(x)!=find(y)){
					fa[find(x)]=find(y);
					o++;
					res+=z;
				}
				if(res>sum||cnt==n-1+o)break;
			}
			sum=min(sum,res);
		}
		cout<<sum;
	}
	return 0;
}

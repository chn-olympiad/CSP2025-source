//16 -> 40
#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005],dis[1005][1005];
struct node{
	int x,y,z;
}v[1000005];
bool cmp(node x,node y){
	return x.z<y.z;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		long long ans=0;
		int cnt=0;
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=1;i<=m;++i){
			cin>>v[i].x>>v[i].y>>v[i].z;
		}
		sort(v+1,v+1+m,cmp);
		for(int i=1;i<=m;++i){
			int fx=find(v[i].x),fy=find(v[i].y);
			if(fx==fy) continue;
			fa[fx]=fy;
			ans+=v[i].z;
			cnt++;
			if(cnt==n-1) break;
		}
		cout<<ans<<endl;
	}
	else if(n<=1000){
		int tot=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=0x3f3f3f3f;
			}
		}
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=1;i<=n;++i) dis[i][i]=0;
		for(int i=1;i<=m;++i){
			int x,y,z;
			cin>>x>>y>>z;
			dis[x][y]=min(dis[x][y],z);
			dis[y][x]=min(dis[y][x],z);
		}
		for(int l=1;l<=k;++l){
			int c;
			cin>>c;
			int t[n+5];
			for(int i=1;i<=n;++i){
				cin>>t[i];
			}
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					dis[i][j]=min(dis[i][j],t[i]+t[j]);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(dis[i][j]!=0x3f3f3f3f){
					v[++tot].x=i,v[tot].y=j,v[tot].z=dis[i][j];
				}
			}
		}
		sort(v+1,v+1+tot,cmp);
		long long ans=0;
		int cnt=0;
		for(int i=1;i<=tot;++i){
			int fx=find(v[i].x),fy=find(v[i].y);
			if(fx==fy) continue;
			fa[fx]=fy;
			ans+=v[i].z;
			cnt++;
			if(cnt==n-1) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}

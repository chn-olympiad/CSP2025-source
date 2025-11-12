#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
struct road{
	int u,v;
	int w;
}r[3000100];
int c[20],a[20][10010];
bool used[20][10010];
int fa[10010];
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	fa[find(y)]=fa[find(x)];
}
bool cmp(road x,road y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>r[i].u>>r[i].v>>r[i].w;
	for(int i=1;i<=n;i++)fa[i]=i;
	if(k==0){
		sort(r+1,r+m+1,cmp);
		ll ans=0,num=n;
		for(int i=1;i<=m;i++){
			if(find(r[i].u)!=find(r[i].v)){
				merge(r[i].u,r[i].v);
				ans+=r[i].w;
				num--;
			}
			if(num==1){
				cout<<ans;
				return 0;
			}
		}
	}
	else{
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++)cin>>a[i][j];
		}
		ll cnt=0;
		for(int i=1;i<=n*n;i++)
			r[i+m].w=1e14;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt++;
				for(int l=1;l<=k;l++){
					if(r[cnt+m].w>c[l]+a[l][i]+a[l][j]){
						r[cnt+m]={i,j,c[l]+a[l][i]+a[l][j]};
					}
				}
			}
		}
		sort(r+1,r+m+n*n+1,cmp);
		long long ans=0,num=n;
		for(int i=1;i<=m+n*n;i++){
			if(find(r[i].u)!=find(r[i].v)){
				merge(r[i].u,r[i].v);
				ans+=r[i].w;
				num--;
			}
			if(num==1){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
} 

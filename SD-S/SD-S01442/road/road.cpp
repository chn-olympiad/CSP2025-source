#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,a[13],z[13][10010],ans,ans2=1e15;
int fa[10010];
struct E{
	int fr,to,z;
}e[1000010],e2[2000010];
bool cmp(E x,E y){
	return x.z<y.z;
}
int find(int x){
	if(fa[x]==x){
		return fa[x];
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+5;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].fr>>e[i].to>>e[i].z;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			cin>>z[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			if(find(e[i].fr)!=find(e[i].to)){
				ans+=e[i].z;
				fa[find(e[i].fr)]=find(e[i].to);
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=0;i<=(1<<k)-1;i++){
		for(int j=1;j<=n+k;j++)fa[j]=j;
		int tot=0,su=0;
		cnt=0,ans=0;
		for(int j=0;j<k;j++){
			if((1<<j)&i){
				ans+=a[j+1];
				tot++;
				for(int l=1;l<=n;l++){
					e2[++cnt].fr=n+tot;
					e2[cnt].z=z[j+1][l];
					e2[cnt].to=l;
				}
			}
		}
		for(int j=cnt+1;j<=cnt+m;j++){
			e2[j].fr=e[j-cnt].fr;
			e2[j].to=e[j-cnt].to;
			e2[j].z=e[j-cnt].z;
		}
		sort(e2+1,e2+cnt+m+1,cmp);
		for(int j=1;j<=m+cnt&&su<n+tot-1;j++){
			if(find(e2[j].fr)!=find(e2[j].to)){
				ans+=e2[j].z;
				fa[find(e2[j].fr)]=find(e2[j].to);
				su++;
			}
		}
		ans2=min(ans2,ans);
	}
	cout<<ans2<<"\n";
	return 0;
}

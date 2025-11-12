#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,l,ans;
struct node{
	int u,v,w;
}p[2000005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int minv[15],in[15],c[15],a[15][100005],f[10025];
int find(int x){
	if(!f[x])return x;
	return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		++l;
		cin>>p[l].u>>p[l].v>>p[l].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];int mi=INT_MAX;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]<mi){
				mi=a[i][j];
				minv[i]=j;
			}
			p[++l]=(node){n+i,j,a[i][j]};
		}
	}
	sort(p+1,p+l+1,cmp);
	for(int i=1;i<=l;i++){
		int x=find(p[i].u),y=find(p[i].v);
		if(x==y)continue;
		f[y]=x;ans+=p[i].w;
		if(p[i].u>n)in[p[i].u-n]++;
	}
	for(int i=1;i<=k;i++)if(in[i]<1)ans-=a[i][minv[i]];
	cout<<ans;
	return 0;
}


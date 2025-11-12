#include<bits/stdc++.h>
#define N 100010
using namespace std;
typedef long long ll;
int f[1010][1010];
int n,m,k;
void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;i<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
int fa[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int merge(int x,int y){
	int t=f[x][y];
	x=find(x);y=find(y);
	t=min(t,f[x][y]);
	fa[x]=y;
	return t;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(f,0x3f,sizeof(f));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int x,y,z;
		f[x][y]=f[y][x]=min(z,f[x][y]);
	}	
	floyd();
	ll ans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=2;i<=n;i++){
		ans+=merge(1,i);
	}
	cout<<ans;
	return 0;
}
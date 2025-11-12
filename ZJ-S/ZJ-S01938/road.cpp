#include<bits/stdc++.h>
using namespace std;
struct node_bian{
	int x;
	int y;
	int z;
}b[1000001],bc[10001],ne[110001];
bool cmp(node_bian x,node_bian y){
	return x.z<y.z;
}
int w[11][10001];
int f[10011],c[11];
int vis[11];
int siz[10001];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&w[i][j]);
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++)
		f[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(find(b[i].x)==find(b[i].y))
			continue;
		int fx=find(b[i].x),fy=find(b[i].y);
		f[fx]=fy;
		bc[++cnt]=b[i];
	}
//	cout<<cnt<<endl;
	long long ans=1e18;
	for(int i=0;i<(1<<k);i++){
		long long cost=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1)
				vis[j+1]=1,cost+=c[j+1];
			else
				vis[j+1]=0;
		}
		//if(i==1023)
		//	cout<<i<<" "<<cost<<endl;
		cnt=0;
		for(int j=1;j<n;j++)
			ne[++cnt]=bc[j];
		for(int j=0;j<k;j++){
			int x=j+1;
			if(!vis[x])
				continue;
			for(int l=1;l<=n;l++){
				cnt++;
				ne[cnt].x=x+n,ne[cnt].y=l,ne[cnt].z=w[x][l];
			}
		}
		//cout<<cnt<<endl;
		sort(ne+1,ne+cnt+1,cmp);
		for(int j=1;j<=n+k;j++)
			f[j]=j;
		for(int j=1;j<=n;j++)
			siz[j]=1;
		for(int j=n+1;j<=n+k;j++)
			siz[j]=0;
		for(int j=1;j<=cnt;j++){
			//if(i==1023)
			//	cout<<cost<<" "<<ne[j].x<<" "<<ne[j].y<<" "<<ne[j].z<<endl;
			if(find(ne[j].x)==find(ne[j].y))
				continue;
			//if(i==1023)
			//	cout<<cost<<" "<<ne[j].x<<" "<<ne[j].y<<" "<<ne[j].z<<endl;
			int fx=find(ne[j].x),fy=find(ne[j].y);
			f[fx]=fy;siz[fy]+=siz[fx];
			cost+=ne[j].z;
			if(siz[fy]==n)
				break;
			//cout<<cost<<endl;
		}	
		//if(i==0||i==1023)	
		//	cout<<i<<" "<<cost<<endl;
		ans=min(ans,cost);
	}
	cout<<ans;
	return 0;
}

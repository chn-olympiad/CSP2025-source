#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,ans,t[15][1000005],w[15],p[15][10005],f[10005],j,jj,xx,yy,x,y,z,s;
vector<int> a[1000005];
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
struct xxx{
	int x,y,z;
}b[1000005];
bool cmp(xxx i,xxx j){
	return i.z<j.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++){
		cin>>b[i].x>>b[i].y>>b[i].z;
	}
	for(i=1;i<=k;i++){
		cin>>w[i];
		for(j=1;j<=n;j++){
			cin>>p[i][j];
		}
	}
	sort(b+1,b+m+1,cmp);
	for(i=1;i<=m;i++){
		int x=b[i].x,y=b[i].y,z=b[i].z,xx=0,yy=0;
		if(find(x)!=find(y)){
			f[find(x)]=find(y);
			for(j=1;j<=k;j++){
				if(p[j][x]+p[j][y]+w[j]<z){
					z=p[j][x]+p[j][y]+w[j];
					jj=j;xx=x;yy=y;
				}
			}
			if(xx==x&&yy==y){
				p[jj][xx]=p[jj][yy]=w[jj]=0;
			}
			a[x].push_back(y);
			a[y].push_back(x);
			for(j=1;j<=k;j++){
				p[j][x]=min(p[j][x],p[j][y]);
				for(int l=0;l<a[x].size();l++){
					int v=a[x][l];
					p[j][v]=min(p[j][v],p[j][y]);
				}
			}
			for(j=1;j<=k;j++){
				p[j][y]=min(p[j][x],p[j][y]);
				for(int l=0;l<a[y].size();l++){
					int v=a[y][l];
					p[j][v]=min(p[j][v],p[j][x]);
				}
			}
			ans+=z;s++;
		}
		if(s==n-1) break;
	}
	cout<<ans;
}
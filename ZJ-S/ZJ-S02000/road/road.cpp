#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,vscode,cs,v[10010],a[10010][10010],c[15],b[15][10010];
struct road{
	int x,y,z;
}r[1000010];
bool cmp(road a,road b){
	return a.z<b.z;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			a[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		int ii,j,k;
		cin>>ii>>j>>k;
		a[ii][j]=a[j][ii]=k;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>b[j][i];
		}
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
				a[i][k]=a[k][i]=min(a[i][k],c[j]+b[j][i]+b[j][k]);
			}
		}
	}
	int mm=0;
	for(int i=1;i<=n+1;i++){
		for(int j=i;j<=n+1;j++){
			if(a[i][j]!=INT_MAX){
				r[++mm]={i,j,a[i][j]};
			}
		}
	}
	m=mm;
	sort(r+1,r+m+1,cmp);
	v[1]=1;
	vscode=1;
	for(int i=1;i<=m;i++){
		if(vscode==n){
			cout<<cs;
			return 0;
		}
		if(v[r[i].x]==0&&v[r[i].y]==0){
			v[r[i].x]=v[r[i].y]=i+1;
		}else if(v[r[i].x]==0){
			if(v[r[i].y]==1){
				vscode++;
			}
			v[r[i].x]=v[r[i].y];
		}else if(v[r[i].y]==0){
			if(v[r[i].x]==1){
				vscode++;
			}
			v[r[i].y]=v[r[i].x];
		}else if(v[r[i].y]==v[r[i].x]){
			continue;
		}else{
			if(min(v[r[i].x],v[r[i].y])==1){
				int t=max(v[r[i].x],v[r[i].y]);
				for(int i=1;i<=n;i++){
					if(v[i]==t){
						v[i]=1;
						vscode++;
					}
				}
			}else{
				int t=max(v[r[i].x],v[r[i].y]),tt=min(v[r[i].x],v[r[i].y]);
				for(int i=1;i<=n;i++){
					if(v[i]==t){
						v[i]=tt;
					}
				}
			}
		}
		cs+=r[i].z;
		cout<<r[i].x<<' '<<r[i].y<<' '<<r[i].z<<"   COSTS NOWW  :"<<cs<<' '<<vscode<<'\n';
	}
	return 0;
}

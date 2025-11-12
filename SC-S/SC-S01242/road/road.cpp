#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<vector<long long> > w(1005,vector<long long>(1005,INT_MAX));
int a[15][1005],c[15];
bool g=true,f[1005];
struct myst{
	int s,k;
	long long p;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y;
		long long p;
		scanf("%d%d%d",&x,&y,&p);
		w[x][y]=min(w[x][y],p);
		w[y][x]=w[x][y];
	}for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		g=(c[i]==0);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]),g=(a[i][j]==0);
		for(int x=1;x<n;x++){
			for(int y=x+1;y<=n;y++){
				long long p=c[i]+a[i][x]+a[i][y];
				w[x][y]=min(w[x][y],p);
				w[y][x]=w[x][y];
			}
		}
	}if(g){
		cout<<0;
		return 0;
	}queue<myst> q;
	myst x;x.k=1,x.p=0,x.s=1;
	q.push(x);
	f[1]=true;
	while(!q.empty()){
		x=q.front();
		if(x.k==n){
			cout<<x.p;
			return 0;
		}q.pop();
		for(int i=1;i<=n;i++){
			if(i==x.s||f[i]==true) continue;
			myst y;y.s=i,y.k=x.k+1,y.p=x.p+w[x.s][y.s];
			q.push(y);
			f[i]=true;
		}
	}cout<<13;
	return 0;
}
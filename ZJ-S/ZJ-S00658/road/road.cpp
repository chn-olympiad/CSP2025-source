#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,d[1010][1010],f[1010][1010],a[1010];
int ans,ss=INT_MAX,zgl[1010][1010];
bool b[1010],bb[1010][1010],g[1010],tt[1010],l=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=w;
		bb[u][v]=bb[v][u]=1;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)cin>>f[i][j];
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			int s1=INT_MAX,xb1,jz;
			for(int j=1;j<=n;j++){
				int s2=INT_MAX;
				if(i==j)continue;
				int t=0,xb2=-1;
				for(int h=1;h<=k;h++){
					t=a[h]+f[h][i]+f[h][j];
					if(g[h])t-=a[h];
					if(s2>t){
						s2=t;
						xb2=h;
					}
				}
				if(bb[i][j]){
					if(d[i][j]<s2){
						s2=d[i][j];
						xb2=-1;
					}
				}
				if(s2<s1){
					s1=s2;
					xb1=xb2;
					jz=j;
				}
			}
			ans+=s1;
			if(xb1!=(-1))g[xb1]=1;
			else{
				bb[i][jz]=0;bb[jz][i]=0;
			}
			b[i]=1;
			b[jz]=1;
			tt[i]++;tt[jz]++;
			zgl[i][jz]=zgl[jz][i]=1;
		}
	}
	for(int i=1;i<=n;i++)if(tt[i]>1)l=0;
	if(l){
		for(int i=1;i<=n;i++){
			int s1=INT_MAX;
			for(int j=1;j<=n;j++){
				if(zgl[i][j])continue;
				int s2=INT_MAX;
				if(i==j)continue;
				int t=0;
				for(int h=1;h<=k;h++){
					t=a[h]+f[h][i]+f[h][j];
					if(g[h])t-=a[h];
					if(s2>t)s2=t;
				}
				if(bb[i][j]){
					if(d[i][j]<s2)s2=d[i][j];
				}
				if(s2<s1)s1=s2;
			}
			ss=min(s1,ss);
		}
	}
	cout<<ans+ss;
	return 0;
}

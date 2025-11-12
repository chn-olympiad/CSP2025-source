#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+5;
int n,m,k;
int f[MAX][MAX],c[MAX];
bool vis[MAX];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	f[u][v]=w;
//    	f[v][u]=w;
	}
	int b=m;
    for(int i=1;i<=k;i++){
    	int a,d;
    	cin>>d;
    	m++;
    	c[m]=d;
        for(int j=1;j<=n;j++){
        	cin>>a;
        	f[m][j]=a;
		}
	}
	int ans=0;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			if(f[i][j]==0) f[i][j]=1e6;
		}
	}
    for(int p=1;p<=n;p++){
    	for(int i=p+1;i<=n;i++){
    		for(int j=p;j<=n+k;j++){
    			int mm;
                mm=min(f[p][j]+f[j][i],f[p][i]);
//                if(mm==(f[i][p]+f[p][j])&&p>n){
//                	if(vis[p]==0)
//                	{
//                		vis[p]=1;
//                	mm+=c[p];
//                }
//				}
                f[p][i]==mm;
			}
		}
	}
    for(int i=1;i<=n+k;i++){
    	for(int j=i+1;j<=n+k;j++){
    		if(f[i][j]!=1e6) {
			ans+=f[i][j];}
		}
	}
    cout<<ans;
	return 0;
}
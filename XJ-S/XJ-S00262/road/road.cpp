#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long a[(int)1e4+20][(int)1e4+20];
long long city[20];
long long ans=0;
int main() {
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=1e4;i++) {
        a[i][i]=-1;
    }
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        long long u,v,w;
        cin>>u>>v>>w;
        a[u][v]=min(a[u][v],w);
        a[v][u]=min(a[v][u],w);
    }
    for(int i=1;i<=k;i++) { //city1 =n+1
        cin>>city[i];
        for(int j=1;j<=n;j++) {
            cin>>a[n+i][j];
            a[j][n+i]=a[n+i][j];
            ans+=city[i];
        }
    }
    for(int l=1;l<=n+k;l++) {
        for(int i=1;i<=n+k;i++) {
            for(int j=1;j<=n+k;j++) {
                if(a[i][l]!=-1&&a[l][j]!=-1) {
                    a[i][j]=min(a[i][j],a[i][l]+a[l][j]);
                }
            }
        }
    }
    for(int i=2;i<=n;i++) {     //1-4 point
        ans+=a[i-1][i];
    }
    cout<<ans;

    // 5 6 0 1 3 3 3 2 2 2 5 4 5 4 2 4 1 1 4 3 2 0 0 0 0 0 0
    //
    return 0;
}
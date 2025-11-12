#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int cost[10005][10005];
int ds[10005][10005];
int ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    memset(cost,127,sizeof(cost));
    memset(ds,127,sizeof(ds));
    for(int i=1;i<=m;i++){
            int r,v,w;
        scanf("%d%d%d",&r,&v,&w);
        cost[r][v]=w;
        cost[v][r]=w;
    }
    /*
    for(int i=1;i<=k;i++){
      //    scanf("%d",&
        for(int j=1;j<=n;j++){
            scanf("%d")
        }
    }
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ds[i][j]=min(ds[j-1][j],min(ds[i][j],cost[i][j]));
            ds[j][i]=ds[i][j];
        }
    }
    for(int i=1;i<n;i++){
    //        cout<<ds[i][i+1]<<" ";
        ans+=ds[i][i+1];
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>>road(n+1,vector<int>(n+1,INT_MAX));
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        road[u][v]=w;
        road[v][u]=w;
    }
    vector<vector<int>>A(k,vector<int>(n+1));
    for(int i=0;i<k;i++)
    {
        cin>>A[i][0];
        for(int j=0;j<n;j++)
            cin>>A[i][j+1];
    }
    sort(road.begin(),road.end());
    int num=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int x=0;x<k;x++)
            {
                if(road[i][j]!=INT_MAX)
                    num+=min(A[x][i]+A[x][j],road[i][j]);
                else num+=A[x][i]+A[x][j];
            }
        }
    }
    cout<<num;
    return 0;
}

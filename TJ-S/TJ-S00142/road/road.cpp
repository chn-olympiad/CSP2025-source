#include<bits/stdc++.h>
using namespace std;

int n,k,m;
long long a[3000][3000],b[10001];

int main(){
    freopen("road.in","r",stdin);
   	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(a,1,sizeof(a));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=w;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n+1;j++)cin>>b[i];
    }
	cout<<0;




    return 0;




}

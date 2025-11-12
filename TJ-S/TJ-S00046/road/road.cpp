#include<bits/stdc++.h>     //...............
using namespace std;
const int N=1e4+10,M=1e6+10,K=20;
int n,m,k;
int v[N][N];
queue <int> q;
int r[N][M];

void add(int U,int V,int W){
    r[U][++r[U][0]]=V;
    v[U][V]=W;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int U,V,W;
        cin>>U>>V>>W;
        add(U,V,W);
        add(V,U,W);
    }
    return 0;
}
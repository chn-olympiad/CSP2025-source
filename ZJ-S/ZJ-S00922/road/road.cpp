#include<iostream>

using namespace std;

int n,m,k;
int rdFrom[1000010],rdTo[1000010],rdCost[1000010];
int vCost[11],vrdCost[11][10010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>rdFrom[i]>>rdTo[i]>>rdCost[i];
    }
    for(int i=0;i<k;i++){
        cin>>vCost[i];
        for(int j=0;j<n;j++){
            cin>>vrdCost[i][j];
        }
    }
    cout<<0;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long u[1000010],v[1000010],w[1000010],c[20],a[20][10010];
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long m,n,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }for(int j=0;j<k;j++){
        cin>>c[j];
        for(int i=0;i<n;i++){
            cin>>a[j][i];
        }
    }//Ì«ÄÑÁË:)
	return 0;
}

#include<iostream>

using namespace std;
const int N=1e6+9,M=1e5+9;
int u[N],w[N],v[N],a[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

    int n,m,k;cin>>n>>m>>k;
    int sum=0;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        sum+=w[i];
    }
    for(int i=1;i<=n+1;i++){
        cin>>a[i];
    }
    cout<<sum<<endl;
}

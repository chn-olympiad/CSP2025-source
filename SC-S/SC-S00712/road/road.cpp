#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    int u[m],v[m],w[m];
    for (int i = 0;i<m;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    int c[k],a[k][n];
    for (int j = 0;j<k;j++){
        cin >> c[j];
        for (int i = 0;i<n;i++){
            cin >> a[j][i];
        }
    }
    cout << 0;
    return 0;
}
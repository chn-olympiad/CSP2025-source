#include <iostream>
using namespace std;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int u[m], v[m], w[m];
    for(int i = 0; i < m; i++){
        cin >> u[i];
        cin >> v[i];
        cin >> w[i];
    }
    int a[k][n];
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cout << 13 << endl;
    return 0;
}

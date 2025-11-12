#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n*m];
    for(int i = 0; i < n*m; i++){
        cin >> a[i];
    }
    int r = a[0];
    if(n == 1 && m == 1){
        cout << 1 << ' ' << 1;
    }
    else{
        sort(a, a + n*m);
        int temp = n*m;
        int a2[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a2[j][i] = a[temp];
                if(r == a[temp]){
                    cout << j+1 << ' ' << i+1 << endl;
                    return 0;
                }
                temp--;
            }
        }
    }

    return 0;
}

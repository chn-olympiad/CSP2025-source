#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int Ra = a[1][1];
    int R = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(Ra < a[i][j]){
                R++;
            }
        }
    }

    cout << R / n << " ";
    if((R / n) % 2 == 0){
        cout << R % n;
    }
    else{
        cout << n - (R % n);
    }
    return 0;
}

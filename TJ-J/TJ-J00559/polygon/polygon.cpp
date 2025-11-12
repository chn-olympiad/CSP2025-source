#include <iostream>
using namespace std;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n < 3){
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    int a1[3];
    a1[0] = a[0];
    a1[1] = a[1];
    a1[1] = a[2];
    int max1 = a1[0];
    if(a1[1] > max1){
        max1 = a1[1];
    }
    if(a1[2] > max1){
        max1 = a1[2];
    }
    int sum = 0;
    for(int g = 0; g < 3; g++){
        sum += a1[g];
    }
    if(sum > max1*2){
        cout << 1 << endl;
    }
    cout << 0 << endl;
    return 0;
}


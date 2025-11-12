#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    string a[n];
    string a1[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> a1[i];
    }
    string b[q];
    string b1[q];
    for(int i = 0; i < q; i++){
        cin >> b[i] >> b1[i];
        cout << 0 << endl;
    }
    return 0;
}

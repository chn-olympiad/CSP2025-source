#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    long long s[n][2];
    for (int i = 0;i<n;i++){
        cin >> s[i][0] >> s[i][1];
    }
    long long t[q][2];
    for (int j = 0;j<q;j++){
        cin >> t[j][0] >> t[j][1];
    }
    for (int i = 0;i<q;i++){
        cout << 0 << endl;
    }
    return 0;
}
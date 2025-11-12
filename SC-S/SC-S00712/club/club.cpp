#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin >> t;
    int ans[t];
    for (int j = 0;j<t;j++) {
        ans[j] = 0;
        cin >> n;
        int a[3];
        for (int i = 0;i <n;i++) {
            cin >> a[0] >> a[1] >> a[2];
            int f = max(a[0],max(a[1],a[2]));
            ans[j] += f;
        }
    }
    for (int i = 0;i<t;i++){
        cout << ans[i] << endl;
    }

    return 0;
}
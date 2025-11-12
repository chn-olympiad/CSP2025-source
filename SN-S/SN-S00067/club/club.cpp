#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int a[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++){
            int b,c;
            cin >> a[i] >> b >> c;
        }
        sort(a+1,a+n+1);
        int cnt = 0;
        for(int i = 1;i <= n/2;i++){
            cnt+=a[i];
        }
        cout << cnt << endl;
    }

    return 0;
}

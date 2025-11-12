#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",polyin)
    freopen("polygon.out","w",polygonout)
    bool n[5001];
    int m,a,b,c,d,e;
    cin >> m >> a >> b >> c >> d >> e;
    int cnt;
    cin >>cnt;
    for(int i = 0;i <=n;i++){
        if(a+b+c || a+b+d || a+b+e || b+c+d || b+d+e || c+d+e){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

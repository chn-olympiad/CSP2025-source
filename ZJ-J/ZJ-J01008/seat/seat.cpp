#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
       cin >> a[i];
    }
    int cnt = a[1];
    sort(a + 1,a + n * m + 1,greater<int>());
    int h = 1,l = 1;
    bool flag = 1;
    for(int i = 1;i <= n * m;i++){
        if(cnt == a[i]){
            cout << l << " " << h;
            break;
        }
        if(flag){
            h++;
            if(h > n){
                h--;
                l++;
                flag = 0;
            }
        }else{
            h--;
            if(h < 1){
                h++;
                l++;
                flag = 1;
            }
        }
    }



    return 0;
}
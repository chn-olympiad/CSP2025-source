#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define endl '\n'

using namespace std;
using LL = long long;

int a[105], n, m, x;

bool cmp(int x, int y){
    return x > y;
}

int main(){

    //seat2 对拍用
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    IOS

    cin >> n >> m;
    for(int i = 1; i <= n*m; i ++)cin >> a[i];
    x = a[1];
    //x是小R的分数
    sort(a+1, a+n*m+1, cmp);

    //找到小R的位置
    int t;
    for(int i = 1; i <= n*m; i ++){
        if(a[i] == x){
            t = i;
            break;
        }
    }

    int cnt = 0;
    for(int i = 1; i <= m; i ++){
        if(i % 2 == 1){
            for(int j = 1; j <= n; j ++){
                cnt++;
                if(cnt == t){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }else{
            for(int j = n; j >= 1; j --){
                cnt++;
                if(cnt == t){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
        
    }
   

    return 0;
}
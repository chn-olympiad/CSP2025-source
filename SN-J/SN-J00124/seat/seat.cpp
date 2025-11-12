#include<bits/stdc++.h>

using namespace std;

int a[110];

bool cmp(int x,int y){
    return x > y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int b = 0;
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
        if(i == 1){
            b = a[i];
        }
    }
    sort(a+1,a+n*m+1,cmp);
    int x = 1,y = 1,flag = 0;
    for(int i = 1;i <= n*m;i++){
        if(a[i] == b){
            cout << x << " " << y;
            return 0;
        }
        if(y == 1&&flag){
            x++;
            flag = 0;
        }else if(y == n&&!flag){
            x++;
            flag = 1;
        }else if(flag){
            y--;
        }else{
            y++;
        }
    }
    return 0;
}


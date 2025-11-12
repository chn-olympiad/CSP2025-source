#include <bits/stdc++.h>
using namespace std;
int cnt,n,m,a[105],x,y;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n*m;i++){
        cin >> a[i];
    }
    a[0] = a[1];
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++){
        if (a[i] == a[0]){
            cnt = i;
            break;
        }
    }
    x = (cnt-1)/n+1;
    if (x % 2 == 1){
        y = (cnt-1)%n+1;
    }else{
        y = n-(cnt-1)%n;
    }
    cout << x << " " << y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


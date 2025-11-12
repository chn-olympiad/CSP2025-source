#include<bits/stdc++.h>
using namespace std;
int a[10000];
int ans[10000][10000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b,c = 0;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    int ans = a[1];
    for(int i = 1;i <= n * m;i++){
        for(int j = i;j <= n * m;j++){
            if(a[i] < a[j]){
                b = i;
                i = j;
                j = b;
            }
        }
    }
    for(int i = 1;i <= n;i = i + 2){
        for(int j = 1;j <= m;j++){
            c++;
            if(a[c] = ans){
                cout << i << ' ' << j;
            }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5001],maxx = 0;
long long sum = 0,cnt = 0;

void dfs(int d){
    int backup;
    if(maxx > sum){
        cnt++;
        return;
    }
    for(int i = d;i <= n;i++){
        sum += a[i];
        if(maxx < 2*a[i]){
            backup = maxx;
            maxx = 2*a[i];
        }
        dfs(d+1);
        sum -= a[i];
        maxx = backup;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    dfs(1);
    cout << cnt % 998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

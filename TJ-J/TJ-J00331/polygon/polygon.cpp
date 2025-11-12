#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int a[N],ans = 0;
void dfs(int depth,int max_now,int now_all,int now_number,bool vis){
    if (now_number>=3 && now_all>max_now*2 && vis==true){
        ans++;
    }
    dfs(depth+1,max(max_now,a[depth]),now_all+a[depth],now_number+1,true);
    dfs(depth+1,max_now,now_all,now_number,false);
}
int main(){
    memset(vis,false,sizeof vis);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
    }
    dfs(1,0,0,0,false);
    cout << ans;
}

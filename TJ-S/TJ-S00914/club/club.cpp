#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int n;
int ans = 0, cnt = 0;
int a1[maxn], a2[maxn], a3[maxn];
int b1 = 0, b2 = 0, b3 = 0;
bool v[maxn];
void dfs(int k){
    if(cnt > ans){
        ans = cnt;
        if(k == n+1) return;
    }
    for(int i = k; i <= n; i++){
    	if(v[i]) continue;
        v[i] = 1;
        if(b1 < n/2){
            b1++;
            cnt += a1[i];
            dfs(i+1);
            cnt -= a1[i];
            b1--;
        }
        if(b2 < n/2){
            b2++;
            cnt += a2[i];
            dfs(i+1);
            cnt -= a2[i];
            b2--;
        }
        if(b1 < n/2){
            b3++;
            cnt += a3[i];
            dfs(i+1);
            cnt -= a3[i];
            b3--;
        }
        v[i] = 0;
    }
    return;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t){
    	t--;
    	memset(v, 0, n);
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a1[i] >> a2[i] >> a3[i];
        }
        dfs(1);
        cout << ans << endl;
        ans = 0;
        cnt = 0;
        b1 = 0;
        b2 = 0;
        b3 = 0;
    }
    return 0;
}

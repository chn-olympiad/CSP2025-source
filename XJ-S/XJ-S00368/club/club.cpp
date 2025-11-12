#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n;
struct sdf{
    int a, b, c, d;
}mem[N];
bool cmp(sdf x, sdf y){
    return x.d > y.d;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t --){
        cin >> n;
        long long ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i = 1; i <= n; ++ i){
            cin >> mem[i].a >> mem[i].b  >> mem[i].c;
            int mx = max(mem[i].a, mem[i].b);
            mx = max(mx, mem[i].c);
            ans += mx;
            if(mx == mem[i].a){
                cnt1 ++;
                mem[i].a -= mx, mem[i].b -= mx, mem[i].c -= mx;
                mem[i].d = max(mem[i].c, mem[i].b);
            } 
            else if(mx == mem[i].b){
                cnt2 ++;
                mem[i].a -= mx, mem[i].b -= mx, mem[i].c -= mx;
                mem[i].d = max(mem[i].a, mem[i].c);
            } 
            else{
                cnt3 ++;
                mem[i].a -= mx, mem[i].b -= mx, mem[i].c -= mx;
                mem[i].d = max(mem[i].a, mem[i].b);
            } 
        }
        sort(mem + 1, mem + n + 1, cmp);
        int x = 0, flag = 0;
        if(cnt1 > (n / 2)) x = cnt1 - (n / 2), flag = 1;
        else if(cnt2 > (n / 2)) x = cnt2 - (n / 2), flag = 2;
        else x = cnt3 -(n / 2), flag = 3;
        for(int i = 1; i <= x; ++ i){
            if(flag == 1 && mem[i].a != 0){
                x ++;
                continue;
            } 
            if(flag == 2 && mem[i].b != 0){
                x ++;
                continue;
            } 
            if(flag == 3 && mem[i].c != 0){
                x ++;
                continue;
            } 
            ans += mem[i].d;
        }
        cout << ans << endl;
    }
    return 0;
}
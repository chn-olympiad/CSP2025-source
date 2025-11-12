#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define MOD 998244353ll


using namespace std;
using LL = long long;

const int N = 1e5+5;

string s;
int a[505];
int main(){

    IOS
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    
    int n, m;
    cin >> n >> m >> s;
    for(int i = 0; i < n; i ++)cin >> a[i];

    if(n <= 18){
        vector<int>pailie(n);
        LL sum = 0;
        for(int i = 0; i < n; i ++)pailie[i] = i;
        do{
            LL fangqi = 0, luqu = 0;
            for(int i = 0; i < n; i ++){
                //循环 全排列
                if(s[i] == '1' && a[pailie[i]] - fangqi > 0){
                    //如果难度较低  并且  当前人的耐心值 减去 前面已经放弃的人数 > 0， 则可以被录取
                    luqu ++;
                }else{
                    fangqi++;
                }
            }
            if(luqu >= m)sum ++;

        }while(next_permutation(pailie.begin(), pailie.end()));
        cout << sum << endl;
    }else {
        //计算全排列
        LL ans = 1;
        for(LL i = 1; i <= n; i ++){
            ans = (ans * i) % MOD;
        }
        cout << ans << endl;
    }


    return 0;
}

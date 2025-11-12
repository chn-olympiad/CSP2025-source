#include <iostream>
#include <map>
#include <cstring>
#define pss std::pair<std::string, std::string>
using std::cin;
using std::cout;
const int N = 2e5 + 5, M = 5e6 + 5;
int n, q;
std::map<pss, int> mp;
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    std::string a, b;
    for (int i = 1; i <= n; i++){
        cin >> a >> b;
        mp[{a, b}]++;
    }
    for (int i = 1; i <= q; i++){
        cin >> a >> b;
        int l = 0, r = a.length() - 1;
        while(a[l] == b[l] && l <= r) l++;
        while(a[r] == b[r] && r >= l) r--;
        int ans = 0;
        std::string x, y;
        for (int f = 0; f <= l; f++){
            x = a.substr(f, a.length()),
            y = b.substr(f, a.length());
            for (int g = a.length() - 1; g >= r; g--){
                ans += mp[{x, y}];
                x.pop_back(), y.pop_back();
            }
        }
        cout << ans << '\n';
    }
}
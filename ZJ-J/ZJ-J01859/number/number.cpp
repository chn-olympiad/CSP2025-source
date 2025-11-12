/*   __    __   _______   __        __        _______
    / /   / /  / _____/  / /       / /       / ___  /
   / /___/ /  / /____   / /       / /       / /  / /
  / ____  /  / _____/  / /       / /       / /  / /
 / /   / /  / /____   / /____   / /____   / /__/ /
/_/   /_/  /______/  /______/  /______/  /______/
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
vector<int> num;

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    for(int i=0; i<s.size(); ++i)
        if('0'<=s[i] && s[i]<='9')
            num.push_back(s[i]-'0');
    sort(num.begin(), num.end(), greater<int>());
    
    for(int x:num) cout << x;
    cout << '\n';
    return 0;
}
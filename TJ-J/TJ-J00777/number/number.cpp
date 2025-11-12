#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    for (int i=0;i<s.size();i++){
        if (s[i]>='0' && s[i]<='9') v.push_back((int)(s[i]-48));
    }
    sort(v.begin(),v.end(),greater<int>());
    for (int i=0;i<v.size();i++) cout<<v[i];
    return 0;
}

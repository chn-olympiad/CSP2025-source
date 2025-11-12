#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
//#define int long long
using namespace std;

signed main(void){
    IOS;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int>v;
    for(int i=0;s[i];i++){
        if('0'<=s[i]&&s[i]<='9')v.push_back(-(s[i]-'0'));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<-v[i];
    }
    return 0;
}
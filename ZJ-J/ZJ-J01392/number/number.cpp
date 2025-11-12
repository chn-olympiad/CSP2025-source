#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=200005;
const int INF=0x3f3f3f3f;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string res="";
    for(int i=0;i<(int)s.size();i++){
        if(s[i]>='0'&&s[i]<='9') res.push_back(s[i]);
    }
    sort(res.begin(),res.end());
    reverse(res.begin(),res.end());
    cout<<res<<"\n";
    return 0;
}


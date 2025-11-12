#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;
int q,n;
string s[N][3],t1,t2;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    while(q--){
        ll ans=0;
        cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            if(t1==s[i][1]&&t2==s[i][2]){
                ans++;continue;
            }
            ll tmp=t1.find(s[i][1]);
            string a1=t1;
            if(tmp==-1) continue;
            a1.replace(tmp,s[i][1].size(),s[i][2]);
            if(a1==t2){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

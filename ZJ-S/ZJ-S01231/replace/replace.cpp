#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+114;

int n,q;
string s[MAXN][2];
string t1,t2;


int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    while(q--){
        int ans = 0;
        cin>>t1>>t2;
        for(int i = 1;i<=n;i++){

            string t = t1;
            int pos = t.find(s[i][0]);
            for(int j = 0;j<s[i][0].size();j++){
                t[j+pos] = s[i][1][j];
            }
            if(t == t2) ans++;
            
        }
        cout<<ans<<"\n";
    }
}
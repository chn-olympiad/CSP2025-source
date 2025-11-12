#include<bits/stdc++.h>
using namespace std;
unordered_map<string, string> rp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a, b;
        cin>>a>>b;
        rp[a]=b;
    }
    while(q--){
        string t1, t2;
        cin>>t1>>t2;
        int cnt = 0;
        for(auto i:rp){
            auto it = t1.find(i.first);
            if(it != string::npos){
                string tt = t1;
                tt.replace(it,i.second.size() ,i.second);
                if(tt == t2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
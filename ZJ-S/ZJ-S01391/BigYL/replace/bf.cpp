#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
// #define vector basic_string
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;cin>>n>>q;
    vector<string>v1(n+1),v2(n+1);
    for(int i=1;i<=n;i++){
        cin>>v1[i]>>v2[i];
    }
    while(q--){
        string s1,s2;cin>>s1>>s2;
        if((int)s1.length()!=(int)s2.length()){
            cout<<"0\n";
            continue;
        }
        int l=-1,r=-1;
        for(int i=0;i<(int)s1.length();i++){
            if(s1[i]!=s2[i]){
                if(l==-1)l=i;
                r=i;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(v1[i].length()<r-l+1){
                continue;
            }
            for(int j=max((int)v1[i].length()-1,r);j<(int)s1.length();j++){
                bool g=1;
                for(int k=j-(int)v1[i].length()+1;k<=j;k++){
                    if(s1[k]!=v1[i][k-(j-(int)v1[i].length()+1)]){
                        g=0;break;
                    }
                    if(s2[k]!=v2[i][k-(j-(int)v1[i].length()+1)]){
                        g=0;break;
                    }
                }
                ans+=g;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
g++ -std=c++14 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
*/
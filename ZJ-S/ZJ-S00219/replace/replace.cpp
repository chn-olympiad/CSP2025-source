/*
T3 replace.cpp
ZJ-S00219 shicj
??pts

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s[200005];
string t[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int l=s1.size(),r=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                l=min(l,i);
                r=max(r,i);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s[i].size()<r-l+1){
                continue;
            }
            for(int j=0;j<=(int)s1.size()-(int)s[i].size();j++){
                bool flag=1;
                if(j>l||j+(int)s[i].size()-1<r){
                    continue;
                }
                for(int k=0;k<s[i].size();k++){
                    if(s1[j+k]!=s[i][k]||s2[j+k]!=t[i][k]){
                        flag=0;
                    }
                }
                if(flag){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
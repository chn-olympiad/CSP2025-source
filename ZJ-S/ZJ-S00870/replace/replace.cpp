#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,q;
string s1[200005],s2[200005];
vector<int> nxt[200005];
string t1,t2;
signed main(){
    //freopen("replace1.in","r",stdin);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0;
            continue;
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int l=0;l<t1.size();l++){
                int r;
                for(int r=0;r<s1[j].size();r++){
                    if(l+r>=t1.size()) break;
                    if(t1[l+r]!=s1[j][r]) break;
                }
                if(r==s1[j].size()){
                    string ne=t1.substr(0,l)+s2[j]+t1.substr(l+r,t1.size()-l-r+1);
                    if(ne==s2[j]){
                        ans++;
                    }
                }
            }

        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

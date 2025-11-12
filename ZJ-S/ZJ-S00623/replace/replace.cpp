#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=2e5+10;
ll n,q,nxt[N],ans;
string s[N],t[N],ss,tt;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i]>>t[i],s[i]=" "+s[i],t[i]=" "+t[i];
    while(q--){
        cin>>ss>>tt;ss=" "+ss,tt=" "+tt;ans=0;
        if(ss.size()!=tt.size()){cout<<"0\n";continue;}
        for(int k=1;k<=n;k++){
            ll m=s[k].size()-1,n=ss.size()-1;
            for(int j=0;j<=m;j++) nxt[j]=0;
            for(int i=2,j=0;i<=m;i++){
                while(j&&s[k][i]!=s[k][j+1]) j=nxt[j];
                nxt[i]=(j+=(s[k][i]==s[k][j+1]));
            }
            for(int i=1,j=0;i<=n;i++){
                while(j&&ss[i]!=s[k][j+1]) j=nxt[j];
                j+=(ss[i]==s[k][j+1]);
                // cerr<<j<<"\n";
                if(j==m){
                    // cerr<<k<<" "<<i<<"\n";
                    for(int p=i-m+1;p<=i;p++)
                        ss[p]=t[k][p-(i-m+1)+1];
                    if(ss==tt) ans++;
                    for(int p=i-m+1;p<=i;p++)
                        ss[p]=s[k][p-(i-m+1)+1];
                }
            }
        }
        cout<<ans<<"\n";
        // cerr<<"\n";
    }
    return 0;
}
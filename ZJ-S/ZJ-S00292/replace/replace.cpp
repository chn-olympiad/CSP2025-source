#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+5;

int n,q;
char s[3][N][N],a[N],b[N],la[N];
int na,nb;

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            cin>>s[j][i]+1;
        }
    }
    while(q--){
        cin>>a+1>>b+1;
        na=strlen(a+1);
        nb=strlen(b+1);
        if(na!=nb){
            cout<<"0\n";
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int zn=strlen(s[1][i]+1);
            for(int l=1;l+zn-1<=na;l++){
                bool flag=true;
                bool qh=true;
                for(int j=1;j<l;j++)
                    if(a[j]!=b[j]){
                        qh=false;
                        break;
                    }
                for(int j=l+zn;j<=na;j++) if(a[j]!=b[j]){
                    qh=false;
                    break;
                }
                if(!qh) continue;
                for(int j=1;j<=zn;j++){
                    if(a[j+l-1]!=s[1][i][j]||b[j+l-1]!=s[2][i][j]){
                        flag=false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        cout<<ans<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int _T=1;
    // cin>>_T;
    while(_T--) solve();
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
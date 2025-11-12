#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
signed main(){
    int n,m,res=0,c[512],allow[512],l[512];
    string s;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    memset(c,0,sizeof(c));
    memset(allow,0,sizeof(allow));
    for(int i=1;i<=n;i++){
        cin>>c[i];
        allow[i]=s[i-1]-'0';
    }
    if(n<=12){
        for(int i=1;i<=n;i++){
            l[i]=i;
        }
        do{
            int pass=0,unpass=0;
            for(int i=1;i<=n;i++){
                if(c[l[i]]>unpass&&allow[i]){
                    pass++;
                }else{
                    unpass++;
                }
            }
            if(pass>=m){
                res++;
            }
        }while(next_permutation(l+1,l+n+1));
    }
    cout<<(res%MOD+MOD)%MOD;
    return 0;
}
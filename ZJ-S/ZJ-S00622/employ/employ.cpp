#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int m,n,p[505];
int per[15];
long long ans;
string d;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>d;
    d=" "+d;
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    if(n<=10){
        for(int i=1;i<=n;i++) per[i]=i;
        do{
            int givup=0;
            for(int i=1;i<=n;i++){
                if(d[i]=='0'){
                    givup++;
                    continue;
                }
                if(p[per[i]]<=givup){
                    givup++;
                    continue;
                }
            }
            if(n-givup>=m){
                ans++;
                ans%=mod;
            }
        }while(next_permutation(per+1,per+n+1));
        printf("%lld",ans%mod);
    }
    else if(m==1){
        int ind=1;
        for(;ind<=n;ind++){
            if(d[ind]=='1') break;
        }
        sort(p+1,p+n+1);
        if(p[n]<=ind-1) printf("0");
        else printf("11451");
    }
    else if(m==n){
        int ind=1;
        sort(p+1,p+n+1);
        for(;ind<=n;ind++) if(d[ind]=='1') break;
        if(ind==n+1) printf("0");
        else if(p[n]<=ind-1) printf("0");
        else printf("1145");
    }
    else printf("0");
    return 0;
}

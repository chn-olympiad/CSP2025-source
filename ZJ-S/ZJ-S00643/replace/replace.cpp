#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
const ll mod1=998244353,mod2=1e9+7,bs1=29,bs2=31;
map<pair<ll,ll>,ll> mp;
string s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        int le=s1.length();
        ll k11=0,k12=0,k21=0,k22=0,ck1=1,ck2=1;
        for(int i=le;i>=1;i--){
            k11=k11+(s1[i-1]-'a'+1)*ck1%mod1; k11%=mod1;
            k12=k12+(s1[i-1]-'a'+1)*ck2%mod2; k12%=mod2;
            k21=k21+(s2[i-1]-'a'+1)*ck1%mod1; k21%=mod1;
            k22=k22+(s2[i-1]-'a'+1)*ck2%mod2; k22%=mod2;
            // cerr<<"psp"<<k11<<" "<<k21<<" "<<k12<<" "<<k22<<endl;
            
            mp[make_pair((3*k11)^k21,(5*k12)^k22)]++;
            ck1=ck1*bs1%mod1;
            ck2=ck2*bs2%mod2;
        }
    }
    for(int i=1;i<=q;i++){
        ll ans=0;
        cin>>s1>>s2;
        int le=s1.length();
        int fl=0,fr=le-1;
        while(s1[fl]==s2[fl]) fl++;
        while(s1[fr]==s2[fr]) fr--;
        ll k11=0,k12=0,k21=0,k22=0;
        // cerr<<fl<<" "<<fr<<'\n';
        for(int i=fl;i<le;i++){
            k11=k11*bs1%mod1+(s1[i]-'a'+1); k11%=mod1;
            k12=k12*bs2%mod2+(s1[i]-'a'+1); k12%=mod2;
            k21=k21*bs1%mod1+(s2[i]-'a'+1); k21%=mod1;
            k22=k22*bs2%mod2+(s2[i]-'a'+1); k22%=mod2;
            // cerr<<"qsq"<<k11<<" "<<k21<<" "<<k12<<" "<<k22<<endl;
            if(i>=fr){
                // if(mp[make_pair(k11^k12,k21^k22)].count()!=0){
                    ans+=mp[make_pair((3*k11)^k21,(5*k12)^k22)];
                // }
            }
            
        }
        printf("%lld\n",ans);
    }
}
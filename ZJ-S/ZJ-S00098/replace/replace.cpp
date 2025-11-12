#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ent putchar('\n')
#define sp putchar(' ')
#define pii pair<int,int>
#define dbg puts("-----------------qaq----------------")
#define fi first
#define se second
#define pl (p<<1)
#define pb push_back
#define pr ((p<<1)|1)
const int B=233,mod=998244353,inf=LONG_LONG_MAX/4;
int read(){int t;scanf("%lld",&t);return t;}
void write(int x){printf("%lld",x);return;}
const int N=2e5+10,RN=2e5;
const int L=5e6+10,RL=5e6;
int n,q,cnt;
int bs[N],hs1[N],hs2[N];
string s1[N],s2[N];
map<pii,int> qaq,pwp;
vector<int> cwc[L];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),q=read();
    bs[0]=1;
    for(int i=1;i<=n;i++) bs[i]=bs[i-1]*B%mod;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        s1[i]="$"+s1[i],s2[i]="$"+s2[i];
        int len=s1[i].size()-1;
        int res1=0,res2=0;
        for(int j=1;j<=len;j++){
            res1=(res1*B+s1[i][j])%mod;
            res2=(res2*B+s2[i][j])%mod;
            if(!pwp[{res1,res2}]){
                pwp[{res1,res2}]=++cnt;
                cwc[cnt].pb(len);
            }
            else cwc[pwp[{res1,res2}]].pb(len);
        }
        qaq[{res1,res2}]++;
    }
    // write(cnt),dbg;
    while(q--){
        int ans=0;
        string t1,t2;
        cin>>t1>>t2;
        t1="$"+t1,t2="$"+t2;
        int l=inf,r=0,len=t1.size()-1;
        for(int i=1;i<=len;i++){
            if(t1[i]!=t2[i]) l=min(l,i),r=max(i,r);
        }
        // write(l),sp,write(r),sp
        hs1[0]=0,hs2[0]=0;
        for(int i=1;i<=len;i++){
            hs1[i]=(hs1[i-1]*B+t1[i])%mod;
            hs2[i]=(hs2[i-1]*B+t2[i])%mod;
        }
        for(int i=1;i<=l;i++){
            int res1=(hs1[r]-hs1[i-1]*bs[r-i+1]%mod+mod)%mod;
            int res2=(hs2[r]-hs2[i-1]*bs[r-i+1]%mod+mod)%mod;
            if(pwp.find({res1,res2})!=pwp.end()){
                // dbg;
                int tmp=pwp[{res1,res2}];
                for(int j=0;j<cwc[tmp].size();j++){
                    int tl=cwc[tmp][j];
                    if(i+tl-1<=len){
                        res1=(hs1[i+tl-1]-hs1[i-1]*bs[tl]%mod+mod)%mod;
                        res2=(hs2[i+tl-1]-hs2[i-1]*bs[tl]%mod+mod)%mod;
                        if(qaq.find({res1,res2})!=qaq.end()) ans++;
                    }
                }
            }
        }
        write(ans),ent;
    }
    // cerr<<1.*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}

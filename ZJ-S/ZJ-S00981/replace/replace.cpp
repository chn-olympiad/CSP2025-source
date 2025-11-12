#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
bool MBE;
const int N=5000010;
const int P=87;
const int mod1=998244353;
const int mod2=319491001;
int ksm(int a,int b,int mod){
    int z=1;
    while(b){
        if(b&1)z=z*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return z;
}
int Inv(int x,int mod){return ksm(x,mod-2,mod);}
int n,q;
struct Node{
    int len;
    pair<int,int>vals,valt;
}a[N];
bool cmp(Node a,Node b){
    return a.len<b.len;
}
int len[N];
pair<int,int>pw[N];
pair<int,int>inv[N];
pair<int,int>vals[N];
pair<int,int>valt[N];
pair<int,int>pres[N];
pair<int,int>pret[N];

void init(){
    pw[0].first=pw[0].second=1;
    for(int i=1;i<=N-10;i++)pw[i].first=pw[i-1].first*P%mod1;
    for(int i=1;i<=N-10;i++)pw[i].second=pw[i-1].second*P%mod2;
    inv[0].first=inv[0].second=1;
    int iP=Inv(P,mod1);
    for(int i=1;i<=N-10;i++)inv[i].first=inv[i-1].first*iP%mod1;
    iP=Inv(P,mod2);
    for(int i=1;i<=N-10;i++)inv[i].second=inv[i-1].second*iP%mod2;
    return;
}
pair<int,int> Vals(int l,int r){
    return make_pair((pres[r].first-pres[l-1].first+mod1)*inv[l-1].first%mod1,(pres[r].second-pres[l-1].second+mod2)*inv[l-1].second%mod2);
}
pair<int,int> Valt(int l,int r){
    return make_pair((pret[r].first-pret[l-1].first+mod1)*inv[l-1].first%mod1,(pret[r].second-pret[l-1].second+mod2)*inv[l-1].second%mod2);
}
int find(int x){
    int l=1,r=n,mid;
    int res=1;
    while(l<=r){
        mid=(l+r)>>1;
        if(len[mid]>=x){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return res;
}
int find2(int x){
    int l=1,r=n,mid;
    int res=1;
    while(l<=r){
        mid=(l+r)>>1;
        if(len[mid]<=x){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}
bool MED;
signed main(){
    // freopen("ex.in","r",stdin);
    // freopen("ex.out","w",stdout);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s,t;
        cin>>s>>t;
        len[i]=s.size();
        for(int j=0;j<s.size();j++){
            vals[i].first=(vals[i].first+pw[j].first*(s[j]-'a'+1)%mod1)%mod1;
            vals[i].second=(vals[i].second+pw[j].second*(s[j]-'a'+1)%mod2)%mod2;
        }
        for(int j=0;j<t.size();j++){
            valt[i].first=(valt[i].first+pw[j].first*(t[j]-'a'+1)%mod1)%mod1;
            valt[i].second=(valt[i].second+pw[j].second*(t[j]-'a'+1)%mod2)%mod2;
        }
        a[i].len=len[i];
        a[i].vals=vals[i];
        a[i].valt=valt[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)len[i]=a[i].len,vals[i]=a[i].vals,valt[i]=a[i].valt;
    while(q--){
        string s,t;
        cin>>s>>t;
        if(s.size()!=t.size()){
            cout<<"0\n";
            continue;
        }
        int m=s.size();
        s=" "+s;t=" "+t;
        for(int i=1;i<=m;i++){
            pres[i].first=(pres[i-1].first+pw[i-1].first*(s[i]-'a'+1)%mod1)%mod1;
            pres[i].second=(pres[i-1].second+pw[i-1].second*(s[i]-'a'+1)%mod2)%mod2;
        }
        for(int i=1;i<=m;i++){
            pret[i].first=(pret[i-1].first+pw[i-1].first*(t[i]-'a'+1)%mod1)%mod1;
            pret[i].second=(pret[i-1].second+pw[i-1].second*(t[i]-'a'+1)%mod2)%mod2;
        }
        int L=0,R=0;
        for(int i=1;i<=m;i++){
            if(s[i]!=t[i]){
                L=i;
                break;
            }
        }
        for(int i=m;i>=1;i--){
            if(s[i]!=t[i]){
                R=i;
                break;
            }
        }
        // cerr<<vals[1].first<<" "<<Vals(3,4).first<<"\n";
        // cerr<<valt[1].first<<" "<<Valt(3,4).first<<"\n";
        int idd=find(R-L+1);
        int edd=find2(m);
        int ans=0;
        for(int i=idd;i<=edd;i++){
            if(len[i]<R-L+1)continue;
            int st=R-len[i]+1;
            st=max(st,1ll);
            for(int j=st;j<=L;j++){
                int ed=j+len[i]-1;
                if(ed>m)break;
                if(Vals(j,ed)==vals[i]&&Valt(j,ed)==valt[i])ans++;
            }
        }
        cout<<ans<<"\n";
    }
    // cerr<<"Time : "<<1000*clock()/CLOCKS_PER_SEC<<" ms\n";
    // cerr<<"Memory : "<<fixed<<setprecision(2)<<abs(&MBE-&MED)/1048576.0<<" MB\n";
    return 0;
}
/*
1 1
bc de
xabcx xadex
*/
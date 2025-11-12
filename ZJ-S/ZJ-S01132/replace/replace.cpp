#include<bits/stdc++.h>
#define fi first
#define se second
#define For(i,il,ir) for(int i=(il);i<=(ir);i++)
#define Rof(i,ir,il) for(int i=(ir);i>=(il);i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod1=998244353;
const ll mod2=1e9+7;

const int maxn=2e5+10;
const int maxm=5e6+10;

int n,Q;
pll mul(pll x,ll v){ return make_pair(x.fi*v%mod1,x.se*v%mod2); }
pll add(pll x,ll v){ return make_pair((x.fi+v)%mod1,(x.se+v)%mod2); }

string s1,s2,t1,t2;
int ln[maxn],pre[maxn],suf[maxn];
pll prehsh[maxn],mid1[maxn],mid2[maxn],sufhsh[maxn],hsh[maxm];

void rd(string &str){
    char ch=getchar(); str="";
    while(ch<'a'||ch>'z') ch=getchar();
    while(ch>='a' && ch<='z') str+=ch,ch=getchar();
}
pll gethsh(string &str,int st,int ed,int ad=1){
    pll h=make_pair(0,0);
    for(int j=st;j!=ed;j+=ad){
        h=add(mul(h,233),str[j]-'a'+1);
    }
    return h;
}

void solve1()
{
    For(i,1,n)
    {
        rd(s1),rd(s2);
        int len=s1.size(),p=0,s=len-1;
        while(p<len && s1[p]==s2[p]) p++;
        while(s>=0 && s1[s]==s2[s]) s--;

        pre[i]=p,suf[i]=len-1-s,ln[i]=len;
        if(p==len) continue;

        mid1[i]=gethsh(s1,p,s+1);
        mid2[i]=gethsh(s2,p,s+1);
        prehsh[i]=gethsh(s1,p-1,-1,-1);
        sufhsh[i]=gethsh(s1,s+1,len,1);
    }

    For(q,1,Q)
    {
        rd(t1),rd(t2);
        int len=t1.size(),p=0,s=len-1;
        while(p<len && t1[p]==t2[p]) p++;
        while(s>=0 && t1[s]==t2[s]) s--;

        pll m1=gethsh(t1,p,s+1);
        pll m2=gethsh(t2,p,s+1);

        hsh[p]=hsh[s]=make_pair(0,0);
        Rof(j,p-1,0) hsh[j]=add(mul(hsh[j+1],233),t1[j]-'a'+1);
        For(j,s+1,len-1) hsh[j]=add(mul(hsh[j-1],233),t1[j]-'a'+1);

        int midlen=s-p+1,ans=0;
        // cout<<s<<' '<<len-1-p<<' '<<"? ? "<<m1.fi<<' '<<m2.fi<<endl;
        For(i,1,n){
            if(pre[i]==ln[i] || ln[i]-pre[i]-suf[i]!=midlen) continue;
            if(!(m1==mid1[i] && m2==mid2[i])) continue;
            if(!(p-pre[i]>=0 && hsh[p-pre[i]]==prehsh[i])) continue;
            if(!(s+suf[i]<len && hsh[s+suf[i]]==sufhsh[i])) continue;
            ans++;
        }
        printf("%d\n",ans);
    }
}

int tans[maxn];
int h[maxn<<1],V;
struct node{
    int op,p,q,r,id;
}ss[maxn],tt[maxn];

bool cmp(node xx,node yy){
    if(xx.op!=yy.op) return xx.op<yy.op;
    else if(xx.q!=yy.q) return xx.q<yy.q;
    return xx.p<yy.p;
}
int tr[maxn<<1];
void add(int x,int y){ while(x<=V) tr[x]+=y,x+=(x&-x); }
int qry(int x){ int ret=0; while(x) ret+=tr[x],x-=(x&-x); return ret; }

void solve2()
{
    For(i,1,n)
    {
        rd(s1),rd(s2);
        int pos1,pos2,len=s1.size();
        For(j,0,len-1){
            if(s1[j]=='b') pos1=j;
            if(s2[j]=='b') pos2=j;
        }
        ss[i].op=(pos1<pos2);
        ss[i].p=min(pos1,pos2);
        ss[i].q=abs(pos1-pos2)+1;
        ss[i].r=len-1-max(pos1,pos2);

        h[++V]=ss[i].r;
    }
    For(i,1,Q)
    {
        rd(t1),rd(t2);
        int pos1,pos2,len=t1.size();
        For(j,0,len-1){
            if(t1[j]=='b') pos1=j;
            if(t2[j]=='b') pos2=j;
        }
        tt[i].op=(pos1<pos2);
        tt[i].p=min(pos1,pos2);
        tt[i].q=abs(pos1-pos2)+1;
        tt[i].r=len-1-max(pos1,pos2);
        tt[i].id=i;

        h[++V]=tt[i].r;
    }

    sort(h+1,h+1+V);
    V=unique(h+1,h+1+V)-h-1;
    For(i,1,n) ss[i].r=lower_bound(h+1,h+1+V,ss[i].r)-h;
    For(i,1,Q) tt[i].r=lower_bound(h+1,h+1+V,tt[i].r)-h;

    sort(ss+1,ss+1+n,cmp);
    sort(tt+1,tt+1+Q,cmp);

    // For(i,1,n) cout<<ss[i].op<<' '<<ss[i].q<<' '<<ss[i].p<<' '<<ss[i].r<<' '<<endl;
    // For(i,1,Q) cout<<tt[i].op<<' '<<tt[i].q<<' '<<tt[i].p<<' '<<tt[i].r<<' '<<tt[i].id<<endl;

    int h=1,t=0;
    For(i,1,Q){
        while(h<=n && (ss[h].op<tt[i].op || ss[h].op==tt[i].op && ss[h].q<tt[i].q)){
            if(h<=t) add(ss[h].r,-1);
            h++;
        }
        t=max(t,h-1);
        while(t+1<=n && ss[t+1].op==tt[i].op && ss[t+1].q==tt[i].q && ss[t+1].p<=tt[i].p)
            add(ss[++t].r,1);
        tans[tt[i].id]=qry(tt[i].r);
    }
    For(i,1,Q) printf("%d\n",tans[i]);
}

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&Q);
    if(n<=1000 || Q<=1000 || Q==1) solve1();
    else solve2();
    return 0;
}
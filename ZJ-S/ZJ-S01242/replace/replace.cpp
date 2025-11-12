#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define forl(i,a,b) for(re ll (i)=(a);(i)<=(b);(i)++)
#define forr(i,a,b) for(re ll (i)=(a);(i)>=(b);(i)--)
#define forll(i,a,b,c) for(re ll (i)=(a);(i)<=(b);(i)+=(c))
#define forrr(i,a,b,c) for(re ll (i)=(a);(i)>=(b);(i)-=(c))
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pii pair<ll,ll>
#define pb push_back
#define x first
#define y second
ll _t_;
ll l;
const int mod1=1e9+7,mod2=998244353,base1=131,base2=666;
struct node{
    int x,y,xx,yy,len,hsh1,hsh2,hsh3,hsh4;
    friend bool operator < (node x,node y){
        if(x.x==y.x)
            return x.y<y.y;
        return x.x<y.x;
    }
    friend bool operator != (node x,node y){
        return x.x!=y.x || x.y!=y.y || x.xx!=y.xx || x.yy!=y.yy || x.len!=y.len || x.hsh1!=y.hsh1 || x.hsh2!=y.hsh2;
    }
}A[5000010];
int t[5000010];
int Pw1[5000010],Pw2[5000010];
int h1[5000010],h2[5000010],h3[5000010],h4[5000010];
int n,m;
ll f1(ll l,ll r){
    if(!l)
        return h1[r];
    return (h1[r]-1ll*h1[l-1]*Pw1[r-l+1]%mod1+mod1)%mod1;
}
ll f2(ll l,ll r){
    if(!l)
        return h2[r];
    return (h2[r]-1ll*h2[l-1]*Pw1[r-l+1]%mod1+mod1)%mod1;
}
ll f3(ll l,ll r){
    if(!l)
        return h3[r];
    return (h3[r]-1ll*h3[l-1]*Pw2[r-l+1]%mod2+mod2)%mod2;
}
ll f4(ll l,ll r){
    if(!l)
        return h4[r];
    return (h4[r]-1ll*h4[l-1]*Pw2[r-l+1]%mod2+mod2)%mod2;
}
void solve()
{
    l=0;
    cin>>n>>m;
    // cout<<n<<' '<<m<<endl;
    forl(i,1,n)
    {
        string s1,s2;
        cin>>s1>>s2;
        ll sz=s1.size();
        ll hsh1=0,hsh2=0;
        ll L=l+1;
        forl(j,0,sz-1)
            hsh1=(1ll*hsh1*base1+s1[j])%mod1,
            hsh2=(1ll*hsh2*base1+s2[j])%mod1,
            A[L+j].x=hsh1,A[L+j].y=hsh2;

        forl(j,0,sz-1)
            A[L+j].len=sz,
            A[L+j].hsh1=hsh1,
            A[L+j].hsh2=hsh2;

        hsh1=0,hsh2=0;
        forl(j,0,sz-1)
            hsh1=(1ll*hsh1*base2+s1[j])%mod2,
            hsh2=(1ll*hsh2*base2+s2[j])%mod2,
            A[L+j].xx=hsh1,A[L+j].yy=hsh2;
        
        forl(j,0,sz-1)
            A[L+j].hsh3=hsh1,
            A[L+j].hsh4=hsh2;
        // A[i].xx=hsh1,A[i].yy=hsh2;
        l+=sz;
    }
    sort(A+1,A+1+l);
    // cout<<l<<endl;
    ll k=0;
    forl(i,1,l)
    {
        if(A[i]!=A[k])
            A[++k]=A[i],
            t[k]=1;
        else
            t[k]++;
    }
    // forl(i,1,k)
    //     cout<<A[i].x<<' '<<A[i].y<<endl;
    // n=k;
    // return ;
    forl(_,1,m)
    {
        string s1,s2;
        cin>>s1>>s2;
        // if(_!=27576)
        //     continue;
        // if(_==306)
        //     cerr<<s1<<' '<<s2<<endl;
        // if(_==27576)
        //     cout<<s1<<' '<<s2<<endl;
        ll sz=s1.size();
        h1[0]=h3[0]=s1[0],h2[0]=h4[0]=s2[0];
        forl(i,1,sz-1)
            h1[i]=(1ll*h1[i-1]*base1+s1[i])%mod1,
            h3[i]=(1ll*h3[i-1]*base2+s1[i])%mod2,
            h2[i]=(1ll*h2[i-1]*base1+s2[i])%mod1,
            h4[i]=(1ll*h4[i-1]*base2+s2[i])%mod2;
        ll L=0,R=sz-1;
        while(L<R)
        {
            ll Mid=(L+R)>>1;
            if(f1(0,Mid)==f2(0,Mid) && f3(0,Mid)==f4(0,Mid))
                L=Mid+1;
            else
                R=Mid;
        }
        ll ql=L;
        L=ql,R=sz-1;
        // cout<<f1(sz-1,sz-1)<<':'<<f2(sz-1,sz-1)<<endl;
        while(L<R)
        {
            ll Mid=(L+R+1)>>1;
            if(f1(Mid,sz-1)==f2(Mid,sz-1) && f3(Mid,sz-1)==f4(Mid,sz-1))
                R=Mid-1;
            else
                L=Mid;
        }
        ll qr=L;
        ll ans=0;
        // if(_==306)
        //     cerr<<ql<<' '<<qr<<endl;
        // if(_==27576)
        //     cout<<ql<<' '<<qr<<endl;
        if(ql>qr)
            exit(-1);
        forr(i,ql,0)
        {
            ll _1=f1(i,qr),_2=f2(i,qr),_3=f3(i,qr),_4=f4(i,qr);
            ll L=1,R=k;
            while(L<R)
            {
                ll Mid=(L+R)/2;
                if(_1<=A[Mid].x)
                    R=Mid;
                else if(_1>A[Mid].x)
                    L=Mid+1;
            }
            // cout<<_1<<' '<<A[L].x<<' '<<_3<<' '<<A[L].xx<<' '<<_2<<' '<<A[L].y<<' '<<_3<<' '<<A[L].yy<<endl;
            // cout<<A[L].x<<','<<_1<<endl;
            if(A[L].x!=_1)
                continue;
            R=k;
            ll ql=L;
            while(L<R)
            {
                ll Mid=(L+R)/2;
                if(_1<A[Mid].x)
                    R=Mid-1;
                else if(_2>A[Mid].y)
                    L=Mid+1;
                else
                    R=Mid;
            }
            // cout<<A[L].y<<' '<<_2<<endl;
            forl(j,L,k)
            {
                ll len=A[j].len;
                // cout<<A[j].x<<' '<<_1<<' '<<A[j].xx<<' '<<_3<<endl;
                if(A[j].x==_1 && A[j].xx==_3 && A[j].y==_2 && A[j].yy==_4)
                {
                    if(i+len-1<=sz && f1(i,i+len-1)==A[j].hsh1 && f2(i,i+len-1)==A[j].hsh2 && f3(i,i+len-1)==A[j].hsh3 && f4(i,i+len-1)==A[j].hsh4)
                        ans+=t[j];
                }
                else
                    break;
            }
        }
        cout<<ans<<endl;
        // cout<<1<<endl;
    }
}
int main()
{
    Pw1[0]=Pw2[0]=1;
    forl(i,1,5e6+5)
        Pw1[i]=1ll*Pw1[i-1]*base1%mod1,
        Pw2[i]=1ll*Pw2[i-1]*base2%mod2;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    IOS;
    _t_=1;
    // cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}
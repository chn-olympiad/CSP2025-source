#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int LENS=5e6+10, N=2e5+10, P1=99824453, P2=1e9+7;
int n, m;
char s[LENS], c[LENS];
map<pii,vector<pair<pii,pii> > > a;
map<pii,bool> mp1, mp2;
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    rep(i, 1, n) {
        cin>>(c+1)>>(s+1);
        int len=strlen(s+1);
        int l, r, tmpl=0, tmpr=0, resl=0, resr=0;
        l=1; r=len;
        while(l<=len&&s[l]==c[l]) l++;
        while(r&&s[r]==c[r]) r--;
        int midc=0, mids=0;
        rep(i, l, r) midc=((1ll*midc*27)%P1+c[i]-'a'+1)%P1;
        rep(i, l, r) mids=((1ll*mids*27)%P1+s[i]-'a'+1)%P1;
        l--; while(l) {
            tmpl=((1ll*tmpl*27)%P1+s[l]-'a'+1)%P1;
            resl=((1ll*resl*28)%P2+s[l]-'a'+1)%P2;
            l--;
        }
        r++; while(r<=len) {
            tmpr=((1ll*tmpr*27)%P1+s[r]-'a'+1)%P1;
            resr=((1ll*resr*28)%P2+s[r]-'a'+1)%P2;
            r++;
        }
        a[mkp(midc, mids)].push_back(mkp(mkp(tmpl, resl), mkp(tmpr, resr)));
    }
    rep(i, 1, m) {
        cin>>(c+1)>>(s+1);
        int len=strlen(c+1);
        int l, r, tmpl=0, tmpr=0, resl=0, resr=0, ans=0;
        l=1; r=len;
        while(l<=len&&s[l]==c[l]) l++;
        while(r&&s[r]==c[r]) r--;
        int midc=0, mids=0;
        rep(i, l, r) midc=((1ll*midc*27)%P1+c[i]-'a'+1)%P1;
        rep(i, l, r) mids=((1ll*mids*27)%P1+s[i]-'a'+1)%P1;
        l--; while(l) {
            tmpl=((1ll*tmpl*27)%P1+s[l]-'a'+1)%P1;
            resl=((1ll*resl*28)%P2+s[l]-'a'+1)%P2;
            mp1[mkp(tmpl, resl)]=1;
            l--;
        } mp1[mkp(0, 0)]=1;
        r++; while(r<=len) {
            tmpr=((1ll*tmpr*27)%P1+s[r]-'a'+1)%P1;
            resr=((1ll*resr*28)%P2+s[r]-'a'+1)%P2;
            mp2[mkp(tmpr, resr)]=1;
            r++;
        } mp2[mkp(0, 0)]=1;
        for(auto i:a[mkp(midc, mids)]) ans+=mp1.count(i.fi)&&mp2.count(i.se);
        cout<<ans<<'\n'; mp1.clear(); mp2.clear();
    }
    return 0;
}
//manba out:(:(:(:(:(
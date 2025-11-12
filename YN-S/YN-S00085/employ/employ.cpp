//by haotian,sun
//面积luogu联系 @fkxr(uid=995934)
#include<bits/stdc++.h>
#define endl cerr<<"I love Olympiad in Informatics!\n"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc getchar
#define pc putchar
#endif
namespace FastIO{
    void r(int &a){
        a=0;bool ok=0;char ch=gc();
        for(;ch>'9'||ch<'0';ch=gc())ok^=(ch=='-');
        for(;ch>='0'&&ch<='9';ch=gc())
            a=(a<<3)+(a<<1)+ch-'0';
        if(ok)a=-a;
    }
    void w(int a){
        if(a==0){pc('0');return;}
        int till=0;char ch[25];
        if(a<0){
            pc('-');
            for(;a;a/=10)ch[till++]=-(a%10);
        }else for(;a;a/=10)ch[till++]=a%10;
        for(;till;)pc(ch[--till]+'0');
    }
    struct FIstream{
        FIstream operator>>(int &x){r(x);return {};}
    }in;
    struct FOstream{
        FOstream operator<<(int x){w(x);return {};}
        FOstream operator<<(char ch){pc(ch);return {};}
        FOstream operator<<(string s){for(auto ch:s)pc(ch);return {};}
    }out;
}using FastIO::in;using FastIO::out;
namespace code{
    void Freopen(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
    string s;int n,m;
    int c[105];
    int k[105];
    int ans=0;
    void dfs(int x,int vis,int Die,int cnt){
        if(x==n+1){
            if(cnt>=m)++ans;
            return;
        }
        if(cnt>=m){
            int tmp=1;
            for(int i=n;i>=x;i--)tmp=tmp*(n-i+1);
            ans+=tmp;
            return;
        }
        for(int i=0;i<n;i++){
            if(vis&(1<<i))continue;
            int tcnt=cnt,tdie=Die;
            if(Die<c[i+1]&&s[x]=='1')++tcnt;
            else ++tdie;
            dfs(x+1,vis|(1<<i),tdie,tcnt);
        }
    }
    void Main(){
        Freopen("employ");
        cin>>n>>m>>s;s="~"+s;
        for(int i=1;i<=n;i++)cin>>c[i];
        dfs(1,0,0,0);
        out<<ans<<"\n";
    }
}
signed main(){
    code::Main();
    return 0;
}
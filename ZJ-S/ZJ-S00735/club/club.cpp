#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=1e6+10,inf=0x3f3f3f3f;
void read(){}
template<class T,class...T2>
void read(T&ret,T2&...rest){
    ret=0;int c=gc();bool f=0;
    for(;!isdigit(c);c=gc())f=c=='-';
    for(;isdigit(c);c=gc())ret=ret*10+c-'0';
    f&&(ret=-ret),read(rest...);
}
#define cin(...) read(__VA_ARGS__)
template<class T>
void print(T x){
    static short sta[35],t=0;
    bool f=0;if(x<0)x=-x,f=1;
    do sta[++t]=x%10;while(x/=10);
    for(f&&pc('-');t;)pc(sta[t--]+'0');
}
int T,n,mi,a[N][3],mx[N],ct[3];
ll res;
signed main(){
#ifdef local
    freopen("club5.in","r",stdin);
#else
    freopen("club.in","r",stdin);
#endif
    freopen("club.out","w",stdout);
    for(cin(T);T;T--){
        cin(n),res=0;
        for(int&c:ct)c=0;
        for(int i=1;i<=n;i++){
            for(int&v:a[i])cin(v);
            mx[i]=max_element(a[i],a[i]+3)-a[i];
            res+=a[i][mx[i]],ct[mx[i]]++;
        }
        if(mi=max_element(ct,ct+3)-ct;ct[mi]>n/2){
            //cerr<<"! "<<res<<endl;
            vector<int>vt;
            for(int i=1;i<=n;i++)if(mx[i]==mi){
                int vl=inf;
                for(int j:{0,1,2})if(j!=mi)
                    vl=min(vl,a[i][mi]-a[i][j]);
                vt.pb(vl);
            }
            //assert((int)vt.size()==ct[mi]);
            sort(all(vt));
            vt.resize(ct[mi]-n/2);
            for(int v:vt)res-=v;
            //cerr<<"~ "<<res<<endl;
        }
        print(res),pc(endl);
    }
    return 0;
}
//g++ club.cpp -o club -Wall -Wextra -Og -g -std=c++14 -fsanitize=address,undefined -Dlocal
//14:54 ok
//What is matter? never mind.
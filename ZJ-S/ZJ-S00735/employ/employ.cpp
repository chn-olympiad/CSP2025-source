#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=1e6+10,inf=0x3f3f3f3f,mod=998244353;
void read(){}
template<class T,class...T2>
void read(T&ret,T2&...rest){
    ret=0;int c=gc();bool f=0;
    for(;!isdigit(c);c=gc())f=c=='-';
    for(;isdigit(c);c=gc())ret=ret*10+c-'0';
    f&&(ret=-ret),read(rest...);
}
void read(string&s){
    s="";char c=gc();
    for(;isspace(c);c=gc());
    for(;isgraph(c);c=gc())s+=c;
}
#define cin(...) read(__VA_ARGS__)
template<class T>
void print(T x){
    static short sta[35],t=0;
    bool f=0;if(x<0)x=-x,f=1;
    do sta[++t]=x%10;while(x/=10);
    for(f&&pc('-');t;)pc(sta[t--]+'0');
}
int n,m,c[N];
string str;
void add(int&a,int b){a=(a+b)%mod;}
namespace sub1{
    const int N=19,S=1<<18;
    unordered_map<int,int>f[N][S];
    void solve(){
        cin(str);
        for(int i=0;i<n;i++)cin(c[i]);
        sort(c,c+n);
        f[0][(1<<n)-1][0]=1;
        for(int i=0;i<n;i++){
            for(int s=0;s<(1<<n);s++){
                for(auto[j,w]:f[i][s]){
                    //cerr<<i<<" "<<s<<" "<<j<<" "<<w<<endl;
                    for(int ss=s,t;ss;ss^=(1<<t)){
                        t=__lg(ss&-ss);
                        add(f[i+1][s^(1<<t)][j+(str[i]=='0'?1:(j>=c[t]))],w);
                    }
                }
            }
        }
        int res=0;
        for(auto[j,w]:f[n][0]){
            if(n-j>=m)add(res,w);
            //cerr<<s<<" "<<j<<" "<<w<<endl;
        }
        print(res),pc(endl);
    }
}
signed main(){
#ifdef local
    freopen("employ2.in","r",stdin);
#else
    freopen("employ.in","r",stdin);
#endif
    freopen("employ.out","w",stdout);
    cin(n,m);
    sub1::solve();
    return 0;
}
//g++ employ.cpp -o employ -Wall -Wextra -Og -g -std=c++14 -fsanitize=address,undefined -Dlocal
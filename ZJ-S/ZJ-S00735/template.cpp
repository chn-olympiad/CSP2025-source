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
int a,b;
signed main(){
    cin(a,b);
    print(a+b),pc(endl);
    return 0;
}
//g++ template.cpp -o template -Wall -Wextra -Og -g -std=c++14 -fsanitize=address,undefined -Dlocal
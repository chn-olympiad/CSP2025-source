#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
template <typename T> void read(T& num){
    num=0;bool sign=false;
    char ch=getchar();
    while(ch<'0'||ch>'9') sign=(ch=='-'),ch=getchar();
    while('0'<=ch&&ch<='9') num=(num<<1)+(num<<3)+(ch-'0'),ch=getchar();
    num=sign?~(num-1):num;
}
ll read(){
    ll num=0;bool sign=false;
    char ch=getchar();
    while(ch<'0'||ch>'9') sign=(ch=='-'),ch=getchar();
    while('0'<=ch&&ch<='9') num=(num<<1)+(num<<3)+(ch-'0'),ch=getchar();
    return sign?~(num-1):num;
}
int n,m;
int main(){
    n=read(),read(m);
    cout<<n<<" "<<m<<"\n";
    return 0;
}

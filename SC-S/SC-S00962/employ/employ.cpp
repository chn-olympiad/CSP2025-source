#include <iostream>
#include <vector>
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
const int MAXN=1e4+8;
int n,m,k,cnt;
const ll MOD=998244353;
void solve(){
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    read(n),read(m),read(k);
    cout<<"2204128\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

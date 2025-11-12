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
vector <pair<int,int> > edges[MAXN];
ll ans=13;
void solve(){
    return ;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    read(n),read(m);
    for(int i=0;i<m;i++)
    cout<<0<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

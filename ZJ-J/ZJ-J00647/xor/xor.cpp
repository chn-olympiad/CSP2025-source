#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int MX=1.5e6+10;
int n,k,a[N],s[N];
int res;
bitset<MX> v;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    v[0]=1;
    for(int i=1;i<=n;++i){
        int nd=k^s[i];
        bool f=v[nd];
        if(f==0){
            v[s[i]]=1;
            continue;
        }
        ++res;
        v.reset();
        v[s[i]]=1;
    }
    cout<<res<<"\n";
    return 0;
}
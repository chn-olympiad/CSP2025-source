#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define vector basic_string
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
int ld(int l,int r){return rnd()%(r-l+1)+l;}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n=ld(1,5),m=ld(n-1,10),k=ld(1,5);
    cout<<n<<" "<<m<<" "<<k<<"\n";
    for(int i=1;i<n;i++){
        cout<<i+1<<" "<ld(1,i)<<" "<ld(1,15)<<"\n";
    }
    for(int i=n;i<=m;i++){
        cout<<ld(1,n)<<" "<<ld(1,n)<<" "<<ld(1,15)<<"\n";
    }
    for(int i=1;i<=k;i++){
        cout<<ld(1,15)<<" ";
        for(int j=1;j<=n;j++)cout<<ld(1,15)<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
}
/*
g++ -std=c++14 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
*/
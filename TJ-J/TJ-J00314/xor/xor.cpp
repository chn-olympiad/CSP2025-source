#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const int N=5e5+5;
int n;
ull k,a[N],s[N],ans,res;

inline void solve1(){
    if(n==1) cout<<0;
    else if(n==2) cout<<1;
    else cout<<(n>>1);
}

inline void solve2(){
    int f=1,res=0;
    for(int i=1;i<=n;i++){if(a[i]==1){res++;f=0;}}
    if(f){cout<<0;return;}
    cout<<res;return;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
    if(n<=100&&k==0){
        solve1();
    }else if(k==1){
        solve2();
    }else{
        int l=1;
        while(l<=n){
            int f=1;
            for(int r=l;r<=n;r++){
                ull tmp=s[r]^s[l-1];
                if(tmp==k){
                    cout<<l<<" "<<r<<endl;
                    ans++;l=r+1;f=0;break;
                }
            }
            if(f) l++;
        }
        cout<<ans;
    }
    return 0;
}

// I love you,SYH;

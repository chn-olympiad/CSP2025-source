#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define db double
#define i128 __int128
#define ull unsigned long long
#define ui unsigned int

const ll N=1e5;
ll n,a[N+10][3];
ll pos[N+10];
int cnt[3];

ll n_2;
ll b[N+10];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<3;i++) cnt[i]=0;
        for(int i=1;i<=n;i++){
            pos[i]=0;
            for(int j=0;j<3;j++)
                cin>>a[i][j];
            for(int j=0;j<3;j++)
                if(a[i][j]>a[i][pos[i]])
                    pos[i]=j;
            cnt[pos[i]]++;
        }
        int mx=0;
        for(int i=0;i<3;i++) mx=max(mx,cnt[i]);
        if(mx<=n/2){
            ll ans=0;
            for(int i=1;i<=n;i++) ans+=a[i][pos[i]];
            cout<<ans<<'\n';
        }
        else{
            // cout<<"case 2\n";
            int mxp=0;
            for(int i=0;i<3;i++)
                if(cnt[i]==mx)
                    mxp=i;
            ll ans=0;
            n_2=0;
            for(int i=1;i<=n;i++){
                ans+=a[i][pos[i]];
                if(pos[i]==mxp){
                    ll val=0;
                    for(int j=0;j<3;j++) if(mxp!=j) val=max(val,a[i][j]);
                    b[++n_2]=a[i][mxp]-val;
                }
            }
            sort(b+1,b+n_2+1);
            // cout<<"debug:\n";
            // for(int i=1;i<=n_2;i++) cout<<b[i]<<" ";
            // cout<<'\n';
            for(int i=1;i<=n_2-n/2;i++) ans-=b[i];
            cout<<ans<<"\n";
        }
    }
    return 0;
}
/*
T_A [14:32,14:36]
W_init [,14:41]
W_A [,14:47]
C [,15:04]

ulimit -s 1024000
g++ club.cpp -o test -std=c++14 -O2 -static -Wall -Wshadow -Wextra
g++ club.cpp -o test -std=c++14 -O2 -Wall -Wshadow -Wextra -fsanitize=address,undefined
./test 
fc club5.ans club.out
*/
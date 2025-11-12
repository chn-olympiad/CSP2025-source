#include<bits/stdc++.h>
#define int long long
#define lop(i,a,b) for(int i=a;i<=b;i++)
#define pol(i,a,b) for(int i=a;i>=b;i--)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout),ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define mset(a,v) memset(a,v,sizeof a)
#define pb push_back
#define pc __builtin_popcountll
using namespace std;
typedef pair<int,int> pii;
bool c1;
const int NN=505,SS=(1<<18)+5,MOD=998244353;
int f[SS][20];
int n,m,s[NN],c[NN];
void Deal(){
    lop(i,1,n)if(!s[i]){
        cout<<0;
        return;
    }
    lop(i,0,n-1){
        if(!c[i]){
            cout<<0;
            return;
        }
    }
    int res=1;
    lop(i,1,n)(res*=i)%=MOD;
    cout<<res;
    return;
}
void Work(){
    cin>>n>>m;
    
    lop(i,1,n){
        char ch;cin>>ch;
        s[i]=ch-'0';
    }
    lop(i,0,n-1)cin>>c[i];
    if(m==n)return Deal();
    f[0][0]=1;
    lop(S,0,(1<<n)-1){
        lop(j,0,n){
            if(!f[S][j])continue;
            lop(i,0,n-1){
                if(S>>i&1)continue;
                int _S=S|(1<<i);
                int _j=j+(s[pc(_S)]&&(c[i]>((int)pc(S)-j)));
                // if(_S==2&&_j==0){
                //     cout<<
                // }
                (f[_S][_j]+=f[S][j])%=MOD;
            }
            // cout<<S<<" "<<j<<" "<<f[S][j]<<"\n";
        }
    }
    int ans=0;
    lop(i,m,n)(ans+=f[(1<<n)-1][i])%=MOD;
    cout<<ans<<"\n";
    return;
}
bool c2;
signed main(){
    // int Time=clock();
    // cerr<<abs(&c1-&c2)/1024.0/1024<<"\n";
    file("employ");
    Work();
    // cerr<<"\n"<<1.0*(clock()-Time)/CLOCKS_PER_SEC;
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define lop(i,a,b) for(int i=a;i<=b;i++)
#define pol(i,a,b) for(int i=a;i>=b;i--)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout),ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define mset(a,v) memset(a,v,sizeof a)
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
bool c1;
const int NN=1e5+5;
int n,a[NN][3],cnt[3],ans,chos[NN];
void Work(){
    ans=0;
    cnt[0]=cnt[1]=cnt[2]=0;
    cin>>n;
    lop(i,1,n){
        lop(j,0,2)
            cin>>a[i][j];
        int mx=0,pos=0;
        lop(j,0,2){
            if(a[i][j]>mx){
                mx=a[i][j],pos=j;
            }
        }
        chos[i]=pos;
        ans+=mx;
        cnt[pos]++;
    }
    int mx=0,pos=0;
    lop(i,0,2)if(cnt[i]>mx)mx=cnt[i],pos=i;
    vector<int> v;
    lop(i,1,n){
        if(chos[i]==pos){
            v.pb(min(a[i][pos]-a[i][(pos+1)%3],a[i][pos]-a[i][(pos+2)%3]));
        }
    }
    sort(v.begin(),v.end());
    int c=mx-n/2;
    lop(i,0,c-1)ans-=v[i];
    cout<<ans<<"\n";
    return;
}
bool c2;
signed main(){
    // int Time=clock();
    // cerr<<abs(&c1-&c2)/1024.0/1024<<"\n";
    file("club");
    int T;cin>>T;
    while(T--)Work();
    // cerr<<"\n"<<1.0*(clock()-Time)/CLOCKS_PER_SEC;
    return 0;
}/*

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}
const int N=1e5+5;
int n,lim,a[N][3],cnt[3],op[N],del[N],ans;
void solve(){
    n=read();lim=n>>1;ans=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)
            a[i][j]=read();
        auto p=max_element(a[i],a[i]+3);
        op[i]=p-a[i];
        cnt[op[i]]++;
        del[i]=0;
        for(int j=0;j<3;j++)
            if(j!=op[i])del[i]=max(del[i],a[i][j]);
        del[i]=(*p)-del[i];
        ans+=(*p);
        // cerr<<(*p)<<' '<<del[i]<<'\n';
    }
    // cerr<<n<<' '<<ans<<'\n';
    for(int j=0;j<3;j++)if(cnt[j]>lim){
        // cerr<<j<<'\n';
        vector<int>vec;
        for(int i=1;i<=n;i++)if(op[i]==j)
            vec.push_back(del[i]);
        sort(vec.begin(),vec.end());
        // for(auto i:vec)cerr<<i<<' ';cerr<<'\n';
        for(int i=0;i<vec.size()&&cnt[j]>lim;i++){
            --cnt[j];
            ans-=vec[i];
        }
        break;
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}
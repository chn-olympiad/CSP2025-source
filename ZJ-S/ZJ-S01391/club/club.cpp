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
constexpr int maxn=1e5+10;
struct node{int a,b,c;}a[maxn];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
        int ans=0,cnt1=0,cnt2=0,cnt3=0;
        bool ok=1;
        for(int i=1;i<=n;i++){
            int val=max({a[i].a,a[i].b,a[i].c});
            bool g=1;
            if(val==a[i].a and cnt1<n/2){
                cnt1++;g=0;
            }
            if(val==a[i].b and g and cnt2<n/2){
                cnt2++;g=0;
            }
            if(val==a[i].c and g and cnt3<n/2){
                cnt3++;g=0;
            }
            if(g){
                ok=0;break;
            }
            ans+=val;
        }
        if(ok){
            cout<<ans<<"\n";
            continue;
        }
        ans=0;

        int res=0;
        sort(a+1,a+n+1,[](node pa,node pb){return pa.a-max(pa.b,pa.c)>pb.a-max(pb.b,pb.c);});
        for(int i=1;i<=n/2;i++)res+=a[i].a;
        for(int i=n/2+1;i<=n;i++)res+=max(a[i].b,a[i].c);
        ans=max(ans,res);

        res=0;
        sort(a+1,a+n+1,[](node pa,node pb){return pa.b-max(pa.a,pa.c)>pb.b-max(pb.a,pb.c);});
        for(int i=1;i<=n/2;i++)res+=a[i].b;
        for(int i=n/2+1;i<=n;i++)res+=max(a[i].a,a[i].c);
        ans=max(ans,res);

        res=0;
        sort(a+1,a+n+1,[](node pa,node pb){return pa.c-max(pa.b,pa.a)>pb.c-max(pb.b,pb.a);});
        for(int i=1;i<=n/2;i++)res+=a[i].c;
        for(int i=n/2+1;i<=n;i++)res+=max(a[i].b,a[i].a);
        ans=max(ans,res);

        cout<<ans<<"\n";
    }
    return 0;
}
/*
g++ -std=c++14 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
*/
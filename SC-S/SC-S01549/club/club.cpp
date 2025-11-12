#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr bool online=1;
int qt,n,t[4],ans;pair<int,int>a[100005][4];
priority_queue<int,vector<int>,greater<int>>pq[4];
signed main(){
    if(online)
        freopen("club.in","r",stdin),
        freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    for(cin>>qt;qt;qt--){
        cin>>n; ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=3;++j)
                cin>>a[i][j].first,
                a[i][j].second=j;
            sort(a[i]+1,a[i]+4,greater<pair<int,int>>());
            ans+=a[i][1].first;
            t[a[i][1].second]++;
            pq[a[i][1].second].emplace(
                a[i][1].first-a[i][2].first
            );
        }
        /*
        一个成员一定可以被分配到自己最喜欢的前两个部门中。
        因此失其一必得其二。
        我们只保留那两个，并尽可能优先让差值更小的人进行谦让。
        */
        for(int j=1;j<=3;++j) while(t[j]>n/2)
            t[j]--,ans-=pq[j].top(),pq[j].pop();
        cout<<ans<<endl;
        for(int j=1;j<=3;++j) while(t[j])
            t[j]--,pq[j].pop();
    }
    return 0; 
}
/*
something fun:
one contestant in our classroom(racepoint)
don't know how to use freopen!!!!
hahaha!!!
*/
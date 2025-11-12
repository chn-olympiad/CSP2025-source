#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;
const int N=1e5+10;
int n,a[N][4],res,c[4];
priority_queue<pii,vector<pii>,greater<pii>> q[4];
bool v[N],vv[4];
int calc(int i,int j){
    if(j==1){
        if(max(a[i][2],a[i][3])>a[i][1]) return a[i][1]-min(a[i][2],a[i][3]);
        return a[i][1]-max(a[i][2],a[i][3]);
    }
    if(j==2){
        if(max(a[i][1],a[i][3])>a[i][2]) return a[i][2]-min(a[i][1],a[i][3]);
        return a[i][2]-max(a[i][1],a[i][3]);
    }
    if(j==3){
        if(max(a[i][2],a[i][1])>a[i][3]) return a[i][3]-min(a[i][2],a[i][1]);
        return a[i][3]-max(a[i][2],a[i][1]);
    }
    return 0;
}
vector<int> cc[4];
void qwq(){
    int sum=0;
    for(auto i:cc[1]) sum+=a[i][1];
    for(auto i:cc[2]) sum+=a[i][2];
    for(auto i:cc[3]) sum+=a[i][3];
    res=max(res,sum);
}
void dfs(int st){
    if(st>n) return qwq();
    for(int j=1;j<=3;++j){
        if(cc[j].size()>=n/2) continue;
        cc[j].push_back(st);
        dfs(st+1);
        cc[j].pop_back();
    }
}
void solve(){
    res=0;
    for(int i=1;i<=3;++i){
        q[i]=priority_queue<pii,vector<pii>,greater<pii>>();
        c[i]=0;
    }
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j){
            cin>>a[i][j];
            if(j>1&&a[i][j]) f=0;
        }
    }
    if(n<=10){
        dfs(1);
        cout<<res<<"\n";
        return;
    }
    if(f){
        priority_queue<int> qq;
        for(int i=1;i<=n;++i) qq.push(a[i][1]);
        int cnt=0;
        while(qq.size()&&cnt<n/2){
            res+=qq.top();
            qq.pop();
            ++cnt;
        }
        cout<<res<<"\n";
        return;
    }
    for(int i=1;i<=n;++i){
        if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
            ++c[1];
            res+=a[i][1];
            q[1].push({a[i][1]-a[i][2],2});
            q[1].push({a[i][1]-a[i][3],3});
        }
        else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
            ++c[2];
            res+=a[i][2];
            q[2].push({a[i][2]-a[i][1],1});
            q[2].push({a[i][2]-a[i][3],3});
        }
        else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
            ++c[3];
            res+=a[i][3];
            q[3].push({a[i][3]-a[i][1],1});
            q[3].push({a[i][3]-a[i][2],2});
        }
    }
    if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2) return cout<<res<<"\n",void();
    while(q[1].size()&&c[1]>n/2){
        auto x=q[1].top();
        q[1].pop();
        if(c[x.second]==n/2) continue;
        res-=x.first;
        ++c[x.second];
        --c[1];
    }
    while(q[2].size()&&c[2]>n/2){
        auto x=q[2].top();
        q[2].pop();
        if(c[x.second]==n/2) continue;
        res-=x.first;
        ++c[x.second];
        --c[2];
    }
    while(q[3].size()&&c[3]>n/2){
        auto x=q[3].top();
        q[3].pop();
        if(c[x.second]==n/2) continue;
        res-=x.first;
        ++c[x.second];
        --c[3];
    }
    cout<<res<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
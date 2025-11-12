#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int t,n,a[N][4],cnt[4];
ll ans;
struct node{
    int id,w;
    bool operator<(const node& b)const{
        return w>b.w;
    }
};
priority_queue<node> q[4];
void pu(int id);
void change(int z,node to){
    node from=q[z].top();
    q[z].pop();
    q[z].push(to);
    ans=ans-from.w+to.w;
    pu(from.id);
}
void pu(int id){
    int i=id;
    if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
        if(cnt[1]<n/2){
            ans+=a[i][1];
            q[1].push({i,a[i][1]});
        }else if(a[i][1]>q[1].top().w){
            change(1,{i,a[i][1]});
        }
    }else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
        if(cnt[2]<n/2){
            ans+=a[i][2];
            q[2].push({i,a[i][2]});
        }else if(a[i][2]>q[2].top().w){
            change(2,{i,a[i][2]});
        }
    }else if(a[i][3]>=a[i][1]&&a[i][3]>a[i][2]){
        if(cnt[3]<n/2){
            ans+=a[i][3];
            q[3].push({i,a[i][3]});
        }else if(a[i][3]>q[3].top().w){
            change(3,{i,a[i][3]});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("club1.in","r",stdin);
//    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=3;i++){
            cnt[i]=0;
            while(q[i].size()) q[i].pop();
        }
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pu(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}


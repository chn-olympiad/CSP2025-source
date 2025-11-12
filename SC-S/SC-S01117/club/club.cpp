#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
using ll=long long;
const int N=1e5+5;
struct node{
    ll w;
    int to,id;
    bool operator < (const node &t) const{
        return w<t.w;
    }
};
priority_queue<node> q[3];
int cnt[3];
int n;
ll a[N][3];
void pushin(int d,int id){
    ++cnt[d];
    if(a[id][(d+1)%3]>a[id][(d+2)%3]) q[d].push({a[id][(d+1)%3]-a[id][d],(d+1)%3,id});
    else q[d].push({a[id][(d+2)%3]-a[id][d],(d+2)%3,id});
}
void slv(){
    for(int i=0;i<3;++i){
        cnt[i]=0;
        while(!q[i].empty()) q[i].pop();
    }
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;++i){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        ll w0=a[i][0];
        if(cnt[0]==(n>>1)) w0+=q[0].top().w;
        ll w1=a[i][1];
        if(cnt[1]==(n>>1)) w1+=q[1].top().w;
        ll w2=a[i][2];
        if(cnt[2]==(n>>1)) w2+=q[2].top().w;
        ll mx=max(w0,max(w1,w2));
        ans+=mx;
        if(w0==mx){
            if(cnt[0]==(n>>1)){
                node t=q[0].top();
                q[0].pop();
                --cnt[0];
                pushin(t.to,t.id);
            }
            pushin(0,i);
        }else if(w1==mx){
            if(cnt[1]==(n>>1)){
                node t=q[1].top();
                q[1].pop();
                --cnt[1];
                pushin(t.to,t.id);
            }
            pushin(1,i);
        }else{
            if(cnt[2]==(n>>1)){
                node t=q[2].top();
                q[2].pop();
                --cnt[2];
                pushin(t.to,t.id);
            }
            pushin(2,i);
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int T;
    cin>>T;
    while(T--) slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
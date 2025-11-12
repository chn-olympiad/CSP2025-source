#include<bits/stdc++.h>
using namespace std;
#define N 10010
struct edge{
    int v,e;
};
struct node{
    int i,x;
};
bool operator<(const node& n,const node& m){
    return n.x>n.x;
}
int a[N],dis[N];
bool z[N];
priority_queue<node> q;
vector<edge> tr[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(dis,0x3f,sizeof dis);
    int n,m,k;
    cin>>n>>m>>k;
    while(m--){
        int u,v,e;
        cin>>u>>v>>e;
        tr[u].push_back({v,e});
        tr[v].push_back({u,e});
    }
    long long ans=0;
    int d=(rand()%n)+1;
    q.push({d,0});
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(z[t.i])continue;
        ans+=t.x;
        z[t.i]=1;
        for(auto i:tr[t.i]){
            if(z[i.v]) continue;
            if(i.e<dis[i.v]){
                dis[i.v]=i.e;
                q.push({i.v,i.e});
            }
        }
    }
	cout<<ans;
    return 0;
}

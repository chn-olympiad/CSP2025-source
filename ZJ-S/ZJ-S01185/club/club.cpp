#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll read(){
    ll w=1,c,ret;
    while((c=getchar())<'0'||c>'9') w=(c=='-'?-1:1);
    ret=c-48;
    while((c=getchar())>='0'&&c<='9') ret=ret*10+c-48;
    return w*ret;
}

int const maxn=1e5+5;

int n;

int a[maxn][10];

struct node{
    int pos;
    int id1,id2;
    int val;

    bool operator<(node const &x) const{
        return x.val<val;
    }
};


int cnt[10];

void sol(){
    priority_queue<node>  pq[3];
    memset(cnt,0,sizeof(cnt));

    n=read();
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2;j++) a[i][j]=read();
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        int mx1=max({a[i][0],a[i][1],a[i][2]}),mx2=0;
        int id1=0,id2=0;
        if(mx1==a[i][0]){
            id1=0;
            mx2=max(a[i][1],a[i][2]);
            if(mx2==a[i][1]) id2=1;
            else id2=2;
        }else if(mx1==a[i][1]){
            id1=1;
            mx2=max(a[i][0],a[i][2]);
            if(mx2==a[i][0]) id2=0;
            else id2=2;
        }else{
            id1=2;
            mx2=max(a[i][0],a[i][1]);
            if(mx2==a[i][0]) id2=0;
            else id2=1;
        }
        if(cnt[id1]<n/2){
            ans+=mx1;
            pq[id1].push({i,id1,id2,mx1-mx2});
            cnt[id1]++;

        }else{
            //1:
            auto k=pq[id1].top();
            if(ans+mx1-pq[id1].top().val>=ans+mx2){
                ans=ans+mx1-pq[id1].top().val;
                pq[id1].pop();
                cnt[k.id2]++;
                pq[id1].push({i,id1,id2,mx1-mx2});
            }else{
                ans=ans+mx2;
                cnt[id2]++;
            }

        }

    }
    cout<<ans<<'\n';


}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.ans","w",stdout);
    int _=read();
    while(_--){
        sol();
    }

    
    





    return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/
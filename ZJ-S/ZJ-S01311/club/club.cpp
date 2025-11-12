#include<bits/stdc++.h>
using namespace std;
#define N 100010
struct node{
    int x;
    int i;
};
bool operator<(const node& n,const node& m){
    return n.x<m.x;
}
int a[N],b[N],c[N];
int f[N];
int n,x,y,z;
priority_queue<node> qu[3];
inline void pa(int i){
    x++;
    qu[0].push({b[i]-a[i],1});
    qu[0].push({c[i]-a[i],2});
}inline void pb(int i){
    y++;
    qu[1].push({a[i]-b[i],0});
    qu[1].push({c[i]-b[i],2});
}inline void pc(int i){
    z++;
    qu[2].push({b[i]-c[i],1});
    qu[2].push({a[i]-c[i],0});
}
int add(int i){
    if(a[i]>b[i]){
        if(a[i]>c[i]){
            pa(i);
            return a[i];
        }else if(a[i]<c[i]){
            pc(i);
            return c[i];
        }else{
            if(x<z) pa(i);
            else pc(i);
            return a[i];
        }
    }else if(a[i]<b[i]){
        if(b[i]>c[i]){
            pb(i);
            return b[i];
        }else if(b[i]<c[i]){
            pc(i);
            return c[i];
        }else{
            if(z<y) pc(i);
            else pb(i);
            return b[i];
        }
    }else{
        if(c[i]>a[i]){
            pc(i);
            return c[i];
        }else if(c[i]<a[i]){
            if(x<y) pa(i);
            else pb(i);
            return a[i];
        }else if(x>y){
            if(y<z) pb(i);
            else pc(i);
            return b[i];
        }else if(x>z){
            pc(i);
            return c[i];
        }else{
            pa(i);
            return a[i];
        }
    }
}int query(int i){
    int g[3]={x,y,z};
    int ans=0;
    while(!qu[i].empty()){
        node x=qu[i].top();
        qu[i].pop();
        if(g[x.i]<n/2){
            g[x.i]++;
            ans+=x.x;
        }else continue;
        g[i]--;
        if(g[i]<=n/2) break;
    }return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        long long ans=0;
        x=0;y=0;z=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            ans+=add(i);
        }if(x>n/2)ans+=query(0);
        else if(y>n/2) ans+=query(1);
        else if(z>n/2) ans+=query(2);
        cout<<ans<<'\n';
        while(!qu[0].empty())qu[0].pop();
        while(!qu[1].empty())qu[1].pop();
        while(!qu[2].empty())qu[2].pop();
    }
    return 0;
}

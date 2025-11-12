#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
struct node{
    int q,id;
}p1[N];
int t,n,a[N][4],d[4],maxn;
ll ans,res;

bool cmp(node a,node b){
    return a.q>b.q;
}

void dfs(int x){
    if(x==n+1){
        ans=max(ans,res);
        return;
    }
    for(int i=1;i<=3;i++){
        if(d[i]<maxn){
            d[i]++;
            res+=a[x][i];
            dfs(x+1);
            res-=a[x][i];
            d[i]--;
        }
    }
}

void solve1(){
    for(int i=1;i<=n;i++){
        p1[i].q=a[i][1]-a[i][2];
        p1[i].id=i;
    }
    sort(p1+1,p1+1+n,cmp);
    for(int i=1;i<=(n>>1);i++){
        ans+=a[p1[i].id][1];
    }
    for(int i=maxn+1;i<=n;i++){
        ans+=a[p1[i].id][2];
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        maxn=n>>1;
        for(int i=1;i<=3;i++){
            d[i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        int f=1,f2=1;
        for(int i=1;i<=n;i++){
            if(a[i][3]){f=0;f2=0;}
            if(a[i][2]){f2=0;}
        }
        if(f2){
            for(int i=1;i<=n;i++){
                ans+=a[i][1];
            }
            cout<<ans<<endl;
            continue;
        }
        if(f){
            solve1();
            cout<<ans<<endl;
            continue;
        }
        ans=0;res=0;
        dfs(1);
        cout<<ans<<endl;;
    }
    return 0;
}

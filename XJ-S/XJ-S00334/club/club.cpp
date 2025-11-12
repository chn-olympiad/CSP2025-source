#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5+16;
int t,n;
struct ch{
    int z,w;
}a[MAXN],b[MAXN],c[MAXN];
int maxn[MAXN],size[8];
bool f[MAXN];
int ans,cnt;
struct node{
    int first,second,third;
}d[MAXN];
struct node1{
    int a,b,c;
};
bool cmp1(ch x,ch y){return x.z>y.z;}
void print(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i].first>>d[i].second>>d[i].third;
        //maxn[i]=max(d[i].first,max(d[i].second,d[i].third));
    }
}
void dfs(int x,int sum){
    cnt++;
    if(x>=n+1){
        ans=max(ans,sum);
        return ;
    }
    if(cnt>100000000)exit(0);
    if(size[1]<n/2)size[1]++,dfs(x+1,sum+d[x].first),size[1]--;
    if(size[2]<n/2)size[2]++,dfs(x+1,sum+d[x].second),size[2]--;
    if(size[3]<n/2)size[3]++,dfs(x+1,sum+d[x].third),size[3]--;

}
int main(){
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        memset(f,0,sizeof(f));
        memset(size,0,sizeof(size));
        print();
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
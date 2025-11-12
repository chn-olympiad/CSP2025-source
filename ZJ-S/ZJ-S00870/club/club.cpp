#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int t;
int n,ans;
struct node{
    int v,id;
}a[100005][4];
struct node2{
    int f,s;
    bool operator<(node2 x) const{
        return f-s>x.f-x.s;
    }
};
bool cmp(node x,node y){
    return x.v>y.v;
}
signed main(){
    //freopen("club5.in","r",stdin);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j].v;
                a[i][j].id=j;
            }
            sort(a[i]+1,a[i]+4,cmp);
        }
        priority_queue<node2> q[4];
        for(int i=1;i<=n;i++){
            if(q[a[i][1].id].size()<n/2){
                q[a[i][1].id].push({a[i][1].v,a[i][2].v});
                ans+=a[i][1].v;
            }else{
                node2 x=q[a[i][1].id].top();
                int a1=x.s+a[i][1].v;
                int a2=x.f+a[i][2].v;
                if(a1>a2){
                    q[a[i][1].id].pop();
                    q[a[i][1].id].push({a[i][1].v,a[i][2].v});
                    ans=ans-x.f+a1;
                }else{
                    ans+=a[i][2].v;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

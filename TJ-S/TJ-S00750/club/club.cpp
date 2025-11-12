#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int T,n,a[N+5][4];
priority_queue<pair<int,int>>q[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if (a[i][1]>=max(a[i][2],a[i][3]))
                q[1].push({max(a[i][2],a[i][3])-a[i][1],a[i][1]});
            else if (a[i][2]>=max(a[i][1],a[i][3]))
                q[2].push({max(a[i][1],a[i][3])-a[i][2],a[i][2]});
            else
                q[3].push({max(a[i][1],a[i][2])-a[i][3],a[i][3]});
        }
        int ans=0;
        if (((int)q[1].size())>n/2){
            while (((int)q[1].size())>n/2){
                pair<int,int>x=q[1].top();q[1].pop();
                ans+=x.first+x.second;
            }
        }
        if (((int)q[2].size())>n/2){
            while (((int)q[2].size())>n/2){
                pair<int,int>x=q[2].top();q[2].pop();
                ans+=x.first+x.second;
            }
        }
        if (((int)q[3].size())>n/2){
            while (((int)q[3].size())>n/2){
                pair<int,int>x=q[3].top();q[3].pop();
                ans+=x.first+x.second;
            }
        }
        while(!q[1].empty()){
            pair<int,int>x=q[1].top();q[1].pop();
            ans+=x.second;
        }
        while(!q[2].empty()){
            pair<int,int>x=q[2].top();q[2].pop();
            ans+=x.second;
        }
        while(!q[3].empty()){
            pair<int,int>x=q[3].top();q[3].pop();
            ans+=x.second;
        }
        printf("%d\n",ans);
    }
    return 0;
}

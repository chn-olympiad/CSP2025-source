#include <bits/stdc++.h>
const int Maxn=1e5+11;
using namespace std;
int T,n;
struct Node
{
    pair<int,int> a[4];
    bool operator<(const Node &x)const
    {
        int i=3;
        while(i>1&&a[i].first==x.a[i].first){
            i--;
        }
        return a[i].first<x.a[i].first;
    }
}dt[Maxn];
int cnt[4];
int ans;
priority_queue<pair<int,int> > q[4][4];
int used[Maxn][4];
void ins(int i,int j_0)
{
    int ttj;
    int x=dt[i].a[j_0].first;
    for(int j=1;j<=3;j++){
        int nx=dt[i].a[j].first;
        int nj=dt[i].a[j].second;
        if(j==j_0){
            used[i][nj]=1;
            cnt[nj]++;
            ttj=nj;
            break;
        }
    }
    for(int j=1;j<=3;j++){
        int nx=dt[i].a[j].first;
        int nj=dt[i].a[j].second;
        if(j==j_0){
            continue;
        }
        q[ttj][nj].push({nx-x,i});
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin >>T;
    while(T--){
        memset(dt,0,sizeof(dt));
        memset(cnt,0,sizeof(cnt));
        memset(q,0,sizeof(q));
        memset(used,0,sizeof(used));
        cin >>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >>dt[i].a[j].first;
                dt[i].a[j].second=j;
            }
            sort(dt[i].a+1,dt[i].a+4);
        }
        sort(dt+1,dt+n+1);
        ans=0;
        for(int i=n;i>=1;i--){
            int x=dt[i].a[3].first,x_1=dt[i].a[2].first,x_2=dt[i].a[1].first;
            int j=dt[i].a[3].second,j_1=dt[i].a[2].second,j_2=dt[i].a[1].second;
            if(cnt[j]<(n>>1)){
                ins(i,3);
                ans+=x;
            }
            else{
                while(used[q[j][j_1].top().second][j]==0){
                    q[j][j_1].pop();
                }
                int po_1=q[j][j_1].top().first+x;
                while(used[q[j][j_2].top().second][j]==0){
                    q[j][j_2].pop();
                }
                int po_2=q[j][j_2].top().first+x;
                if(x_1>=po_1&&x_1>=po_2){
                    ins(i,2);
                    ans+=x_1;
                }
                else{
                    cnt[j]--;
                    ins(i,3);
                    int newi;
                    if(po_1>=po_2){
                        newi=q[j][j_1].top().second;
                        ans+=po_1;
                        ins(newi,2);
                    }
                    else{
                        newi=q[j][j_2].top().second;
                        ans+=po_2;
                        ins(newi,1);
                    }
                    used[newi][j]=0;
                }
            }
        }
        cout <<ans<<'\n';
    }
}

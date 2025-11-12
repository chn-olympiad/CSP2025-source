#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct node{
    int x,y,z;
};

const int N=1e5+10;
int t,n;
node a[N];
bool vis[N];

inline bool cmp(node a,node b){ return a.x>b.x; }
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        vector<int> c1,c2,c3;
        for (int i=1;i<=n;++i){
            if (a[i].x>=a[i].y && a[i].x>=a[i].z) c1.push_back(i);
            else if (a[i].y>=a[i].x && a[i].y>=a[i].z) c2.push_back(i);
            else c3.push_back(i);
        }
        int l1=c1.size(),l2=c2.size(),l3=c3.size(),ans=0,res=0;
        for (auto i:c1) ans+=a[i].x;
        for (auto i:c2) ans+=a[i].y;
        for (auto i:c3) ans+=a[i].z;
        vector<pii> tmp;
        if (l1>n/2){
            memset(vis,0,sizeof vis);
            int s=ans;
            for (auto i:c1)
                tmp.push_back({a[i].x-a[i].y,i}),tmp.push_back({a[i].x-a[i].z,-i});
            sort(tmp.begin(),tmp.end());
            for (int i=0,cnt=0;cnt<l1-n/2;++i){
                if (vis[abs(tmp[i].second)]) continue;
                s-=tmp[i].first,vis[abs(tmp[i].second)]=1,++cnt;
                if (tmp[i].second>0) ++l2;
                else ++l3;
            }
            if (l2>n/2){
                tmp.clear();
                for (auto i:c2) tmp.push_back({a[i].y-a[i].z,0});
                sort(tmp.begin(),tmp.end());
                for (int i=0;i<l2-n/2;++i) s-=tmp[i].first;
            }else if (l3>n/2){
                tmp.clear();
                for (auto i:c3) tmp.push_back({a[i].z-a[i].y,0});
                sort(tmp.begin(),tmp.end());
                for (int i=0;i<l3-n/2;++i) s-=tmp[i].first;
            }
            res=max(res,s);
        }
        if (l2>n/2){
            int s=ans;
            tmp.clear();
            memset(vis,0,sizeof vis);
            for (auto i:c2) tmp.push_back({a[i].y-a[i].x,i}),tmp.push_back({a[i].y-a[i].z,-i});
            sort(tmp.begin(),tmp.end());
            for (int i=0,cnt=0;cnt<l2-n/2;++i){
                if (vis[abs(tmp[i].second)]) continue;
                s-=tmp[i].first,vis[abs(tmp[i].second)]=1,++cnt;
                if (tmp[i].second>0) ++l1;
                else ++l3;
            }
            if (l1>n/2){
                tmp.clear();
                for (auto i:c1) tmp.push_back({a[i].x-a[i].z,0});
                sort(tmp.begin(),tmp.end());
                for (int i=0;i<l1-n/2;++i) s-=tmp[i].first;
            }else if (l3>n/2){
                tmp.clear();
                for (auto i:c3) tmp.push_back({a[i].z-a[i].x,0});
                sort(tmp.begin(),tmp.end());
                for (int i=0;i<l3-n/2;++i) s-=tmp[i].first;
            }
            res=max(res,s);
        }
        if (l3>n/2){
            int s=ans;
            tmp.clear();
            memset(vis,0,sizeof vis);
            for (auto i:c3) tmp.push_back({a[i].z-a[i].x,i}),tmp.push_back({a[i].z-a[i].y,-i});
            sort(tmp.begin(),tmp.end());
            for (int i=0,cnt=0;cnt<l3-n/2;++i){
                if (vis[abs(tmp[i].second)]) continue;
                s-=tmp[i].first,vis[abs(tmp[i].second)]=1,++cnt;
                if (tmp[i].second>0) ++l1;
                else ++l2;
            }
            if (l1>n/2){
                tmp.clear();
                for (auto i:c1) tmp.push_back({a[i].x-a[i].y,0});
                sort(tmp.begin(),tmp.end());
                for (int i=0;i<l1-n/2;++i) s-=tmp[i].first;
            }else if (l2>n/2){
                tmp.clear();
                for (auto i:c3) tmp.push_back({a[i].y-a[i].x,0});
                sort(tmp.begin(),tmp.end());
                for (int i=0;i<l2-n/2;++i) s-=tmp[i].first;
            }
            res=max(res,s);
        }
        printf("%d\n",res==0?ans:res);
    }
    return 0;
}

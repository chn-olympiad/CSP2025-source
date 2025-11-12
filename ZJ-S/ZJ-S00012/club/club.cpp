#include<bits/stdc++.h>
#define MAXN 100005
#define int long long
using namespace std;
struct edge{
    int from,weight;
    bool operator<(edge x){
        return weight<x.weight;
    }
};
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,sum=0,count[4],p[MAXN][4],maxn,minx,miny,cur=0,cnt=0,changed[MAXN];
        edge f[MAXN*2];
        cin>>n;
        memset(count,0,sizeof(count));
        memset(p,0,sizeof(p));
        memset(changed,0,sizeof(changed));
        for(int i=1;i<=n;i++){
            cin>>p[i][1]>>p[i][2]>>p[i][3];
            if(p[i][1]>=p[i][2]&&p[i][1]>=p[i][3]){
                sum+=p[i][1];
                count[1]++;
            }else if(p[i][2]>=p[i][1]&&p[i][2]>=p[i][3]){
                sum+=p[i][2];
                count[2]++;
            }else{
                sum+=p[i][3];
                count[3]++;
            }
        }
        if(count[1]>=count[2]&&count[1]>=count[3]){
            maxn=1,minx=2,miny=3;
        }else if(count[2]>=count[1]&&count[2]>=count[3]){
            maxn=2,minx=1,miny=3;
        }else{
            maxn=3,minx=1,miny=2;
        }
        for(int i=1;i<=n;i++){
            if(p[i][1]>=p[i][2]&&p[i][1]>=p[i][3]&&maxn==1){
                f[++cnt]={i,p[i][maxn]-p[i][minx]};
                f[++cnt]={i,p[i][maxn]-p[i][miny]};
            }else if(p[i][2]>=p[i][1]&&p[i][2]>=p[i][3]&&maxn==2){
                f[++cnt]={i,p[i][maxn]-p[i][minx]};
                f[++cnt]={i,p[i][maxn]-p[i][miny]};
            }else if(p[i][3]>=p[i][1]&&p[i][3]>p[i][2]&&maxn==3){
                f[++cnt]={i,p[i][maxn]-p[i][minx]};
                f[++cnt]={i,p[i][maxn]-p[i][miny]};
            }
        }
        sort(f+1,f+cnt+1);
        while(count[maxn]>n/2){
            cur++;
            if(changed[f[cur].from]){
                continue;
            }
            sum-=f[cur].weight;
            count[maxn]--;
            changed[f[cur].from]=1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
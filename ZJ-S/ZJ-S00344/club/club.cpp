#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int n,m;
int d[N][3],c[3];
void calc(){
    scanf("%d",&n);
    c[0]=c[1]=c[2]=0;
    LL ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&d[i][0],&d[i][1],&d[i][2]);
        if(d[i][0]>=d[i][1] && d[i][0]>=d[i][2]) c[0]++,ans+=d[i][0];
        else if(d[i][1]>=d[i][0] && d[i][1]>=d[i][2]) c[1]++,ans+=d[i][1];
        else c[2]++,ans+=d[i][2];
    }
    int t=max(c[0],max(c[1],c[2]));
    if(t<=n/2) printf("%lld\n",ans);
    else{
        vector<int>v;
        for(int i=1;i<=n;i++){
            if(d[i][0]>=d[i][1] && d[i][0]>=d[i][2]){
                if(t==c[0])
                    v.push_back(min(d[i][0]-d[i][1],d[i][0]-d[i][2])); 
            }
            else if(d[i][1]>=d[i][0] && d[i][1]>=d[i][2]){
                if(t==c[1])
                    v.push_back(min(d[i][1]-d[i][0],d[i][1]-d[i][2])); 
            }
            else{
                if(t==c[2])
                    v.push_back(min(d[i][2]-d[i][0],d[i][2]-d[i][1]));
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;t>n/2;i++,t--)
            ans-=v[i];
        printf("%lld\n",ans);
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) calc();
    return 0;
}
//g++ club.cpp -o a -O2
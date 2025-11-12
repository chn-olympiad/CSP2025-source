#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int hus[5];
long long maxans=LLONG_MIN;
struct stu{
    int man[5];
    int id;
}stlist[100010];
void dfs(int level,long long ans,int hu[]){
    if(level==n){
        if(ans>maxans)
            maxans=ans;
        return;
    }
    else{
        if(hu[1]<n/2){
            hu[1]++;
            dfs(level+1,ans+stlist[level+1].man[1],hu);
            hu[1]--;
        }
        if(hu[2]<n/2){
            hu[2]++;
            dfs(level+1,ans+stlist[level+1].man[2],hu);
            hu[2]--;
        }
        if(hu[3]<n/2){
            hu[3]++;
            dfs(level+1,ans+stlist[level+1].man[3],hu);
            hu[3]--;
        }
    }
    return;
}
bool cmp(stu a,stu b){
    return a.man[1]>b.man[1];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        maxans=LLONG_MIN;
        memset(stlist,0,sizeof(stlist));
        memset(hus,0,sizeof(hus));
        scanf("%d",&n);
        bool flag=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&stlist[i].man[j]);
                if(stlist[i].man[j]!=0&&(j==2||j==3))
                    flag=true;
            }
        }
        if(flag){
            dfs(0,0,hus);
        }
        else{
            sort(stlist+1,stlist+1+n,cmp);
            maxans=0;
            for(int i=1;i<=n/2;i++)
                maxans+=stlist[i].man[1];
        }
        printf("%lld\n",maxans);
    }
    return 0;
}

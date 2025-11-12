#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
bool Fa=0,Fb=0,Fc=0;
void bfs(int r,int cnt,vector<vector<int>>st){
    for(int i=r+1;i<=n;i++){
        for(int j:st[i]){
            bfs(j,cnt+1,st);
        }
    }
    ans=max(ans,cnt);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        if(v[i]==1) Fa=1;
        else if(v[i]==0) Fb=1;
        else Fc=1;
    }
    if(Fa&&!Fb){
        printf("%d",n/2);
        return 0;
    }
    else if(Fa&&Fb&&!Fc){
        if(k==0){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(v[i]==0) ans++;
                else if(i<n&&v[i]==1&&v[i+1]==1) ans++,i++;
            }
            printf("%d",ans);
            return 0;
        }else if(k==1){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(v[i]==1) ans++;
            }
            printf("%d",ans);
            return 0;
        }
    }
    vector<vector<int>>f(n+1,vector<int>(n+1,-1)),st(n+1);
    for(int i=1;i<=n;i++){
        f[i][i]=v[i];
        for(int j=i+1;j<=n;j++){
            f[i][j]=f[i][j-1]^v[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[i][j]==k) st[i].push_back(j);
        }
    }
    bfs(0,0,st);
    printf("%d",ans);
    return 0;
}


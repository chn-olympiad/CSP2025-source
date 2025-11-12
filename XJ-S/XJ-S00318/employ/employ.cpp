#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const long long pp=998244353;
int n,m,cnt,k;
char c[maxn];
int a[maxn];
int p[maxn],vis[maxn];
long long ans;
void dfs1(int x){
    if(x>n){
        cnt=0; k=0;
        for(int i=1;i<=n;i++){
            if(c[i]=='0'){
                cnt++;
            } else{
                if(cnt>=a[p[i]]) cnt++;
                else k++;
            }
        }
        if(k>=m) ans++;
        return; 
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1) continue;
        vis[i]=1, p[x]=i;
        dfs1(x+1);
        vis[i]=0, p[x]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool flg=1;
    cin>>(c+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(c[i]=='0') flg=0;
        if(a[i]==0) flg=0;
    }
    if(n==m){
        if(flg==0) cout<<"0";
        else{
            ans=1LL;
            for(int i=1;i<=n;i++) ans=ans*i%pp;
            cout<<ans;
        }
    }
    else{
        dfs1(1);
        cout<<ans;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,lst[maxn],pre[maxn],f[maxn][2],ans;
unordered_map<int,int> mp;

int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read(),k=read();
    for(int i=1;i<=n;i++) lst[i]=read();
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]^lst[i];
    for(int i=1;i<=n;i++){
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        f[i][1]=((mp[pre[i]^k]||(!(pre[i]^k)))?f[mp[pre[i]^k]+1][0]+1:0);
        if(lst[i]==k) f[i][1]=max(f[i][1],max(f[i-1][1],f[i-1][0])+1);
        mp[pre[i]]=i;
        ans=max({ans,f[i][0],f[i][1]});
        // cout<<f[i][0]<<f[i][1]<<endl;
    }
    // for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
    cout<<ans;
    return 0;
}
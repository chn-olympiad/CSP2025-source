#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int f,s,t;
}a[N];
int n,c[5],g[N],f[N],maxv[N],maxi[N];
void solve(){
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].f>>a[i].s>>a[i].t;
        int f=a[i].f,s=a[i].s,t=a[i].t;
        if(f>t&&f>s){
            maxv[i]=f,maxi[i]=1;
            g[i]=f-max(t,s);
        }
        else if(t>s&&t>f){
            maxv[i]=t,maxi[i]=3;
            g[i]=t-max(f,s);
        }
        else if(s>t&&s>f){
            maxv[i]=s,maxi[i]=2;
            g[i]=s-max(f,t);
        }
    }
    for(int i=1;i<=n;i++){
        int s=maxv[i]-g[i];
        if(c[maxi[i]]<(n/2)){
            f[i]=f[i-1]+maxv[i];
            c[maxi[i]]++;
        }else{
            f[i]=f[i-1]+s;
            for(int j=1;j<=i-1;j++){
                if(maxi[j]!=maxi[i]) continue;
                f[i]=max(f[i],f[i-1]-g[j]+maxv[i]);
                maxi[j]+=1;
            }
        }
    }
    cout<<f[n]<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
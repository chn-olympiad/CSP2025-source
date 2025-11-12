#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int NN=998244353;
int n,m;
string s;
int ans;
int g[550][550],f[2][550][550];
int c[550][550];
int a[100100],b[100100];
void add(int &x,int y){
    x=(x+y)%NN;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;s=" "+s;
    for (int i=1,x;i<=n;i++)
    cin>>x,a[x]++;
    c[0][0]=1;
    for (int i=1;i<=n;i++){
        c[i][0]=1;
        for (int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%NN;
        }
    }
    b[0]=a[0];
    for (int i=1;i<=n;i++)
    b[i]=b[i-1]+a[i];
    // for (int i=0;i<=n;i++)
    // cout<<b[i]<<" ";cout<<"\n";
    f[0][0][b[0]]=1;
    int w=0;
    for (int i=1;i<=n;i++){
        w^=1;
        // memset(g,0,sizeof(g));
        for (int j=0;j<i;j++)
        for (int k=0;k<=n;k++)
        if(f[w^1][j][k]!=0){
            if(k)add(g[j+1][k-1],f[w^1][j][k]*k);
            if(s[i]=='1')add(f[w][j][k],f[w^1][j][k]);
            else add(g[j+1][k],f[w^1][j][k]);
            f[w^1][j][k]=0;
        }
        for (int j=1;j<=i;j++){
            for (int k=0;k<=n;k++)
            if(g[j][k]!=0){
                int tmp=i-(b[j-1]-k);
                for (int t=a[j],s=g[j][k];t>=0;t--,s=s*tmp%NN,tmp--)
                add(f[w][j][k+t],s*c[a[j]][t]);
                g[j][k]=0;
            }
        }
    }
    for (int i=0;i<=n-m;i++){
        int sum=f[w][i][0];
        for (int j=1;j<=n-b[i];j++)sum=sum*j%NN;
        add(ans,sum);
    }
    cout<<ans<<"\n";
}
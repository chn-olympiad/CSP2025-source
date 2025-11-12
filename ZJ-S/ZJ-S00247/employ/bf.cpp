#include<bits/stdc++.h>
using namespace std;
const int maxn=505,Mod=998244353;
int N,M,A[maxn],C[maxn][maxn],F[maxn][maxn][maxn],Pre[maxn],fac[maxn];
string s;
void reduce(int &x){if(x>=Mod) x-=Mod;}
int Get_C(int x,int y){
    if(x<0||y<0||x<y) return 0;
    return C[x][y];
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>s;s=" "+s;int ret=0;for(int i=1;i<=N;i++) if(s[i]=='0') ret++;
    fac[0]=1;
    for(int i=1,x;i<=N;i++) cin>>x,A[x]++,Pre[x]++,fac[i]=1ll*fac[i-1]*i%Mod;
    for(int i=1;i<=N;i++) Pre[i]+=Pre[i-1];
    for(int i=0;i<=N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++) reduce(C[i][j]=C[i-1][j]+C[i-1][j-1]);
    }
    F[0][0][0]=1;int sum=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++)
        for(int k=0;k<=i;k++)
        if(F[i][j][k]){
            int val=F[i][j][k];
            if(s[i+1]=='0'){
                for(int l=0;l<=k;l++) F[i+1][j+1][k-l]=(F[i+1][j+1][k-l]+1ll*val*C[k][l]%Mod*C[A[j+1]][l]%Mod*fac[l])%Mod;
            }
            if(s[i+1]=='1'&&Pre[j]-(sum-k)>0){
                int v=1ll*val*(Pre[j]-(sum-k))%Mod;
                for(int l=0;l<=k;l++) F[i+1][j+1][k-l]=(F[i+1][j+1][k-l]+1ll*v*C[k][l]%Mod*C[A[j+1]][l]%Mod*fac[l])%Mod;
            }
            if(s[i+1]=='1'){
                reduce(F[i+1][j][k+1]+=val);
            }
        }
        if(s[i+1]=='1') sum++;
    }
    // for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) for(int k=0;k<=N;k++) if(F[i][j][k]) printf("%d %d %d %d\n",i,j,k,F[i][j][k]);
    int ans=0;
    for(int i=0;i<=N-M;i++)
    for(int j=0;j<=N;j++)
     if(F[N][i][j]) ans=(ans+1ll*F[N][i][j]*Get_C(N-Pre[i],j)%Mod*fac[j])%Mod;
    ans=1ll*ans*fac[ret]%Mod;
    cout<<ans<<'\n';
    return 0;
}
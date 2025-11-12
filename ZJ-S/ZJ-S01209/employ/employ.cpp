#include<bits/stdc++.h>
#define MAXN 510
using namespace std;
typedef long long ll;
const ll yangfeiting=998244353; // %yangfeiting %yangfeiting
ll n,m;
char s[MAXN];
int S=0;
pair<int,int> f[300000][20];
int c[MAXN];
int x=0;
int cnt(int x){
    int cc=0;
    while(x){
        if(x%2==1) cc++;
        x/=2;
    }
    return cc;
}
void chenduling(){
    int p[12];
    int fangan=1;
    for(int i=1;i<=n;i++){
        p[i]=i;
        fangan*=i;
    }
    int tot=0;
    for(int i=1;i<=fangan;i++){
        int afo=0,afotot=0;
        for(int j=1;j<=n;j++){
            if(s[j]=='0'||afo>=c[p[j]]){
                afotot++;
                afo++;
            }
            else afo=0; 
        }
        if(n-afotot>=m){
            tot++;
        }
        next_permutation(p+1,p+n+1);
    }
    cout << tot;
}
ll ans=0;
void zhuxudan(){
    int tt=0;
    ll anss=1;
    for(int i=1;i<=n;i++){
        if(c[i]==0) tt++;
        anss*=i;
        anss%=yangfeiting;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s+1;
    for(int i=1;i<=n;i++) cin >> c[i];
    bool flag=0;
    for(int i=1;i<=n;i++) if(s[i]=='0') flag=1;
    if(n<=10){
    	chenduling();
    	return 0;
	}
    if(!flag) zhuxudan();
    S=(1<<n)-1;
    for(int i=1;i<=n;i++){
        f[1<<(i-1)][(c[i]!=0 && s[1]=='1')].second=(c[i]!=0 && s[1]=='1');
        f[1<<(i-1)][(c[i]!=0 && s[1]=='1')].first=!(c[i]!=0 && s[1]=='1');
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=S;j++){
            if(j&(1<<(i-1))==0) continue;
            for(int k=1;k<=n;k++){
                if(j&(1<<(k-1))!=0) continue;
                int xxx=cnt(j);
                for(int l=0;l<=xxx;l++){
                    bool zt=(s[xxx]=='1' && f[j][l].first<c[k]);
                    if(zt){
                        f[j|(1<<(k-1))][l+1].first=0;
                        f[j|(1<<(k-1))][l+1].second+=f[j][l].second;
                        f[j|(1<<(k-1))][l+1].second%=yangfeiting;
                    }else{
                        f[j|(1<<(k-1))][l].first=f[j][l].first+1;
                        f[j|(1<<(k-1))][l].second+=f[j][l].second;
                        f[j|(1<<(k-1))][l].second%=yangfeiting;
                    }
                }
            }
        }
    }
    for(int i=m;i<=n;i++){
        ans+=f[S][i].second;
        ans%=yangfeiting;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);



    return 0;
}

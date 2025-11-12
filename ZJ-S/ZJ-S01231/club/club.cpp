#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;

int a[100200][10];
int b[100200];
int f[MAXN][MAXN][MAXN][MAXN];
int n;
int T;
int ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        int flag = 1;
        memset(f,0,sizeof(f));
        ans = 0;
        cin>>n;
        for(int i = 1;i <= n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]) flag = 0;
            b[i] = a[i][1];
        }
        if(flag){
            ans = 0;
            sort(b+1,b+n+1);
            for(int i = n;i>n/2;i--){
                ans += b[i];
            }
            cout<<ans;
            return 0;
        }
        if(n<=55){
            f[1][1][0][0] = a[1][1];
            f[1][0][1][0] = a[1][2];
            f[1][0][0][1] = a[1][3];
            for(int i = 2;i <= n;i++){
                for(int n1 = 0;n1 <= n/2;n1++){
                    for(int n2 = 0;n2<=n/2;n2++){
                        for(int n3 = 0;n3<=n/2;n3++){
                            if(n1>=1) f[i][n1][n2][n3] = max(f[i-1][n1-1][n2][n3]+a[i][1],f[i][n1][n2][n3]);
                            if(n2>=1) f[i][n1][n2][n3] = max(f[i-1][n1][n2-1][n3]+a[i][2],f[i][n1][n2][n3]);
                            if(n3>=1) f[i][n1][n2][n3] = max(f[i-1][n1][n2][n3-1]+a[i][3],f[i][n1][n2][n3]);
                        }
                    }
                }
            }

            for(int n1 = 0;n1 <= n/2;n1++){
                for(int n2 = 0;n2<=n/2;n2++){
                    for(int n3 = 0;n3<=n/2;n3++){
                        ans = max(ans,f[n][n1][n2][n3]);
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
}

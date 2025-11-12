#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int t,n,a[N][3],d[3];
long long dp[N][3];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                d[j] = 0;
                a[i][j] = 0;
                dp[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        for(int i=0;i<3;i++){
            dp[0][i] = a[0][i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                //cout << d[j] << "|";
                if(d[j]<n/2){  
                    int tmp = 0;
                    for(int l=1;l<3;l++){
                        if(dp[i-1][l]>dp[i-1][tmp]) tmp = l;
                    }
                    //cout << tmp << " ";
                    dp[i][j] = dp[i-1][tmp]+a[i][j];
                }
                else{
                    int tmp = abs(j-1);
                    for(int l=0;l<3;l++){
                        if(l!=j && dp[i-1][l]>dp[i-1][tmp] && d[l]<n/2){tmp = l;}
                    }
                    //cout << tmp << " ";
                    dp[i][j] = a[i][j]+dp[i-1][tmp];
                }
                //d[j]++;
            }
            int tmp=0;
            for(int j=0;j<3;j++){
                if(dp[i][j]>=dp[i][tmp]) tmp = j;
            }
            d[tmp]++;
            //cout << endl;
            for(int j=0;j<3;j++){
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        //cout << endl;
        long long ans = -1;
        for(int i=0;i<3;i++){
            ans = max(ans,dp[n-1][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
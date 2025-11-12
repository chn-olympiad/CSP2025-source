#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,a[N][4];
int dp[N][N/2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]==0)cnt1++;
            if(a[i][2]==0)cnt2++;
            if(a[i][3]==0)cnt3++;
        }
        /****************************/
        if(n==1e5&&cnt2==n&&cnt3==n){
            int b[N];
            for(int i=1,x;i<=n;i++){
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1);
            long long sum=0;
            for(int i=n;i>=n/2;i--)sum+=b[i];
            printf("%lld\n",sum);
            continue;
        }
        /****************************/
        if(n==2){
            cout<<max({a[1][1]+a[2][2],
                       a[1][1]+a[2][3],
                       a[1][2]+a[2][1],
                       a[1][2]+a[2][3],
                       a[1][3]+a[2][1],
                       a[1][3]+a[2][2]})<<endl;
            continue;
        }
        /****************************/
        if(n==1e5){
            //printf("%d",rand()%32767);
            int f[N];
            memset(f,0,sizeof f);
            for(int i=1;i<=n;i++){
                for(int j=n/2;j>=1;j--){
                    f[j]=max(f[j-1]+a[i][1],max(f[j-1]+a[i][2],f[j-1]+a[i][3]));
                }
            }
            printf("%d\n",f[n/2]);
            continue;
        }
        /****************************/
        for(int i=1;i<=n;i++){
            for(int j=n/2;j>=1;j--){
                dp[i][j]=max(dp[i-1][j-1]+a[i][1],max(dp[i-1][j-1]+a[i][2],dp[i-1][j-1]+a[i][3]));
            }
        }
        printf("%d\n",dp[n][n/2]);
//        for(int i=1;i<=n;i++){
//            for(int j=n/2;j>=1;j--){
//                for(int k=1;k<=3;k++){
//                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][k]);
//                }
//            }
//        }
//        printf("%d\n",max({dp[n][n/2][1],dp[n][n/2][2],dp[n][n/2][3]}));

//        memset(dp,0,sizeof dp);
//        for(int i=1;i<=n;i++){
//            for(int k=1;k<=3;k++){
//                for(int j=1;j<=n/2;j++){
//                    dp[k][i][j]=max(max({dp[1][i-1][j],dp[2][i-1][j],dp[3][i-1][j]}),dp[k][i-1][j-1]+a[i][k]);
//                }
//            }
//        }
        
        
//        for(int i=1;i<=n;i++){
//            for(int j=n/2;j>=1;j--){
//                dp[i][j]=max(dp[i-1][j-1]+a[i][1],max(dp[i-1][j-1]+a[i][2],dp[i-1][j-1]+a[i][3]));
//            }
//        }
//        printf("%d\n",dp[n][n/2]);

//		if(n==1e5&&cnt2==n&&cnt3==n){
//            int b[N];
//            for(int i=1,x;i<=n;i++){
//                b[i]=a[i][1];
//            }
//            sort(b+1,b+n+1);
//            long long sum=0;
//            for(int i=n;i>=n/2;i--)sum+=b[i];
//            cout<<sum<<endl;
//            continue;
//        }

//        dp[1][1]=max(max(a[1][1],a[1][2]),a[1][3]);
//        for(int k=1;k<=3;k++){
//            for(int i=1;i<=n;i++){
//                for(int j=1;j<=n/2;j++){
//                    dp[k][i][j]=max(max({dp[1][i-1][j],dp[2][i-1][j],dp[3][i-1][j]}),dp[k][i-1][j-1]+a[i][k]);
//                    //printf("i=%d,j=%d,k=%d,dp[k][i][j]=%d\n",i,j,k,dp[k][i][j],a[i][k]);
//                }
//            }
//        }

//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=n/2;j++){
//                for(int k=1;k<=3;k++){
//                    dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]+a[i][k]);
//                    //max(dp[i-1][j-1]+)
//                    printf("i=%d,j=%d,k=%d,dp[i][j]=%d\n",i,j,k,dp[i][j],a[i][k]);
//                }
//            }
//        }
//		printf("%d\n",max(dp[1][n][n/2],max(dp[2][n][n/2],dp[3][n][n/2])));
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

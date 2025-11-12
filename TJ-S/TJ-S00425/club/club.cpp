#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[n+1][n/2+1][n/2+1][n/2+1]={},b[n+1][4];
        for(int i=1;i<=n;i++) scanf("%d%d%d",&b[i][1],&b[i][2],&b[i][3]);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    for(int l=0;l<=n/2;l++){
                    	if(j) a[i][j][k][l]=max(a[i][j][k][l],a[i-1][j-1][k][l]+b[i][1]);
                        if(k) a[i][j][k][l]=max(a[i][j][k][l],a[i-1][j][k-1][l]+b[i][2]);
                        if(l) a[i][j][k][l]=max(a[i][j][k][l],a[i-1][j][k][l-1]+b[i][3]);
                    }
                }
            }
        }
        int num=0;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++){
                int k=n-i-j;
                num=max(num,a[n][i][j][k]);
            }
        }
    	printf("%d\n",num); 
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


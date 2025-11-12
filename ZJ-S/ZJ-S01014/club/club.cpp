#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100055;
int a[N][4],t[N]/*choose*/,u[3]/*use*/,f[3]/*min*/;
int dp[2][N]/*B,1~i,cnt1=j*/,dq[2][233][233]/*1~i,cnt1=j,2=k*/;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		int n,a0=0,ans=0;scanf("%d",&n);
		memset(t,0,sizeof(t));u[1]=u[2]=u[3]=0;f[1]=f[2]=f[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]),f[j]=max(f[j],a[i][j]);
				if(a[i][t[i]]<a[i][j])t[i]=j;
			} u[t[i]]++,a0+=a[i][t[i]];
		}
		if(u[1]<=n/2&&u[2]<=n/2&&u[3]<=n/2)ans=a0;
		else if(f[2]==0&&f[3]==0){ //printf("A ");//A
			for(int i=1;i<=n;i++) dp[0][i]=a[i][1];
			sort(dp[0]+1,dp[0]+n+1);
			for(int i=n/2+1;i<=n;i++) ans+=dp[0][i];
		}else if(f[3]==0){ //printf("B ");//B
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
				for(int j=max(0,i-n/2);j<=min(i,n/2);j++){
					dp[i&1][j]=0;
					if(j!=0)dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j-1]+a[i][1]);
					if(j!=i)dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j]+a[i][2]);
				}
			ans=dp[n&1][n/2];
		}else if(n<=200){
			memset(dq,0,sizeof(dq));
			for(int i=1;i<=n;i++){
				memset(dq[i&1],0,sizeof(dq[i&1]));
				for(int j=0;j<=min(i,n/2);j++)
					for(int k=0;k<=min(i-j,n/2);k++){
						if(i-j-k>n/2)continue;
						if(j!=0)dq[i&1][j][k]=max(dq[i&1][j][k],dq[(i-1)&1][j-1][k]+a[i][1]);
						if(k!=0)dq[i&1][j][k]=max(dq[i&1][j][k],dq[(i-1)&1][j][k-1]+a[i][2]);
						if(i!=j+k)dq[i&1][j][k]=max(dq[i&1][j][k],dq[(i-1)&1][j][k]+a[i][3]);
						if(i==n) ans=max(ans,dq[i&1][j][k]);
					}
			}
		}else{
			/*printf("QwQ ");*/ans=a0;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0 */ /*
30	1-8     DP AC   #1-3
200	9     B DP AC     #4
	10-11 perhaps
1e5	12    A AC
	13-14 B DPTLE?1e10
	15-16 C perhapsAC #5
	17-20 perhaps       =>70pts*/

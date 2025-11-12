#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define int long long

string s;
int anss,T,A,B;
int n,m,c[N],aa[N][N],b[N],ans,mod=998244353;
int dp[205][205][205];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		A=1,B=1;
		memset(dp,0,sizeof(dp));
		anss=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>aa[i][j];
				if(aa[i][2])	A=0;
				if(aa[i][3])	B=0;
			}
		}
		if(A){
			for(int i=1;i<=n;i++){
				b[i]=aa[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--){
				anss+=b[i];
//				cout<<b[i]<<" ";
			}
			cout<<anss<<endl;
			continue ;
		}
//		dp[1][1][1][1]=1;
		for(int i=1;i<=n;i++){
			for(int a=min(i,n/2);a>=0;a--){
				for(int b=min(i-a,n/2);b>=0;b--){
					for(int c=min(n/2,i-a-b);c>=0;c--){
						if(a-1>=0)
							dp[a][b][c]=max(dp[a][b][c],dp[a-1][b][c]+aa[i][1]);
						if(b-1>=0)
							dp[a][b][c]=max(dp[a][b][c],dp[a][b-1][c]+aa[i][2]);
						if(c-1>=0)
							dp[a][b][c]=max(dp[a][b][c],dp[a][b][c-1]+aa[i][3]);
						anss=max(anss,dp[a][b][c]);
					}
				}
			}
		}
		cout<<anss<<endl;
	}
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
4 0 0 
*/
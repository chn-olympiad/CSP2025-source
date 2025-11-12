#include<bits/stdc++.h>
//int main!!!!
//T1 
//任意时刻至多有一个社团满 
using namespace std;
const int N=250;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int T,n;
int a[100005][5];
int f[N];
int a_1[100005];
int dp[2][N][N][N];
void sub1(){
	int ans=0;
	for(int i=1;i<=n;i++)a_1[i]=a[i][1];
	sort(a_1+1,a_1+1+n);
	for(int i=n;i>n/2;i--)ans+=a_1[i];
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n>200){
			sub1();
			continue;
		}
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		int m=n/2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				for(int k=0;j+k<=i;k++){
					int r=i-j-k;
						if((j>m)||(k>m)||(r>m))continue;
						if(j>0)dp[i%2][j][k][r]=max(dp[(i-1)%2][j-1][k][r]+a[i][1],dp[i%2][j][k][r]);
						if(k>0)dp[i%2][j][k][r]=max(dp[(i-1)%2][j][k-1][r]+a[i][2],dp[i%2][j][k][r]);
						if(r>0)dp[i%2][j][k][r]=max(dp[(i-1)%2][j][k][r-1]+a[i][3],dp[i%2][j][k][r]);
						f[i]=max(f[i],dp[i%2][j][k][r]);
						
					}
				}
			}
		cout<<f[n]<<endl;
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

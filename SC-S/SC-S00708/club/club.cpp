#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{
	ll c1,c2,c3;
}a[N];
ll t;
ll n;
ll c[5][N];
ll dp[N][5];
ll num[N][5][5];
bool cmp(node a,node b){
	ll q,w;
	q=max(a.c1,max(a.c2,a.c3));
	w=max(b.c1,max(b.c2,b.c3));
	return q>w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		memset(num,0,sizeof num);
		memset(dp,0,sizeof dp);
		scanf("%lld",&n);
		for(int i=1;i<=n;++i){
			scanf("%lld%lld%lld",&a[i].c1,&a[i].c2,&a[i].c3);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i){
			c[1][i]=a[i].c1;
			c[2][i]=a[i].c2;
			c[3][i]=a[i].c3;
		}
		//for(int i=1;i<=n;++i)	cout<<c[1][i]<<c[2][i]<<c[3][i]<<endl;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				if(dp[i][j]<=dp[i-1][1]+c[j][i]){
					if(num[i-1][1][j]+1<=(n/2)){
						dp[i][j]=dp[i-1][1]+c[j][i];
						num[i][j][1]=num[i-1][1][1];num[i][j][2]=num[i-1][1][2];num[i][j][3]=num[i-1][1][3];
						num[i][j][j]++;
					}
				}
				if(dp[i][j]<=dp[i-1][2]+c[j][i]&&num[i-1][2][j]+1<=(n/2)){
					dp[i][j]=dp[i-1][2]+c[j][i];
					num[i][j][1]=num[i-1][2][1];num[i][j][2]=num[i-1][2][2];num[i][j][3]=num[i-1][2][3];
					num[i][j][j]++;
				}
				if(dp[i][j]<=dp[i-1][3]+c[j][i]&&num[i-1][3][j]+1<=(n/2)){
					dp[i][j]=dp[i-1][3]+c[j][i];
					num[i][j][1]=num[i-1][3][1];num[i][j][2]=num[i-1][3][2];num[i][j][3]=num[i-1][3][3];
					num[i][j][j]++;
				}//else dp[i][j]=

			}
			
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	}
	
	
	fclose(stdin);fclose(stdout);
	return 0;
} 
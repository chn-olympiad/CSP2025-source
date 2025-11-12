#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXx(a,b,c) max(max(a,b),c)
int dp[100005][3][4],t,n;
struct aa{
	int num[3];double fc,sum;
}a[100005];
bool cmp(pair<int,int> A,pair<int,int> B){
	return A.first > B.first;
}
bool cmp2(aa A,aa B){
	if(A.sum == B.sum) return A.fc < B.fc;
	return A.sum > B.sum;  
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].num[0] >> a[i].num[1] >> a[i].num[2];
			a[i].sum = a[i].num[0] + a[i].num[1] + a[i].num[2];
			a[i].fc = 1.0*((a[i].num[0]-1.0*a[i].sum/3)*(a[i].num[0]-1.0*a[i].sum/3)+
						(a[i].num[1]-1.0*a[i].sum/3)*(a[i].num[1]-1.0*a[i].sum/3)+
						(a[i].num[2]-1.0*a[i].sum/3)*(a[i].num[2]-1.0*a[i].sum/3))/3;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i = 1;i <= n;i++){
		for(int j = 0;j <= 2;j++){
				pair<int,int> dpp[3] = {{dp[i-1][0][j+1]+1 <= n/2 ? dp[i-1][0][0] + a[i].num[j] : -1,0},
				    	   				{dp[i-1][1][j+1]+1 <= n/2 ? dp[i-1][1][0] + a[i].num[j] : -1,1},
				    	   				{dp[i-1][2][j+1]+1 <= n/2 ? dp[i-1][2][0] + a[i].num[j] : -1,2}};
				sort(dpp,dpp+3,cmp);
				dp[i][j][0] = dpp[0].first;
				int addd[3] = {0,0,0};
				addd[j] = 1;
				dp[i][j][1] = dp[i-1][dpp[0].second][1]+addd[0];
				dp[i][j][2] = dp[i-1][dpp[0].second][2]+addd[1];
				dp[i][j][3] = dp[i-1][dpp[0].second][3]+addd[2];
			}
		}
		cout << MAXx(dp[n][0][0],dp[n][1][0],dp[n][2][0]) << endl;
	}
	return 0;
} 
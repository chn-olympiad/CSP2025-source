//已消耗一次免費觀看次數!
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int N=1e5+7;
int dp[4][N];
int max_id[N];
int T,n;
priority_queue<int>s[4];

signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
	
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			max_id[i]=0;
			for(int j=1;j<=3;j++){
				cin>>dp[j][i];
				if(dp[j][i]>=dp[max_id[i]][i]){
					max_id[i]=j;
				}
			}
		}
		for(int i=1;i<=n;i++)
			s[max_id[i]].push(dp[max_id[i]][i]);
		
		int sum=0;
		for(int i=1;i<=n/2&&!s[1].empty();i++){
			sum+=s[1].top();s[1].pop();
		}
		for(int i=1;i<=n/2&&!s[2].empty();i++){
			sum+=s[2].top();s[2].pop();
		}
		for(int i=1;i<=n/2&&!s[3].empty();i++){
			sum+=s[3].top();s[3].pop();
		}
		cout<<sum<<'\n';
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
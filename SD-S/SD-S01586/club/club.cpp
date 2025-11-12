#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],t[3],dp[105][105][105];
int bfs(int a)
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios:sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int mx=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=2){
			cout<<max(max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],a[1][2]+a[2][1])),max(max(a[1][2]+a[2][3],a[1][3]+a[2][1]),a[1][3]+a[2][2]));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

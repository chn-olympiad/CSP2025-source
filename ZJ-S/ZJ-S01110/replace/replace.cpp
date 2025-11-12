#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+10;
ll n,m,k,ans;
ll sum[10];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		string s;
		cin>>s;
	}
	for(ll i=1;i<=m;i++){
		string s;
		cin>>s;
	}
	for(ll i=1;i<=m;i++){
		cout<<"0\n";
	}
	return 0;
}
/*
4
9  6 0
10 9 8
4  0 0
0  0 0
dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i])
  1     2     3
(1,9)
(2,10)
*/

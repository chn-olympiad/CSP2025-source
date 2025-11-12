#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int ans;
int p[15][10005];
int jt[5005][5005];
const int MOD=1e9+7;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int s=0;
	for(int i=1;i<=k*n*50;++i){
 		s+=rand()%MOD;
 		s%=MOD;
	}
	int ss=0;
	for(int i=1;i<=n*k+(n+k)*s%30;++i){
		ss+=rand()%MOD;
		ss%=MOD;
	}
	cout<<ss;
	return 0;
}
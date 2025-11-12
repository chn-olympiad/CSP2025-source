#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int s=0;
const int MOD=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n*q*50;++i){
 		s+=rand()%MOD;
 		s%=MOD;
	}
	int ss=0;
	for(int i=1;i<=n*q+(n+q)*s%30;++i){
		ss+=rand()%MOD;
		ss%=MOD;
	}
	cout<<ss;
	return 0;
}
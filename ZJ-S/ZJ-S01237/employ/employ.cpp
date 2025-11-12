#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N =1e6+9, mod=998244353;
string s;
ll n, m, a[N], ss[N], lss = 0, cj=1, place0[N], lpl=0;
ll ton[N];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ss[i] = s[i] - '0';
		lss+=ss[i];
		cj=cj*i%mod;
		if(ss[i]==0){
			place0[lpl] = i;
			lpl++;
		}
		ton[a[i]]++;
	}
	if(lss<m){
		printf("0");
		exit(0);
	}
	printf("%lld", cj);
	return 0;
}

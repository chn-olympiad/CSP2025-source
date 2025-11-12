#include<bits/stdc++.h>
using namespace std;
const int mod=998244353
int n,m;
long long tot;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		tot=tot*i%mod;
	cout<<tot;
	return 0;
}

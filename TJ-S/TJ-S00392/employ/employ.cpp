#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> c(n+5);
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	unsigned long long ans=1;
	for(unsigned long long i=2;i<=n;i++){
		ans=(ans*i)%MOD;
	}
	cout<<ans;
	return 0;
}

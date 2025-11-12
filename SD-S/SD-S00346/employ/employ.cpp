#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=n;i>=1;i--)ans=ans*i%MOD;
	cout<<ans;
	return 0;
}

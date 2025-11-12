#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,a[505],sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='1') sum++;
	}
	if(sum==n){
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans*=n;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	else if(n==m||m>sum){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}

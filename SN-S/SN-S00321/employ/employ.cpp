#include<bits/stdc++.h>
using namespace std;
const long long mod1=998244353
long long n,m,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=n;i>=n-m+1;i--){
		ans*=i;
		ans%=mod1;
	}
	cout<<ans;
	return 0;
}

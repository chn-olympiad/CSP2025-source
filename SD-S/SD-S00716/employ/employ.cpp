#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const long long mod = 998244353;
long long C[700];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long i,j=0,n,m,ans=1,sum,z=0;
	string s;
	cin>>n>>m;
	cin>>s;
	for(i = 1 ; i <= n ; i++){
	    cin>>C[i];
	    if(C[i]==0)z++;
	}
//	ans=(ans*z)%mod;j++;
	for(i = n-z ; i >= 1 ; i--){
		j++;
		cout<<ans<<" "<<i<<endl;
		ans = (ans * i) % mod;
		if(j==m) break;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}


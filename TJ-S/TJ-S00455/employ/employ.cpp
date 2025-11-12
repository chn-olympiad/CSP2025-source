#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		ans*=i;
		ans=ans%998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

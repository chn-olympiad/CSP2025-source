#include<bits/stdc++.h>
unsigned long long ans=1;
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
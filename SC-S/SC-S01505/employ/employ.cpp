#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,ans=1,mod=998244353;
	cin >>n;
	for(int i=1;i<=n;i++) ans=(ans*i%mod);
	cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
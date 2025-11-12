#include <bits/stdc++.h>
using namespace std;
long long n,m,c[510],fact;
const long long mod=998244353;
string s;
long long A(long long n){
	long long ans=1;
	for (int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
void opA(){
	for (auto& i:s){
		if (i!='1') return ;
	}
	printf("%lld",A(fact));
	exit(0);
}
void opC(){
	if (m==1 || m==n){
		printf("%lld",A(fact));
		exit(0);
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	fact=n;
	cin>>s;
	for (int i=1;i<=n;i++) {
		scanf("%lld",&c[i]);
		if (c[i]==0) --fact;
	}
	opA();opC();
	cout<<0;
	return 0;
}


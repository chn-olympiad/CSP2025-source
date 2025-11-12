#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m;
char s[505];
long long c[505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int nb=n;
	bool ji=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')ji=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)nb--;
	}
	if(ji==1){
		long long ans=1;
		for(int i=0;i<nb;i++){
			ans=((ans%mod)*(nb-i))%mod;
		}
		cout<<ans;
	}
	return 0;
}

//by snakeMC
//now:PAC 0pts  tp a ~20pts
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long C(long long n,long long m){
	if(m>n/2)return C(n,n-m);
	long double ans=1;
	for(int i=0;i<m;i++){
		ans=ans*(long double)(n-i)/(m-i);
		long long t=ans/mod;
		ans=ans-t*mod;
	}
	return (long long)ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool flag=true;
	for(long long i=0;i<n;i++){
		if(s[i]!='1'){
			flag=false;
			break;
		}
	}
	if(m==1&&!flag){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
	}
	if(flag){
		cout<<C(n,m);
	}else cout<<rand();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

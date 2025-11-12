#include<iostream>
using namespace std;
int test[501],person[501];
const long long mod=998244353;
long long stage(long long d){
	long long tmp=1;
	for(int i=d;i>1;i--){
		tmp*=i;
		tmp%=mod;
	}
	return tmp;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		char t;
		cin>>t;
		test[i]=t-'0';
		cnt+=test[i];
	}
	for(int i=1;i<=n;i++){
		cin>>person[i];
	}
	if(cnt==n){
		cout<<stage(n);
		return 0;
	}
	
}

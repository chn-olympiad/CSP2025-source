#include<bits/stdc++.h>
using namespace std;
long long jc(int x){
	long long ans=1;
	for(long long i=1;i<=x;i++){
		ans=(ans%998244353)*(i%998244353)%998244353;
	}
	return ans;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	string s;
	cin>>s;
	long long ans=1;
	int x=1;
	int cnt=1;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==0) cnt++;
	}
	cout<<jc(n)%998244353;
	return 0;
}


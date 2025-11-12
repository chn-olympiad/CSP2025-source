#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long ans=1;
	if(n==m){
		for(long long i=n;i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	string s;
	cin>>s;
	int k=n;
	int ne=0;
	for(int i=1;i<=k;i++){
		int t;
		cin>>t;
		if(t==0) {
			n--;
			ne++;
		}
	}
	
	for(long long i=n;i>=1;i--){
		ans*=i;
		ans%=998244353;
	}
	for(long long i=1;i<=ne;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
} 

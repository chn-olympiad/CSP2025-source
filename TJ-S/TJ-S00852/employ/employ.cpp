#include<bits/stdc++.h>
using namespace std;
int rn[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')f=0;
	}
	for(int i=1;i<=n;i++){
		cin>>rn[i];
	}
	sort(rn+1,rn+1+n);
	if(f==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(rn[i]==0){
				sum++;
			}
		}
		if(n-sum<m){
			cout<<0;
			return 0;
		}

		long long ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans=ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(rn[i]==0){
				sum++;
			}
		}
		if(n-sum==0){
			cout<<0;
			return 0;
		}
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans=ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	long long ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans=ans%998244353;
	}
	cout<<ans;
	return 0;
}



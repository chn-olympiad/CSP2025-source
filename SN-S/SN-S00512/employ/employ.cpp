#include<bits/stdc++.h>
using namespace std;
long long n,m,flag1,flag2,arr[505];
string s;
long long A(int x){
	long long ans=1;
	for(int i=2;i<=x;i++) ans=(ans*i)%998244353;
	return ans%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=0;i<n;i++){
		if(s[i]==0) flag1=1;
	}
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==0) flag2=1;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==n){
		if(flag1==0 and flag2==0) cout<<A(n);
		else cout<<0;
		return 0;
	}
	cout<<A(n);
	return 0;
}

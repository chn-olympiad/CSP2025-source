#include<bits/stdc++.h>
using namespace std;
int n,m,a[600];
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool t=1;
	long long n1=n;
	while(n1>0){
		ans=ans*n1%10;
		n1--;
	}
	for(int i=1;i<=n;i++){
		ans=ans*ans%998244353;
	}
	if(t){
		cout<<ans;
	}
	return 0;
} 

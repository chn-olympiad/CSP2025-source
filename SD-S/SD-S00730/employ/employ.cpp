#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int m,n;
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin.ignore();
	string s;
	getline(cin,s); 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	long long ans=1;
	for(int i=1;i<=m;i++){
		ans=ans*i;
	} 
	n=n-m;
	for(int i=1;i<=n;i++){
		ans=ans/i;
	} 
	cout<<ans%998244353;
	
	
	
	return 0;
}

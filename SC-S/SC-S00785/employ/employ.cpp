#include<bits/stdc++.h>
using namespace std;
int n,m,l;
long long ans=1;
string s;
int a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=0)a[++l]=x;
	}
	if(l<m){
		cout<<0;
	}else if(l==m){
		cout<<1;
	}
	for(int i=1;i<=l;i++){
		ans=((ans%998244353)*(a[i]%998244353))%998244353;
	}
	cout<<ans%998244353;
	return 0;
}
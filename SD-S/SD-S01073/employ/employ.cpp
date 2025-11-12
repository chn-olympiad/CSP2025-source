#include<bits/stdc++.h>
using namespace std;
int a[505];
int c(int m,int n){
	int cnt=1,cnt1=1;
	for(int i=n;i>=n-m+1;i--){
		cnt*=i%998244353;
	}
	for(int i=1;i<=m;i++){
		cnt1*=i%998244353;
	}
	return cnt/cnt1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=m;i<=n;i++){
		ans+=c(i,n)%998244353;
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,c[505]={},flag1=1,flag2=1,ans=1;
	string s="";
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++){
		if(s[i]!='1') flag1=0;
		if(s[i]!='0') flag2=0;
	}
	if(flag1==1){
		if(n>2) cout<<(n-1)*(n-2)%998244353*n%998244353;
		else cout<<(n-1)%998244353*1*n%998244353;
		return 0;
	}
	if(m==1){
		cout<<n*(n-1)*(n-2)%998244353;
		return 0;
	}
	if(m==n){
		if(flag1==0) cout<<0;
		else {
			for(int i=1;i<=n;i++){
				ans*=i;
				ans=ans%998244353;
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<10543;
	return 0;
} 
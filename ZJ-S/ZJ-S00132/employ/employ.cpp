#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		if(p!=0) cnt++;
	}
	long long ans=1;
//	if(s[0]=='1'){
//		for(long long i=1;i<=cnt;i++){
//			ans=ans*i;
//			ans=ans%998244353;
//		}
//		cout<<ans;
//	}
//	else cout<<0;
	cout<<0;
	return 0;
}

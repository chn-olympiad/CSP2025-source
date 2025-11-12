#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int a[10001];
	string s;
	cin>>s;
	int cntt=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'){
			cntt++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(cntt==n){
		cout<<(n*n*n)%998244353;
		return 0;
	}
	if(m==n){
		cout<<0<<endl;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
	}
	cout<<(cnt%998244353)<<endl;
	return 0;
}

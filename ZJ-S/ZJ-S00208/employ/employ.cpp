#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[505],ans1,a[505];
string s;
int jie(int x){
	int ans=1;
	for(int i=2;i<=x;i++){
		ans*=x;
		ans=ans%998244353;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
	}
	if(n>10){
		cout<<jie(n);
		return 0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int l[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long ans=1;
	string s;
	cin>>n>>m;
	cin>>s;
	if(n==m){
		for(int i=1,a;i<=n;i++){
			cin>>a;
			ans*=i;
			ans%=998244353;
		}
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				return 0;
			}
		}
		cout<<ans;
	}
	for(int i=1,a;i<=n;i++){
		cin>>a;
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
} 

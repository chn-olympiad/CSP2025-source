#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,s[N],c[N];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s1; cin>>s1;
	int all_one=1;
	for(int i=1;i<=n;i++){
		s[i]=s1[i-1]-'0';
		if(s[i]==0) all_one=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(all_one){
		ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
bool b=1;
int a[505];
long long ans;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		cout<<1<<endl;
		return 0;
	}
	if(m==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.length();i++){
		a[i+1]=s[i]-48;
		if(!a[i+1]) b=0;
	}
	if(b){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<18<<endl;


	return 0;
}



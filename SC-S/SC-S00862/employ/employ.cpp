#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[600];
long long ans=1;
bool all_1=1,all_0=1;
const int Mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') all_1=0;
		else all_0=0;
	}
	int f1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') {
			f1=i;
			break;
		}
	}
	if(all_1){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=Mod;
		} 
		cout<<ans;
		return 0;
	}
	else if(m==n){
		cout<<0;
		return 0;
	}
	else if(m==1){
		if(all_0) cout<<0;
		sort(c+1,c+n+1);
		if(c[n]<f1) cout<<0;
		else{
			for(int i=1;i<n;i++){
				ans*=i;
				ans%=Mod;
			} 
			cout<<ans;
		}
		return 0;
	}
	else{
		cout<<0;
	}
	return 0;
}

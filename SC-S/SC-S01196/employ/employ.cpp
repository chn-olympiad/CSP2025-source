#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	int n,m,a;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
		cin>>a;
	bool f=true;
	for(int i=0;i<n;i++){
		if(s[i]=='0')
			f=false;
	}
	long long ans=1;
	if(f){
		if(m==n){
			for(int i=n;i>=1;i--){
				ans*=i;
				ans%=MOD;
			}
			cout<<ans;
		}
		else
			cout<<0;
	}
	else if(m==1){
		cout<<1;
	}
	return 0;
}
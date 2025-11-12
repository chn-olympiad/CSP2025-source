#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0,a[200005],c=0;
	long long ans=1;
	cin>>n>>m;
	string s;
	bool f=1;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			f=0;
		}
		else {
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) c++;
	}
	if(f=1){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	if(m==n){
		if(f==0){
			cout<<"0";
		}
		else{
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
		}
		return 0;
	}
	if(cnt<m){
		cout<<"0";
	}
	return 0;
} 

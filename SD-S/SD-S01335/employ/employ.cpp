#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,m,c[505];
string s;
int f;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			f++;
		}
	}
	if(m==n){
		if(f!=0){
			cout<<0;
			return 0;
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%MOD;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		if(f==n){
			cout<<0;
			return 0;
		}
		int minn=505;
		int cnt=0;
		int ans=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				minn=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]>=minn){
				cnt++;
			}
		}
		for(int i=1;i<n-1;i++){
			ans=ans*i%MOD;
		} 
		cout<<ans*cnt%MOD;
		return 0;
	} 
	if(f==0){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%MOD;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
} 


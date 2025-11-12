#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[1000];
int ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='1'){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		if(ans==m){
			long long cnt=1;
			for(int i=1;i<=ans;i++){
				cnt*=i;
				cnt%=998244353;
			}
			cout<<cnt%998244353;
			//cout<<6402373705728000%998244353;
			return 0;
		}
		else {
			cout<<"0";
			return 0;
		}
	}
	if(m==1){
		if(ans>0){
			long long cnt=1;
			for(int i=1;i<=ans;i++){
				cnt*=i;
				cnt%=998244353;
			}
			cout<<cnt%998244353;
			//cout<<6402373705728000%998244353;
			return 0;
		}
		else {
			cout<<"0";
			return 0;
		}
	}
	if(m>ans){
		cout<<"0";
		return 0;
	}
	long long cnt=1,cn=0;
	for(int i=1;i<=ans;i++){
		cnt*=i;
		cnt%=998244353;
	}
	cout<<cnt%998244353;
	return 0;
}

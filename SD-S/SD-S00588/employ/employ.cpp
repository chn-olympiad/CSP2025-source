#include<bits/stdc++.h>
using namespace std;
long long n,m,b[1005],cnt;
string a;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];if(!b[i])cnt++;
	} 
	if(m==n){
		if(cnt){
			cout<<0;return 0;
		}
		for(int i=0;i<a.size();i++){
			if(a[i]!='1'){
				cout<<0;return 0;
			}
			
		}
		long long ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	}
	
	long long ans=1;
	if(n-cnt<m){
		cout<<0;return 0;
	}
	for(int i=2;i<=n-cnt;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}

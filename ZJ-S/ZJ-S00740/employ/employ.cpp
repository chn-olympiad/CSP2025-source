#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=510;
int n,m;
string s;
int c[N],a[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n==m){
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(c+1,c+n+1);
	if(c[1]>=n){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=n;i>=1;i--){
		a[i]=rand()%(n-i+1)+1;
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*a[i])%mod;
	}
	cout<<ans;
	return 0;
}

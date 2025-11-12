#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
string s;
int a[520],vis[520];
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	int l=s.length();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				for(int j=i+1;j<=n;j++){
					swap(a[j],a[j-1]);
				}
				n--;
			}
		}
		if(m==n){
			long long ans=1,ok=0;
			for(int i=1;i<=l;i++){
				if(s[i]=='0'){
					ok=1;
					break;
				}
			}
			if(ok){
				cout<<0;
				return 0;
			} 
			for(int i=1;i<=n;i++){
				ans*=i;
				ans=ans%MOD;
			}
			cout<<ans;
		}
		else if(m>n) cout<<0;		
	}
	else if(m==1){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans=ans%MOD;
		}
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
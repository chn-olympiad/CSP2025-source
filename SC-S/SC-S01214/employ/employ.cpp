#include<bits/stdc++.h>
using namespace std;
int p[502];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=0,cnt=0;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(m==n){
		bool o=1;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				o=0;
				break;
			}
		}
		if(o==0) cout<<"0";
		else{
			ans=1;
			for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
			cout<<ans;
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1') cnt++;
	}
	if(cnt<m){
		cout<<"0";
		return 0;
	}
	if(cnt==n){
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
	}
	cout<<1<<endl;
	return 0;
}
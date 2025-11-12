#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long long n,m,ans=1,cnt=0;
string s;
long long c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0') cnt++;
		if(cnt==s.size()){
			cout<<0;
			return 0;
		}
	}
	if(m==n){
		if(cnt!=0) cout<<0;
		for(int i=1;i<=n;i++){
			if(c[i]==c[i+1]) cout<<0;
			else cout<<1;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=ans*i;
			ans=ans%998244353;
		}
	}
	cout<<ans;
	return 0;
}

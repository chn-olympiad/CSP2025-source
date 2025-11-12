#include <iostream>
#include <algorithm>
using namespace std;
int n,m,cnt=0,t=0;
string s;
int a[505],sa[505];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			a[i]=i-t;
			t=i+1;
			cnt++;
		}
	}
	if(cnt==n){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010;
const int P=998244353;
int n,m;
string s; 
int a[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f0=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==1) f0=1;
	}
	if(f0==0){
		int ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%P;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}

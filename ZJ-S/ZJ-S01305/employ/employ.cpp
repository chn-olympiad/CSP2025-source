#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<int> c(n+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	int asn=n;
	for(int i=1;i<=n;i++) asn-=(c[i]==0);
	if(asn<m){
		cout<<0;
		return 0;
	}
	else{
		long long ans=1;
		for(int i=0;i<m;i++){
			ans=ans*(asn-i)%P;
		}
		cout<<ans;
	}
	return 0;
}

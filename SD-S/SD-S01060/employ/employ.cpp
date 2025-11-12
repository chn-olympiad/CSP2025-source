#include <bits/stdc++.h>
using namespace std;
const int mod=998244353; 
int n,m; 
int fail;
int p[100010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int flag=1;
	for(int i=0;i<n;i++){
		if(s[i]==0) flag=0,fail++;
	}
	int nn=n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]==0) nn--; 
	} 
	if(fail>(nn-m)) {
		cout<<"0";
		return 0;
	}
	if(flag){
		long long ans=1;
		for(int i=1;i<=nn;i++){
			ans=ans*i%mod;
		}
		printf("%lld\n",ans);
		return 0;
	}
}

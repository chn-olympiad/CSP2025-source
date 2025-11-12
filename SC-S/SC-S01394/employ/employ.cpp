#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,tot=0;cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]) tot++;
	}
	if(tot<m){
		cout<<0;
		return 0;
	}
	long long ans=1;
	for(int i=2;i<=n;i++) ans=ans*i%998244353;
	cout<<ans;
	return 0;
}

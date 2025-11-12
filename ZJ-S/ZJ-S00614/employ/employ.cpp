#include<bits/stdc++.h>
using namespace std;
int n,m,a[506],o;
string s;
long long ans=1;
int main(){
	cin.tie();
	cout.tie();
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}

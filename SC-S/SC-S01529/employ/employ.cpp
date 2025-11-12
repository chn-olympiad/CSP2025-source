#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005];
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)k++;
		ans=(ans*i)%998244353;
	}
	if(k>n){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
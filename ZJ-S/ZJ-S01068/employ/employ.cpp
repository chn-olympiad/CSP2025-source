#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
bool f;
long long x,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		if(s[i]!='1')f=1;
	}
	if(!f){
		for(int i=m;i<=n;i++){
			x=1;
			for(int j=n;j>=n-m+1;j--)x=(x*j)%998244353;
			ans=(ans+x)%998244353;
		}
		cout<<ans;
	}
	else cout<<0;
}

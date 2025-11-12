#include<bits/stdc++.h>
using namespace std;
//能骗到吗 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n+1];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int ans=1;
	for(int i=m;i<=n;i++)
		ans=(ans*i)%998244353;
	cout<<ans;
	return 0;
}
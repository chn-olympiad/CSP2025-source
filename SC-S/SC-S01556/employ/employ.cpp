#include <bits/stdc++.h>
using namespace std;
int c[510],n,m,ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	froepen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i]; 
	for(int i=n;i>=n-m+1;i--)ans=ans*i%998244353;
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N];
long long ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	int flag=1;
	for(int i=0;i<n;i++)
		if(s[i]=='0')flag=0;
	for(int i=1;i<=n;i++)
		if(a[i]==0)flag=0;
	if(flag==0&&m==n)
		return cout<<0,0;
	if(flag==1){
		ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*i)%mod;
		cout<<ans;
	}
	return 0;
}
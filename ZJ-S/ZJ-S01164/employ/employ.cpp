#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,sum,a[510],x;
string s;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		cout<<0;
		return 0;
	}
	else{
		for(int i=0;i<s.size();i++)
			if(s[i]=='0') sum++;
		sort(a+1,a+1+n);
		ans=1;x=1;
		for(int i=sum+1;i<=n;i++)
			ans=ans*x,ans%=mod,x++;
		x=1;
		for(int i=1;i<=sum;i++)
			ans=ans*x,ans%=mod,x++;
		cout<<ans;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0,t=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]<=t||s[i]=='0')t++;
		else cnt++;
	}
	if(cnt<m)cout<<0;
	else {
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}cout<<ans;
	}
	return 0;
}
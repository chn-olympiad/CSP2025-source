#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m;
string s;
int c[505];
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int ls=s.size();
	s=" "+s;
	int cnt=0;
	for (int i=1; i<=n; i++){
		cin>>c[i];
		if (c[i]!=0) cnt++;
	}
	if (cnt<m){
		cout<<0;
		return 0;
	}
	if (m==1&&cnt){
		ll sum=1;
		for (int i=1; i<=n; i++){
			(sum*=i)%=mod;
		}
		cout<<sum;
		return 0;
	}
	int flag=0;
	for (int i=1; i<=n; i++){
		if (s[i]=='1') flag=1;
	}
	if (!flag){
		cout<<0;
		return 0;
	}
	if (n==m){
		ll sum=1;
		for (int i=1; i<=cnt; i++){
			(sum*=i)%=mod;
		}
		cout<<sum;
		return 0;
	}
	int flag=0;
	for (int i=1; i<=ls; i++){
		if (s[i]=='0') flag=1;
	}
	if (!flag){
		ll sum=1;
		for (int i=1; i<=cnt; i++){
			(sum*=i)%=mod;
		}
		cout<<sum;
		return 0;
	}
	cout<<0;
	return 0;
}


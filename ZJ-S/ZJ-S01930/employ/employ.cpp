#include<bits/stdc++.h>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N=505;
const ll mod=998244353;
int n,m,a[N],b[N];
bool chek(string s){
	for(int i=1;i<s.size();i++)if(s[i]=='0')return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	s=" "+s+"#";
	for(int i=1;i<=n;i++)cin>>a[i];
	if(chek(s)){
		ll ans=1;
		int cnt=0;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
			if(a[i])cnt++;
		}
		if(cnt>=m)cout<<ans;
		else cout<<0;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	int L=1;
	while(s[L]=='0')L++;
	if(s[L]=='0'){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1;i<=n;i++)b[i]=i;
	do{
		int cnt=0,num=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=a[b[i]])cnt++;
			else num++;
		}
		if(num>=m)ans=(ans+1)%mod;
	}while(next_permutation(b+1,b+1+n));
	cout<<ans;
	return 0;
}

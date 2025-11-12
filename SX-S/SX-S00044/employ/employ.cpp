#include<bits/stdc++.h>
#define ll long long
#define fi fisrt
#define se second
//recall.cpp
//#define ll bong bong

using namespace std;
const ll N=100005;
const ll inf=1e18;
const ll mod=998244353;
ll n,m,c[N],pi[N];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m>>s;
	s=" "+s;
	ll k=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		k+=(s[i]=='1');
	}
	sort(c+1,c+n+1);
	if(k<m){
		cout<<"0\n";
		return 0;
	}	
	if(n<=10){
		ll res=0;
		for(int i=1;i<=n;i++)pi[i]=i;
		do{
			ll cnt=0,q=0;
			for(int i=1;i<=n;i++){
				if(c[pi[i]]<=q||s[i]=='0'){
					q++;
					continue;
				}cnt++;
				if(n-i+cnt<m)break;
				if(cnt>=m)break;
			}	
			if(cnt>=m)res=(res+1)%mod;
		}while(next_permutation(pi+1,pi+n+1));
		cout<<res<<endl;
		return 0;
	}
	if(m==n){
		if(c[1]==0){
			cout<<"0\n";
			return 0;
		}
		ll res=1;
		for(int i=1;i<=n;i++)res=res*i%mod;
		cout<<res<<endl;
	}
	cout<<0<<endl;
	return 0;
}
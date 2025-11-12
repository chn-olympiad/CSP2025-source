#include<iostream>
#include<cstdio>
#include<string>
#define debug
using namespace std;
const int N=5e2+1e1;
const int p=998244353;
int n,m;
string s;
int c[N];

void A();
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int cnt=0;
	for(int i=1;i<=n;++i)
		cin>>c[i];
	for(int i=0;i<s.size();++i)
		if(s[i]=='1') ++cnt;
	if(cnt<m){
		cout<<0<<'\n';
		return 0;
	}
	int spa=1;
	for(int i=0;i<s.size();++i){
		if(s[i]!='1'){
			spa=0;
			break;
		} 
	}
	if(spa){
		A();
		return 0;
	}
	if(m==n){
		int x=1;
		for(int i=0;i<s.size();++i)
			if(s[i]=='0') x=0;
		for(int i=1;i<=n;++i)
			if(c[i]==0) x=0;
		if(x==0) cout<<0<<'\n';
		else A();
		return 0;
	}
	return 0;
} 
void A(){
	int x=0;
	for(int i=1;i<=n;++i)
		if(c[i]==0) ++x;
	n-=x;
	if(n<m){
		cout<<0<<'\n';
		return;
	}
	long long ans=1ll;
	for(long long i=n;i>=1;--i)
		ans=(ans*i)%p;
	cout<<ans<<'\n';
	return;
}

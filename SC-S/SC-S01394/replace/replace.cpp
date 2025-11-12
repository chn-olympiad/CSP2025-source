#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7,mod=998244353,N=2e5+5;
int n,m;
struct node{
	long long x,y,len;
}a[N];
long long hsh(string s){
	long long res=0;
	for(int i=0;i<s.size();i++){
		res=res*M+1ll*(s[i]-'a'+1)%mod;
		res%=mod;
	}
	return res;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		a[i]={hsh(s),hsh(t),s.size()};
	}
	for(int i=1;i<=m;i++){
		long long ans=0;
		string s,t;cin>>s>>t;
		int ax=hsh(s),bx=hsh(t);
		int len1=s.size();
		for(int j=1;j<=n;j++){
			long long pw=1;
			for(int k=1;k<=len1-a[j].len+1;k++){
				int f1=a[j].x*pw%mod;
				int f2=a[j].y*pw%mod;
				int xx=ax-f1+f2;
				if(xx==bx) ans++;
				pw=pw*M%mod;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

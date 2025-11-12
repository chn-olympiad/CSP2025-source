#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5,mod=998244353;

int n,m,c[maxn],fk[maxn];
char s[maxn];


signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	
	bool flg=0;
	for(int i=1;i<=n;i++){
		fk[i]=s[i]-'0';
		if(fk[i]==0)flg=1;
		cin>>c[i];
	}
	
	if(!flg){
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<mod;
		return 0;
	}
	cout<<0;
	
	
	
	
	return 0;
}

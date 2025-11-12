#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ans=1,m,dp[514][514],c[514];
string s;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();cin>>s;
	if(m!=n){
		for(int i=1;i<=n;i++)ans*=i,ans%=mod;
		cout<<ans;return 0;
	}
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=0;i<n;i++){
		if(s[i]==0||c[i+1]==0){
			cout<<0;return 0;
		}
	}
	for(int i=1;i<=n;i++)ans*=i,ans%=mod;
	cout<<ans;
	return 0;
}

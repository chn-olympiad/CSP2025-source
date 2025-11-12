#include<bits/stdc++.h>
using namespace std;
long long read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
long long n,k,x[500001],dp[500001],answer,mp[4000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	memset(mp,-1,sizeof(mp));
	mp[0]=0;
	for(int i=1;i<=n;i++){
		x[i]=(x[i-1]^read());
		dp[i]=dp[i-1];
		if(mp[x[i]^k]!=-1) dp[i]=max(dp[i],dp[mp[x[i]^k]]+1);
		mp[x[i]]=i;
	}
	cout<<dp[n];
	return 0;
}

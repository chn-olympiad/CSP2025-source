#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define int long long
using namespace std;
const int mod=998244353;
int n,k,a[11451],b[11451],c[11451],ans;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	b[a[1]]=1;
	for(int i=3;i<=n;i++){
		for(int j=5001+a[i-1];j>=a[i-1];j--){
			c[min(5001,j)]+=c[j-a[i-1]];
			if(c[min(5001,j)]>mod)c[min(5001,j)]-=mod;
		}
		for(int j=1;j<=5000;j++){
			c[min(5001,j+a[i-1])]+=b[j];
			if(c[min(5001,j+a[i-1])]>mod)c[min(5001,j+a[i-1])]-=mod;
		}
		for(int j=a[i]+1;j<=5001;j++){
			ans+=c[j];
			if(ans>mod)ans-=mod;
		}
		b[a[i-1]]++;
	}
	cout<<ans%mod;
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
const int TT=998244353;
int n,a[maxn],ans;
int c[50005];
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	c[0]++;c[a[1]]++;c[a[2]]++;c[a[1]+a[2]]++;
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=50000;j++)ans=(ans+c[j])%TT;
		for(int j=50000;j>=0;j--){if(c[j])c[j+a[i]]=(c[j+a[i]]+c[j])%TT;}
	}
	printf("%lld\n",ans%TT);
	return 0;
}
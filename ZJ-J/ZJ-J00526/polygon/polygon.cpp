#include<bits/stdc++.h>
using namespace std;
const int TT=998244353;
int n,max_x;
long long a[5005],sum[5005],ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),max_x=max(max_x,(int)a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
		if(sum[j-1]-sum[i-1]>sum[j]-sum[j-1]&&j-i>=2)ans=(ans+1)%TT;
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=500005;
LL n,k,a[maxn],sum[maxn],nxt,ans;
bool f[maxn];
LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(LL i=1;i<=n;i++){
		a[i]=read();
		sum[i]=sum[i-1]^a[i];
	}
	for(LL L=0;L<=n;L++){
		for(int i=1;i+L<=n;i=nxt){
			nxt=i+1;
			int x=sum[i+L]^sum[i-1];
//			printf("%d %d %d\n",i,i+L,x);
			if(x==k){
				bool flg=0;
				for(int j=i;j<=i+L;j++)
					if(f[j]){flg=1;break;}
				if(!flg){
					ans++;
					for(int j=i;j<=i+L;j++)f[j]=1;
					nxt=i+L+1;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
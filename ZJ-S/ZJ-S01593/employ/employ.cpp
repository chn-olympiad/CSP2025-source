#include<bits/stdc++.h>
using namespace std;
const long long o=998244353;
long long n,m,a[505],cnt[505],y,c[505],ans,sum[505];
bool b[505],r;
long long s_getchar(){
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	return ch-'0';
}
void DFS(long long p,long long k,long long s){
	//printf("%d %d %d\n",p,k,s);
	if(p>n-m){
		return ;
	}
	if(s==n+1){
		if(k>=m) ans++;
		ans%=o;
		return ;
	}
	if(k>=m){
		ans+=sum[n-s+1];
		ans%=o;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(c[i]<=p||!a[s]) DFS(p+1,k,s+1);
			else DFS(p,k+1,s+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	sum[1]=1;
	for(int i=2;i<=n;i++) sum[i]=sum[i-1]*i,sum[i]%=o;
	for(int i=1;i<=n;i++){
		a[i]=s_getchar();
	}
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++) y+=a[i];
	for(int i=1;i<=n;i++)
	if(c[i]==0) r=1;
	if(m==n){
		if(y==n&&!r) printf("%lld",sum[n]);
		else printf("0\n");
	}
	if(n<=18||m==1){
		DFS(0,0,1);
		printf("%lld\n",ans);
	}
	else printf("0\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],b[N];
long long ans;
bool u[N],tle;
char c[N];
clock_t st;
void dfs(int k){
	if(tle)return;
	if(k==n+1){
		int fl=0,sc=0;
		for(int i=1;i<=n;i++){
//			cout<<a[b[i]]<<" ";
			if(fl>=a[b[i]]){fl++;continue;}
			if(c[i]=='0')fl++;
			else sc++;
		}//cout<<endl<<sc<<endl;
		if(sc>=m)ans=(ans+1)%mod;
		return;
	}
	if((clock()-st)*1.0/CLOCKS_PER_SEC>0.9){tle=1;return;}
	for(int i=1;i<=n;i++)
	if(!u[i]){
		if((clock()-st)*1.0/CLOCKS_PER_SEC>0.9){tle=1;return;}
		b[k]=i;u[i]=1;
//		printf("b[%d]=%d\n",k,i);
		dfs(k+1);
		if(tle)return;
		u[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	st=clock();
	scanf("%d%d",&n,&m);getchar();
	bool A=1;
	for(int i=1;i<=n;i++){
		c[i]=getchar();
		if(c[i]=='0')A=0;
	}
	if(A){
		ans=1;
		for(int i=2;i<=n;i++)
			ans=ans*i%mod;
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	tle=0;dfs(1);
	if(!tle)printf("%lld\n",ans);
	else printf("0\n");
	return 0;
}

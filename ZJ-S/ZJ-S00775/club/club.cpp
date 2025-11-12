#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+20;
long long read(){
	long long ret=0,f=1;char ch=getchar();
	while('0'>ch||ch>'9')f=(ch=='-')?-f:f,ch=getchar();
	while('0'<=ch&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
long long n,t,ans;
struct note{
	long long a[4];
	long long mal,ll,mil;
	bool operator <(const note &x)const{return (a[mal]-a[ll])>(x.a[x.mal]-x.a[x.ll]);}
}num[maxn];
long long m[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T=read();
	while(T--){
		memset(m,0,sizeof m);
		n=read();
		ans=0;
		for(long long i=1;i<=n;i++){
			num[i].a[1]=read();
			num[i].a[2]=read();
			num[i].a[3]=read();
			long long mx=0,mi=0,li=0;
			mx=max(num[i].a[1],max(num[i].a[2],num[i].a[3]));
			mi=min(num[i].a[1],min(num[i].a[2],num[i].a[3]));
			li=num[i].a[1]+num[i].a[2]+num[i].a[3]-mx-mi;
			for(long long j=1;j<=3;j++){
				if(num[i].a[j]==mx)num[i].mal=j;
				if(num[i].a[j]==li)num[i].ll=j;
				if(num[i].a[j]==mi)num[i].mil=j;
			}
		}
		sort(num+1,num+1+n);
		for(long long i=1;i<=n;i++){
			if(m[num[i].mal]>=(n/2)){
				m[num[i].ll]++;
				ans+=num[i].a[num[i].ll];
			}
			else{
				m[num[i].mal]++;
				ans+=num[i].a[num[i].mal];
			}
		}
		printf("%lld\n",ans);
	}
}

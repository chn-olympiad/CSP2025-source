#include<bits/stdc++.h>
using namespace std;
const int k=998244353;
int n,a[5005],ans,d;
inline int read(){
	int ret(0),f(1);char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void f(int x,long long y,int z){
	if(x>n) return;
	if(z>=2&&a[x]<y) ans++,ans%=k;
	f(x+1,y,z);
	f(x+1,y+a[x],z+1);
}
inline int C(int N,int I){
	int num=1;
	for(int i=I+1;i<=N;++i) num*=i,num%=k;
	for(int i=2;i<=N-I;++i) num/=i;
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){a[i]=read();if(a[i]!=1)d=1;}
	if(d==0){
		for(int i=3;i<=n;++i) ans+=C(n,i)%k,ans%=k;
		printf("%d\n",ans);
		return 0;
	}
	sort(a+1,a+1+n);
	f(1,0,0);
	printf("%d\n",ans);
	return 0;
}
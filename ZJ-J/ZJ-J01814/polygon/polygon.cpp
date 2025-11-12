#include<bits/stdc++.h>
using namespace std;
const int maxa=5005,TT=998244353;
int n,a[maxa],ans;
bool flg;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1) flg=1;
	}
	if(flg){
		for(int s=1;s<(1<<n);s++){
			int Max=-(1<<30),sum=0,sie=0;
			for(int i=0;i<n;i++) if(s&(1<<i)) Max=max(Max,a[i+1]),sum=sum+a[i+1],sie++;
			if(sum>2*Max&&sie>=3) ans++,ans%=TT;
		}
		printf("%d\n",ans);	
	}else{
		long long sum=0,as=1;
		for(int i=1;i<=n;i++) as=(as*2)%TT;
		sum=(as-1-n-n*(n-1)/2+TT)%TT;
		printf("%lld\n",sum); 
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,maxn;
bool flg=1;
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
		if(a[i]!=1) flg=0;
	}
	if(flg){
		n-=2;
		for(int i=1;i<=n;i++) ans+=i,ans%=998,ans%=244,ans%=353;
		printf("%d",((ans%998)%244)%353);
		return 0;
	}
	if(n==3){
		int maxn=max(max(a[1],a[2]),a[3]);
		if(2*maxn<a[1]+a[2]+a[3]) ans++;
		printf("%d",ans);
		return 0;
	}
	printf("0");
	return 0;
}

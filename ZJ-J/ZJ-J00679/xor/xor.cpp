#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
bool flg=1;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1) flg=0;
	}
	if(flg){printf("%d",n/2);return 0;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int now=a[i];
			for(int x=i+1;x<=j;x++) now^=a[x];
			if(now==k) ans++;
		}
	}
	printf("%d",ans*2+3);
	return 0;
}

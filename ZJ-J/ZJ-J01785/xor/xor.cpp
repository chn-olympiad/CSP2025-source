#include <bits/stdc++.h>
using namespace std;
int n,a[500010],f=1,k;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1) f=0;
	}
	if(f){
		if(!k) printf("%d",n/2);
		else printf("%d",n);
	}
	else{
		int ans=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]) ans++;
			}
			printf("%d",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				if(!a[i]) ans++;
				else if(a[i]&&a[i+1]) ans++,i++;
			}
			printf("%d",ans);
		}
	}
}

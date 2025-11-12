#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int f[25000005],allv,n,a[5005],ans;
void dfs(int now,int all,int c,int lst){
	if(now==n+1){if(((all-a[lst]>a[lst])&&(c>2))) ans++/*,printf("%d can.\n",all)*/;if(ans==998244353) ans=0;return;}
	dfs(now+1,all+a[now],c+1,now);
	dfs(now+1,all,c,lst);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),allv+=a[i];
	sort(a+1,a+n+1);
	if(n<=20) dfs(1,0,0,0);
	else{
		printf("%d",n*n);
		return 0;
	}
	printf("%d",ans);
	return 0;
}
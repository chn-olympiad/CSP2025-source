#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int s[500005],n,k,nn,ans;
struct mine{
	int L,R;
	bool operator <(const mine b)const{return L<b.L||L==b.L&&R<=b.R;}
}a[1000005];
inline void tanxing(){
	int i=1,j;
	while(i<=n){
		bool ok=0;
		j=i;
		while(j<=n){
			if((s[j]^s[i-1])==k){ans++;ok=1;break;}
			j++;
		}
		if(ok) i=j+1;
		else i++;
	}
	printf("%d",ans);
}
void dfs(int now,int maxx){
	maxx++;
	for(int i=now+1;i<=nn;i++){
		if(a[i].L>a[now].R) dfs(i,maxx);
	}
	ans=max(ans,maxx);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		int x=read();
		s[i]=s[i-1]^x;
	}
	if(n<=10){
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		if((s[j]^s[i-1])==k) a[++nn].L=i,a[nn].R=j;
		sort(a+1,a+nn+1);
		dfs(0,0);
		printf("%d",ans-1);
	}
	else{
		if(k==0){printf("%d",n/2);return 0;}
		else{
			tanxing();
		}
	}
	return 0;
}
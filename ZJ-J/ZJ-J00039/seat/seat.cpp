#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();int f=1,ret=0;
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+(ch&15),ch=getchar();
	return f*ret;
}
int a[105],c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i]=read();
	for(int i=1;i<=n*m;i++)if((i-1)%n==0){
		if((i/n)&1)c[i]=n;
		else c[i]=1;
	}
	int x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int i=2,dd=1;
	while(i<=n*m){
		if(c[i]==n)dd=-1;
		else if(c[i]==1)dd=1;
		else c[i]=c[i-1]+dd;
		i++;
	}
	i=1;
	while(a[i]!=x)i++;
	printf("%d %d",(i+n-1)/n,c[i]);
	return 0;
}

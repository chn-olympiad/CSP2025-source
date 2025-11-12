#include<bits/stdc++.h>
using namespace std;
int a[105],m,n,b[15][15],cnt,R;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1) for(int j=1;j<=n;j++) b[j][i]=a[++cnt];
		if(i%2==0) for(int j=n;j>=1;j--) b[j][i]=a[++cnt];
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	if(b[i][j]==R){printf("%d %d\n",j,i);break;}
	return 0;
}

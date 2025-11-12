#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[1005],mp[15][15],R;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1) for(int i=1;i<=n;i++) mp[i][j]=a[++cnt];
		else for(int i=n;i>=1;i--) mp[i][j]=a[++cnt];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) if(mp[i][j]==R){printf("%d %d",j,i);return 0;}
	return 0;
}

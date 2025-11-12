//T2
//8:56 idea
//9:01 AC
//9:05 check
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m;
int a[N*N];
int c[N][N];
int pt;
void dfs(int x,int y,int id,int tot){
	c[x][y]=a[tot];
	if(x==n && y==m)return;
	if(id==1){
		if(x==n)dfs(n,y+1,2,tot+1);
		else dfs(x+1,y,1,tot+1); 
	}
	if(id==2){
		if(x==1)dfs(1,y+1,1,tot+1);
		else dfs(x-1,y,2,tot+1);
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i]=read();
	pt=a[1];sort(a+1,a+1+n*m);reverse(a+1,a+1+n*m);
	dfs(1,1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==pt){
				write(j);putchar(' ');
				write(i);putchar('\n');
				exit(0);
			}
		}
	}
	return 0;
}
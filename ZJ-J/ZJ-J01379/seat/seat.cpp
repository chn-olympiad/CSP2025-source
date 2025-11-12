#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int n,m,R,a[maxn*maxn],pos[maxn][maxn];
namespace dhcio{
	inline int read(){
		char ch=getchar();int ret=0,f=1;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
		while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
		return ret*f;
	}
	inline void write(int x){
		if(x<0) x=-x;
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
}
using namespace dhcio;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();R=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	  pos[i][j]=a[(i-1)*n+j];
	for(int i=1;i<=m;i++)
	  if(i%2==0) reverse(pos[i]+1,pos[i]+1+n);
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	  if(R==pos[i][j]){
	  	write(i);putchar(' ');write(j);putchar('\n');
	  	return 0;
	  }
	return 0;
}
//RP++ 300+ Please!
//9:35 100pts
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=105;
int n,m,l;
struct node{
	int x,id;
}a[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read(),l=n*m;
	for(int i=1;i<=l;i++)a[i].x=read(),a[i].id=i;
	sort(1+a,1+a+l,[](node A,node B){return A.x<B.x;});
	for(int i=1;i<=m;i++){
		if(i&1)for(int j=1;j<=n;j++)if(a[l--].id==1)printf("%d %d\n",i,j),exit(0);
		if(!(i&1))for(int j=n;j;j--)if(a[l--].id==1)printf("%d %d\n",i,j),exit(0);
	}
	return 0;
}
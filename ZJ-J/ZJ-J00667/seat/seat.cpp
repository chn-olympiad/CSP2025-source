#include<stdio.h>
#include<algorithm>
#define rep(i,s,e) for(int i=(s);i<=(e);++i)
#define _rep(i,s,e) for(int i=(s);i<(e);++i)
#define rev(i,s,e) for(int i=(s);i>=(e);--i)

const int N=1e4+10;

int n,m,a[N],s;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n*m) scanf("%d",&a[i]);
	s=a[1];
	std::sort(a+1,a+1+n*m,std::greater<int>());
	int pos=std::lower_bound(a+1,a+1+n*m,s,std::greater<int>())-a;
//	printf("\nhis:%d\tpos:%d\n",s,pos);
	int c,l;
	//c:cols ÁÐ 
	//l:line ÐÐ 
	c=(pos-1)/n+1;
	if(c&1) l=pos-(c-1)*n;
	else l=c*n-pos+1;
	printf("%d %d",c,l);
	return 0;
}
//#Shang4Shan3Ruo6Shui4

#include<bits/stdc++.h>//I LOVE CCF
//#define int long long
using namespace std;//I LOVE CCF
inline int read() {//I LOVE CCF
	int x=0,f=1;//I LOVE CCF
	char c=getchar();//I LOVE CCF
	while(c<'0'||c>'9') {//I LOVE CCF
		if(c=='-')f=-1;//I LOVE CCF
		c=getchar();//I LOVE CCF
	}//I LOVE CCF
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();//I LOVE CCF
	return x*f;//I LOVE CCF
}//I LOVE CCF
int n,m,x;//I LOVE CCF
int a[205];//I LOVE CCF
bool CCF(int x,int y) {//I LOVE CCF
	return x>y;
}//I LOVE CCF
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1; i<=n*m; i++)a[i]=read();
	x=a[1];
	sort(a+1,a+n*m+1,CCF);
	int id;
	for(int i=1; i<=n*m; i++)if(a[i]==x)id=i;
	int hang,lie=ceil(id*1.0/n);
	hang=lie%2==0?n-(id-(lie-1)*n)+1:id-(lie-1)*n;
	cout<<lie<<' '<<hang<<'\n';
	return 0;
}//I LOVE CCF


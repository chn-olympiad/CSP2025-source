#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}
int n,m,p,x;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n*m;i++) read(a[i]);
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==p) x=i;
	}
	int c=x/n,r;
	if (x%n) c++;
	if (c%2) r=x-(c-1)*n;
	else r=n-(x-(c-1)*n)+1;
	printf("%d %d",c,r);
	return 0;
}
//100pts?

#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,a[maxn],r;
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n*m;i++)a[i]=read();
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			int x=(i-1)/n+1,y=(i-1)%(2*n)+1;
			if(y>n)y=n-(y-n)+1;
			printf("%d %d",x,y);
			return 0;
		}
	}
	return 0;
}
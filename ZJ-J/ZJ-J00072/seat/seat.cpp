#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R;
int read(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i]=read();
	R=a[1];
	sort(a+1,a+1+n*m);reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			int x=(i+m-1)/m,y=i-(x-1)*n;
			if(x%2==0)y=n+1-y;
			printf("%d %d",x,y);
			break;
		}
	}
	return 0;
}

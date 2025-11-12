#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int n,m,k,x=0,y=1,s,a[maxn*maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++){
		a[i]=read();
		if(i==1)k=a[i];
	}
	sort(a+1,a+1+n*m);reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(a[i]==k){k=i;break;}
	for(int i=1;i<=k;i++){
		if(!s){
			if(x==n)s=1-s,y++;
			else x++;
		}else{
			if(x==1)s=1-s,y++;
			else x--;
		}
	}
	printf("%d %d\n",x,y);
	return 0;
}
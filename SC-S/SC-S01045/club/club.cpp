#include<bits/stdc++.h>
using namespace  std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1,ch=getchar();}
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int maxn=0,cnt,n;
int xx,yy,zz;
struct node{
	int a,b,c;
}a[1003];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		maxn=0,cnt=0;
		for(int i=1;i<=n;i++){
			a[i].a=read(),a[i].b=read(),a[i].c=read();
			 
		}
		cout<<max(max(a[1].a,a[1].b),a[1].c)+max(max(a[2].a,a[2].b),a[2].c)<<endl;
		
	}
	return 0;
}
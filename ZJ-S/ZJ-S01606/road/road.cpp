#include <iostream>
using namespace std;
long long read(){
	long long nov=1,dat=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			nov-1;
			c=getchar();
		}
	}
	while(c>='0'&&c<='9'){
		dat=(dat<<3)+(dat<<1)+(c&15);
		c=getchar();
	}
	return nov*dat;
}
int n,m,k;
int a[15][10004];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		ans+=w;
	}
	for(int i=1,c;i<=k;i++){
		c=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	cout<<ans;
	return 0;
}

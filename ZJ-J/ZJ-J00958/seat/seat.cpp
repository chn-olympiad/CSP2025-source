#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],x;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;++i){
		a[i]=read();
		if(i==1)x=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;++i)b[n*m-i+1]=a[i];
	for(int i=1;i<=n*m;++i){
		if(b[i]==x){
			if(((i-1)/n+1)&1){
				cout<<((i-1)/n+1)<<" "<<((i-1)%n+1)<<'\n';
			}
			else{
				cout<<((i-1)/n+1)<<" "<<(n-((i-1)%n+1)+1)<<'\n';
			}
		}
	}
	return 0;
}

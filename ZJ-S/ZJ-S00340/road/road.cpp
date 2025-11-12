#include<bits/stdc++.h>
#define ll long long
int n,m,k,u,v,w,c,a;
ll ans;
using namespace std;
int read(){
	int x=0,f=1;char aa=getchar();
	while(aa<'0'||aa>'9'){
		if(aa=='-')f=-1;
		aa=getchar();
	}
	while('0'<=aa&&aa<='9'){
		x=x*10+aa-'0';
		aa=getchar();
	}
	return x*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		c=read();
		for(int j=1;j<=n;j++)a=read();
	}
	cout<<ans;
	return 0;
}

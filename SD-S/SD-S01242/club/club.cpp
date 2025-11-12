#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+5;
int T,n,ans;
int jl[10];
bool vis[N];
struct node{
	int s,id,bm;
}a[N];
bool cmp(node x,node y){
	if(x.s==y.s) return x.id<y.id;
	return x.s>y.s;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		n=read();
		for(int i=1;i<=3*n;i+=3){
			a[i].s=read(),a[i+1].s=read(),a[i+2].s=read();
		}
		sort(a+1,a+1+3*n,cmp);
		for(int i=1;i<=n/2;++i){
			ans+=a[i].s;
		}
		printf("%lld",ans);
	}
	return 0;
}

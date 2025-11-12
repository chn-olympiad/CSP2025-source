#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int num=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
const int M=2e6;
struct node{
	int a,b,c;
} vct[M];
bool cmp(node x,node y){
	return x.c<y.c;
}
int f[M];
int fnd(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=fnd(f[x]);
}
int n,m,k;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
			f[i]=i;
		}
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		vct[i].a=u;
		vct[i].b=v;
		vct[i].c=w;
	}
	int p=0;
	int cnt=m;
	int sumc=0,sumw=0;
	for(int j=1;j<=k;j++){
		int c=read(); 
		sumc+=c;
		for(int i=1;i<=n;i++){
			int w=read();
			sumw+=w;
			if(i==1){
				p=w;
			}
			else{
				cnt++;
				vct[cnt].a=1;
				vct[cnt].b=i;
				vct[cnt].c=p+c+w;
			}
		}
	}
	if(sumc==0&&sumw==0){
		printf("0");
		return 0;
	}
	sort(vct+1,vct+1+cnt,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int x=vct[i].a,y=vct[i].b;
		if(fnd(x)!=fnd(y)){
			f[fnd(x)]=fnd(y);
			ans+=vct[i].c;
		}
	}
	printf("%lld",ans);
	return 0;
 }


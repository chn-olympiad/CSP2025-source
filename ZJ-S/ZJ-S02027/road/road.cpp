#include<bits/stdc++.h>
#define rint register int
using namespace std;
//bool kkksc03;
const int mxn=10001,mxm=1000001,mxk=11;
int n,m,k,cost[mxk],fa[mxn+mxk]={},ww[mxk][mxn],ans=1e9;
struct road{
	int u,v,w;
}a[mxm+mxk*mxn],b[mxm+mxk*mxn];
//bool soha;
inline int read(){
    int x=0;bool f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return f?-x:x;
}
bool cmp(road a,road b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	//printf("%lfMB\n",(&soha-&kkksc03)/1024.0/1024.0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    for(rint i=1;i<=m;i++){
    	a[i].u=read();a[i].v=read();a[i].w=read();
	}
	sort(a+1,a+1+m,cmp);
	for(rint i=1;i<=n;i++)fa[i]=i;
	int cnt=0,ans=0,idx=1;
	while(1){
		if(cnt>=n-1)break;
		if(find(a[idx].u)==find(a[idx].v)){
			idx++;
			continue;
		}
		ans+=a[idx].w;
		fa[find(a[idx].u)]=find(a[idx].v);
		idx++;cnt++;
	}
	cout<<ans;
    return 0;
}
/*
	Code is far away from
bug with the animal protecting
*/
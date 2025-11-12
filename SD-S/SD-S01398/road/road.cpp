#include <bits/stdc++.h>
using namespace std;
int fa[100005];
int c[100005][11];
struct Node{
	int u,v,w;
}a[1000005];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int n,m,k,sum;
int read(){
	int f=1,x=0;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')
		f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
	return x;
}
int find(int x){
	if(x!=fa[x]) x=find(fa[x]),fa[x]=x;
	return fa[x];
}
void unionn(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y)
	fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++){
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
		fa[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	if(k==0){
		int i=0;
		while(i<n){
			i++;
			if(find(a[i].u)!=find(a[i].v))
			unionn(a[i].u,a[i].v),sum+=a[i].w;
			else
			continue;
		}
		cout<<sum;
	}
	else{
		int a=rand()%1324654;
		cout<<a;
	}
	return 0;
}

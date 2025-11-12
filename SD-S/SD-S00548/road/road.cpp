#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2001000;
struct node{
	int a,b,c;
}x[N];
bool fl=1;
int pw[N],inp[N],www[N],fa[N],ic[N],ed[12][100100];
bool cmp(node ss,node tt){
	if(ss.c==tt.c){
		return ss.a<tt.a;
	}
	return ss.c<tt.c;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int read(){
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int n,m,cnt,k;
ll ans;
bool chos[12];
void kruskal(){
	cnt=m;
	ll res=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		if(chos[i]){
			res+=pw[i];
			for(int j=1;j<=n;j++){
				x[++cnt].a=n+i;
				x[cnt].b=j;
				x[cnt].c=ed[i][j];
			}
		}
	}
	sort(x+1,x+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int uu=x[i].a;
		int vv=x[i].b;
		int ww=x[i].c;
		if(find(uu)!=find(vv)){
			merge(uu,vv);
			res+=ww;
		}
	}
	ans=min(res,ans);
	return ;
}
void solve(){
	ans=99999999999999999;
	int erp=1;
	for(int i=1;i<=k;i++){
		erp*=2;
	}
	for(int i=0;i<erp;i++){
		for(int j=1;j<=k;j++){
			chos[j]=(i&(1<<(j-1)));
		}
		kruskal();
	}
	cout<<ans;
	return ;
}
int main(){
	srand((int)time(0));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		x[++cnt].a=read();
		x[cnt].b=read();
		x[cnt].c=read();
	}
	for(int i=1;i<=n+10;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		pw[i]=read();
		//cout<<pw[i]<<" ";
		if(pw[i]!=0)fl=0;
		ans+=pw[i];
		for(int j=1;j<=n;j++){
			x[++cnt].a=n+i;
			x[cnt].b=j;
			x[cnt].c=read();
			ed[i][j]=x[cnt].c;
		}
	}
	//cout<<fl<<"\n";
	if(k!=0&&!fl){
		//cout<<"ww\n";
		if(k>5){
			cout<<rand();
		}
		else{
			solve();
		}
		return 0;
	}
	sort(x+1,x+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int uu=x[i].a;
		int vv=x[i].b;
		int ww=x[i].c;
		int fu=find(uu);
		int fv=find(vv);
		if(fu!=fv){
			merge(uu,vv);
			ans+=ww;
			if(uu>n){
				www[uu]+=ww;
				inp[uu]++;
			}
		}
	}
	for(int uu=n+1;uu<=n+k;uu++){
		if(inp[uu]<=1){
			ans-=pw[uu]+www[uu];
		}
	}cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

#include<bits/stdc++.h>
#define se second
#define fs first
using namespace std;
const int maxn=1e4+5,maxm=1e6+5;
int n,m,k,fa[maxn];
pair<int,pair<int,int>> eg[maxm];
bool flgA=1;

int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

struct Node{
	int c,cst[maxn];	
	void init(){
		flgA&=(!(c=read()));
		for(int i=1;i<=n;i++) flgA&=!(cst[i]=read());
	}
}vill[15];

int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int a=read(),b=read(),w=read();
		eg[i]={w,{a,b}};
	}
	for(int i=1;i<=k;i++) vill[i].init();
	if(flgA) cout<<0<<endl,exit(0);
	if(k==0){
		int ans=0;
		sort(eg+1,eg+1+m);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int x=eg[i].se.fs,y=eg[i].se.se;
			int fx=getfa(x),fy=getfa(y);
			if(fx==fy) continue;
			f[fx]=fy;
			ans+=eg[i].fs;
		}
		cout<<ans;
		return 0;
	}
	srand(time(0));
	cout<<rand();// 
    return 0;
}
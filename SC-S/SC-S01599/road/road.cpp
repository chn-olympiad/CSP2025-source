#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-'){
			f=-f;
		}
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
struct sj{
	int l,r,z;
};
int bcj[20001];
sj cb[1000001];
sj yyb[10001];
sj cb2[200001];
int gz[11];
bool ff(sj a,sj b){
	return a.z<b.z;
}
int cx(const int a){
	if(bcj[a]!=a){
		bcj[a]=cx(bcj[a]);
	}
	return bcj[a];
}
void hb(const int a,const int b){
	if(cx(a)!=cx(b)){
		bcj[bcj[a]]=bcj[b];
	}
	return;
}
int fy[11][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c,d,g;
	long long e,f;
	a=read();
	b=read();
	c=read();
	for(int v=1;v<=b;++v){
		cb[v].l=read();
		cb[v].r=read();
		cb[v].z=read();
	}
	sort(cb+1,cb+b+1,ff);
	for(int v=1;v<=a;++v){
		bcj[v]=v;
	}
	d=0;
	for(int v=1;v<=b;++v){
		if(cx(cb[v].l)!=cx(cb[v].r)){
			yyb[++d]=cb[v];
			hb(cb[v].l,cb[v].r);
		}
	}
	for(int v=1;v<=c;++v){
		gz[v]=read();
		for(int var=1;var<=a;++var){
			fy[v][var]=read();
		}
	}
	e=1145141145141919810;
	for(int v=0;v<(1<<c);++v){
		f=0;
		g=d;
		for(int v=1;v<=d;++v){
			cb2[v]=yyb[v];
		}
		for(int va=0;va<c;++va){
			if(v&(1<<va)){
				f=f+gz[va+1];
				for(int var=1;var<=a;++var){
					++g;
					cb2[g].l=va+1+a;
					cb2[g].r=var;
					cb2[g].z=fy[va+1][var];
				}
			}
		}
		sort(cb2+1,cb2+g+1,ff);
		for(int v=1;v<=a+c;++v){
			bcj[v]=v;
		}
		for(int v=1;v<=g;++v){
			if(cx(cb2[v].l)!=cx(cb2[v].r)){
				hb(cb2[v].l,cb2[v].r);
				f=f+cb2[v].z;
			}
		}
		e=min(e,f);
	}
	cout<<e;
	return 0;
} 
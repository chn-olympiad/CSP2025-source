#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N=1e5+10;
int T,n,p[N],tot2,tot3; 
int tot;
struct node{
	int a1,a2,a3;
}a[N];
struct qwq{
	int d,x,y;
}t2[N],t3[N],tx,ty;
ll ans,maxx;
inline bool operator <(qwq x,qwq y){
	return x.x-x.y<y.x-y.y;
}
inline bool cmp(node x,node y){
	return x.a2-x.a3>y.a2-y.a3;
}
set<qwq>st,st2,st3,st4,st5;
inline int read() {
	register int x=0,f=1;
	register char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	register int i,x,siz,y;
	T=read();
	while(T--){
		n=read();
		siz=n/2;
		st2.clear();
		st3.clear();
		st4.clear();
		st5.clear();
		ans=maxx=0;
		for(i=1;i<=n;++i){
			a[i]=(node){read(),read(),read()};
		}
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=siz;++i){
			ans+=a[i].a2;
			st4.insert((qwq){i,a[i].a1,a[i].a2});
			st2.insert((qwq){i,a[i].a3,a[i].a2});
		}
		for(i=siz+1;i<=n;++i){
			ans+=a[i].a3;
			st5.insert((qwq){i,a[i].a1,a[i].a3});
			st3.insert((qwq){i,a[i].a2,a[i].a3});
		}
		maxx=ans;
		tot=0;
		while(tot<siz&&!st4.empty()&&!st5.empty()){
			auto it1=st4.end();
			auto it2=st5.end();
			it1--,it2--;
			x=(*it1).d,y=(*it2).d;
			if(a[x].a1-a[x].a2>a[y].a1-a[y].a3){
				auto it=st3.end();
				it--;
				tx=(*it);
				if(tx.x-tx.y+a[x].a1-a[x].a2>=0||a[x].a1-a[x].a2>0){
					ans+=a[x].a1-a[x].a2;
					tx=(*it1);
					ty=tx;
					ty.x=a[ty.d].a3,ty.y=a[ty.d].a2;
					st4.erase(tx),st2.erase(ty);
					it=st3.end();
					it--;
					if((*it).x-(*it).y>=0){
						tx=(*it);
						ty=tx;
						ty.x=a[ty.d].a1,ty.y=a[ty.d].a3;
						ans+=tx.x-tx.y;
						st3.erase(tx),st5.erase(ty);
						swap(tx.x,tx.y);
						ty=tx;
						ty.x=a[ty.d].a1,ty.y=a[ty.d].a2;
						st4.insert(ty),st2.insert(tx);
					}
				}
				else{
					tx=(*it1);
					ty=tx;
					ty.x=a[ty.d].a3,ty.y=a[ty.d].a2;
					st4.erase(tx),st2.erase(ty);
					tot++;
					continue;
				}
			}
			else{
				auto it=st2.end();
				it--;
				tx=(*it);
				if(tx.x-tx.y+a[x].a1-a[x].a3>=0||a[x].a1-a[x].a3>=0){
					ans+=a[y].a1-a[y].a3;
					tx=(*it2);
					ty=tx;
					ty.x=a[ty.d].a2,ty.y=a[ty.d].a3;
					st5.erase(tx),st3.erase(ty);
					it=st2.end();
					it--;
					if((*it).x-(*it).y>=0){
						tx=(*it);
						ty=tx;
						ty.x=a[ty.d].a1,ty.y=a[ty.d].a2;
						ans+=tx.x-tx.y;
						st2.erase(tx),st4.erase(ty);
						swap(tx.x,tx.y);
						ty=tx;
						ty.x=a[ty.d].a1,ty.y=a[ty.d].a3;
						st5.insert(ty),st3.insert(tx);
					}
				}
				else{
					tx=(*it2);
					ty=tx;
					ty.x=a[ty.d].a2,ty.y=a[ty.d].a3;
					st5.erase(tx),st3.erase(ty);
					tot++;
					continue;
				}
			}
			maxx=max(maxx,ans);
			++tot;
		}
		while(st4.empty()&&tot<siz){
			auto it2=st5.end();
			it2--;
			y=(*it2).d;
			if(a[y].a1<a[y].a3){
				tx=(*it2);
				ty=tx;
				ty.x=a[ty.d].a2,ty.y=a[ty.d].a3;
				st5.erase(tx),st3.erase(ty);
				tot++;
				continue;
			}
			ans+=a[y].a1-a[y].a3;
			tx=(*it2);
			ty=tx;
			ty.x=a[ty.d].a2,ty.y=a[ty.d].a3;
			st5.erase(tx),st3.erase(ty);
			++tot;
			maxx=max(maxx,ans);
		}
		if(st5.empty()&&tot<siz){
			auto it1=st4.end();
			it1--;
			x=(*it1).d;
			if(a[x].a1<a[x].a2){
				tx=(*it1);
				ty=tx;
				ty.x=a[ty.d].a3,ty.y=a[ty.d].a2;
				st4.erase(tx),st2.erase(ty);
				tot++;
				continue;
			}
			ans+=a[x].a1-a[x].a2;
			tx=(*it1);
			ty=tx;
			ty.x=a[ty.d].a3,ty.y=a[ty.d].a2;
			st4.erase(tx),st2.erase(ty);
			++tot;
			maxx=max(maxx,ans);
		}
		printf("%lld\n",maxx);
	}
}

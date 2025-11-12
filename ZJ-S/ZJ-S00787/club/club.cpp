#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=ch=='-'?-f:f,ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int Mid(int a,int b,int c){
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	return b;
}
const int N=1e5+10;
int t,n;
struct Furina{
	int a,b,c,mx,mx2,v;
	bool operator<(const Furina B)const{return mx-mx2<B.mx-B.mx2;}
}a[N];
int p[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		memset(p,0,sizeof p);
		n=read();
		long long ans=0;
		for(int i=1;i<=n;i++)a[i].a=read(),a[i].b=read(),a[i].c=read(),a[i].mx=max(a[i].a,max(a[i].b,a[i].c)),a[i].mx2=Mid(a[i].a,a[i].b,a[i].c),ans+=a[i].mx;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i].a==a[i].mx)a[i].v=1;
			else if(a[i].b==a[i].mx)a[i].v=2;
			else a[i].v=3;
			p[a[i].v]++;
		}
		int maxp=max(max(p[1],p[2]),p[3]);
		int V;
		if(maxp==p[1])V=1;
		else if(maxp==p[2])V=2;
		else V=3;
		if(maxp>n/2){
			int k=maxp-n/2,K=0;
			for(int i=1;i<=n;i++){
				if(a[i].v==V){
					K++;
					ans-=a[i].mx-a[i].mx2;
				}
				if(K==k)break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Luogu user :I_Love_Furina
//Luogu uid 1113349
//Genshin Impact uid 275713829
//Fuirna!!!
//RP++
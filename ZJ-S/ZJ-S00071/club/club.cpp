#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define _F(i,a,b) for(int i=(a);i>=(b);i--)
int read(){
	int p=0,f=1;char ch=getchar();
	while(!isdigit(ch))
		f=ch=='-'?-1:1,ch=getchar();
	while(isdigit(ch))
		p=p*10+ch-'0',ch=getchar();
	return p*f;
}
const int N=1e5+5;
int n;
struct qwe{
	int q[5],c,d,t;
	
}a[N];
int b[5];
void init(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	
}
void trry(int x){
	if(a[x].q[1]>=a[x].q[2]&&a[x].q[1]>=a[x].q[3])
		b[1]++,
		a[x].c=a[x].q[1]-max(a[x].q[2],a[x].q[3]),
		a[x].d=max(a[x].q[2],a[x].q[3]),
		a[x].t=1;
		
	else if(a[x].q[2]>=a[x].q[1]&&a[x].q[2]>=a[x].q[3])
		b[2]++,
		a[x].c=a[x].q[2]-max(a[x].q[1],a[x].q[3]),
		a[x].d=max(a[x].q[1],a[x].q[3]),
		a[x].t=2;
		
	else if(a[x].q[3]>=a[x].q[1]&&a[x].q[3]>=a[x].q[2])
		b[3]++,
		a[x].c=a[x].q[3]-max(a[x].q[2],a[x].q[1]),
		a[x].d=max(a[x].q[2],a[x].q[1]),
		a[x].t=3;
	
	return;
}
bool cmp(qwe x,qwe y){
	return x.c>y.c;
}
void solve(){
	init();
	n=read();
	F(i,1,n){
		a[i].q[1]=read();
		a[i].q[2]=read();
		a[i].q[3]=read();
		trry(i);
	}
	int ans=0;
	F(i,1,3){
//		printf("%d ",b[i]);
		if(b[i]<=n/2){
			F(j,1,n){
				if(a[j].t==i){
					ans+=a[j].q[a[j].t];
				}
			}
		}
		else{
			sort(a+1,a+n+1,cmp);
			int tmp=n/2;
			F(j,1,n){
				if(a[j].t==i){
					if(tmp>=1)
						ans+=a[j].q[a[j].t];
					else
						ans+=a[j].d;
					tmp--;
				}
			}
		}
	}
	printf("%d\n",ans);
}
signed main()
{
 freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
	int t=read();
	F(i,1,t){
		solve();
	}
   return 0;
}


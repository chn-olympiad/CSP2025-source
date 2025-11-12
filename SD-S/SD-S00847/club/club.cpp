#include<bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int,int>
#define rd read()
#define x first
#define y second
#define y1 Y1
#define y0 Y0
//char buf[(1<<21)+10],obuf[(1<<21)+10],*p1=buf,*p2=buf,*O=obuf;int ol=(1<<21);
//#define getchar() (((p1==p2)&&(p2=((p1=buf)+fread(buf,1,ol,stdin)),p1==p2))?EOF:*p1++)
//#define flush() (fwrite(obuf,1,O-obuf,stdout),O=obuf)
//#define putchar(x) (((O-obuf==ol)&&(flush(),O-obuf==ol))?:*O++=x)
inline int read(int u=0,char c=getchar(),bool f=false){
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) u=(u<<1)+(u<<3)+(c^'0');
	return f?-u:u;
}
inline void wt(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) wt(x/10);
	putchar((x%10)^'0');
}
inline void wt(int x,char c){wt(x);putchar(c);}
const int N=1e5+10;
int n,ans;P a[N][3];
priority_queue<int>q[3];
void work(){
	n=rd;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++)
			a[i][j].x=rd,a[i][j].y=j;
		sort(a[i],a[i]+3);ans+=a[i][2].x;
		q[a[i][2].y].push(a[i][1].x-a[i][2].x);
	}int pos=-1;for(int i=0;i<=2;i++) if(q[i].size()>n/2) pos=i;
	if(pos!=-1) while(q[pos].size()>n/2) ans+=q[pos].top(),q[pos].pop();
	wt(ans,'\n');
	for(int i=0;i<=2;i++) while(!q[i].empty()) q[i].pop();ans=0;
}
main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=rd;while(T--) work();
	return /*flush(),*/0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

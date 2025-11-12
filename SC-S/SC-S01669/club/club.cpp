#include<bits/stdc++.h>
#define N 100002
using namespace std;
int s,f;
char ch;
inline int read() {
	s=0, f=1;
	do if(ch=='-') f=-1;
	while((ch=getchar())<48);
	do s=(s<<3)+(s<<1)+(ch^48);
	while((ch=getchar())>47);
	return s*f;
}
inline void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
struct node {
	int a,b,c;
} arr;
vector<node> va,vb,vc;
int T,n,now,tot,pos;
inline bool cmp1(node xx,node yy) {
	return xx.a-max(xx.b,xx.c)<yy.a-max(yy.b,yy.c);
}
inline bool cmp2(node xx,node yy) {
	return xx.b-max(xx.a,xx.c)<yy.b-max(yy.a,yy.c);
}
inline bool cmp3(node xx,node yy) {
	return xx.c-max(xx.a,xx.b)<yy.c-max(yy.a,yy.b);
}
inline void solve() {
	n=read();
	va.clear();
	vb.clear();
	vc.clear();
	tot=0;
	for(int i=1; i<=n; i++) {
		arr.a=read(), arr.b=read(), arr.c=read();
		now=max(max(arr.a,arr.b),arr.c);
		if(arr.a==now) va.push_back(arr);
		else if(arr.b==now) vb.push_back(arr);
		else vc.push_back(arr);
		tot+=now;
	}
	if(va.size()>n/2) {
		sort(va.begin(),va.end(),cmp1);
		pos=va.size()-n/2;
		for(int i=0; i<pos; i++) {
			tot-=va[i].a;
			tot+=max(va[i].b,va[i].c);
		}
		write(tot);
		putchar('\n');
	} else if(vb.size()>n/2) {
		sort(vb.begin(),vb.end(),cmp2);
		pos=vb.size()-n/2;
		for(int i=0; i<pos; i++) {
			tot-=vb[i].b;
			tot+=max(vb[i].a,vb[i].c);
		}
		write(tot);
		putchar('\n');
	} else if(vc.size()>n/2) {
		sort(vc.begin(),vc.end(),cmp3);
		pos=vc.size()-n/2;
		for(int i=0; i<pos; i++) {
			tot-=vc[i].c;
			tot+=max(vc[i].a,vc[i].b);
		}
		write(tot);
		putchar('\n');
	} else {
		write(tot);
		putchar('\n');
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}

// 性质：只有可能出现一处冲突，并且这处冲突刚好平息为 n/2 时最优。且，平息过程中一定不存在新的冲突出现。
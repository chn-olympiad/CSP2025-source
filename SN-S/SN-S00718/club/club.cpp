#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e5+5;
int read () {
	int f=1,x=0;char ch=getchar();
	while (!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while (isdigit(ch)) {x=x*10+ch-48;ch=getchar();}
	return f*x;
}
int T,n;
struct node {
	int a,b,c,d,tm,sm;
}a[N]; 
bool cmp (node a,node b) {
	return a.d<b.d;
}
signed main () {
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout); 
	T=read();
	while (T--) {
		n=read();
		int sum=0,s1=0,s2=0,s3=0;
		queue <int> st,nd,rd;
		for(int i=1;i<=n;i++)
			a[i].a=read(),
			a[i].b=read(),
			a[i].c=read();
		for(int i=1;i<=n;i++) {
			int A=a[i].a,B=a[i].b,C=a[i].c; 
			int mx=max(max(A,B),C);
			int mn=min(min(A,B),C);
			int mi=A+B+C-mx-mn;
			a[i].d=mx-mi;
			if(mx==A) a[i].tm=1;
			if(mx==B) a[i].tm=2;
			if(mx==C) a[i].tm=3;
			if(mi==A) a[i].sm=1;
			if(mi==B) a[i].sm=2;
			if(mi==C) a[i].sm=3;
			sum+=mx;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) {
			if(a[i].tm==1) {
				st.push (i); s1++;
				if (s1>n/2) {
					s1--;
					int c=st.front(); st.pop();
					int s=a[c].sm; 
					if(s==2) nd.push(c),s2++,sum-=a[c].d;
					if(s==3) rd.push(c),s3++,sum-=a[c].d;
				} 
			} if(a[i].tm==2) {
				nd.push (i); s2++;
				if (s2>n/2) {
					s2--;
					int c=nd.front(); nd.pop();
					int s=a[c].sm; 
					if(s==1) st.push(c),s1++,sum-=a[c].d;
					if(s==3) rd.push(c),s3++,sum-=a[c].d;
				} 
			} if(a[i].tm==3) {
				rd.push (i); s3++;
				if (s3>n/2) {
					s3--;
					int c=rd.front(); rd.pop();
					int s=a[c].sm; 
					if(s==2) nd.push(c),s2++,sum-=a[c].d;
					if(s==1) st.push(c),s1++,sum-=a[c].d;
				} 
			}
		} cout<<sum<<'\n';
	}
	return 0;
}

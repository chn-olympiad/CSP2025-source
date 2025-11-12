#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,P=5;
long long t,n,k,p[N],cnt=0,tong[P],ma,l;
struct node{
	long long b,v;
}a[N][5];
bool cmp(long long f1,long long f2){
	return f1<f2;
}
long long read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	long long w=0;
	while(isdigit(c)){
		w=(w<<1)+(w<<3)+c-'0';
		c=getchar();
	}
	return w;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		k=0;
		for(int i=1;i<=n;i++){
			a[i][1].v=read();a[i][2].v=read();a[i][3].v=read();
			a[i][1].b=1;a[i][2].b=2;a[i][3].b=3;
			if(a[i][1].v<a[i][2].v) swap(a[i][1],a[i][2]);
			if(a[i][1].v<a[i][3].v) swap(a[i][1],a[i][3]);
			if(a[i][2].v<a[i][3].v) swap(a[i][2],a[i][3]);
		}
		tong[1]=tong[2]=tong[3]=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			k+=a[i][1].v;
			tong[a[i][1].b]++;
			ma=max(tong[1],max(tong[2],tong[3]));
		}
		l=1;
		if(tong[1]==ma) l=1;
		else if(tong[2]==ma) l=2;
		else l=3;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i][1].b==l) p[++cnt]=a[i][1].v-a[i][2].v;
		}
		sort(p+1,p+1+cnt,cmp);
		for(int i=ma;i>n/2;i--) k-=p[ma-i+1];
		printf("%lld\n",k);
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522

150176

*/

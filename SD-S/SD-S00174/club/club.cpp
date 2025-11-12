#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rop(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a,b) for(int i=(a);i>(b);--i)
using namespace std;
int iread(){int x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
ll lread(){ll x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
const int N=1e5+500;
int a[N],b[N],c[N];
int v[N];
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=iread();
	while(T--){
		
	n=iread();
	FOR(i,1,n){
		a[i]=iread();
		b[i]=iread();
		c[i]=iread();
	}
	ll sum=0;
	int A,B,C;
	A=B=C=0;
	FOR(i,1,n){
		int tmp=max(a[i],b[i]);
		tmp=max(tmp,c[i]);
		if(tmp==a[i]) ++A;
		else if(tmp==b[i]) ++B;
		else ++C;
		sum+=tmp;
	}
//	cout<<A<<" "<<B<<" "<<C<<endl;
	int cur=n>>1;
	if(C>cur) swap(a,c);
	else if(B>cur) swap(a,b);
	else {
		if(A>cur) ;
		else {
			printf("%lld\n",sum);
			continue;
		}
	}
	int m=0;
	FOR(i,1,n){
		int tmp=max(a[i],b[i]);
		tmp=max(tmp,c[i]);
		if(tmp==a[i]){
			++m;
			v[m]=a[i]-max(b[i],c[i]);
		}
	}
//	cout<<m<<endl;
	sort(v+1,v+m+1);
//	FOR(i,1,m) cout<<v[i]<<" ";
//	puts("");
	m-=cur;
	FOR(i,1,m){
		sum-=v[i];
	}
	printf("%lld\n",sum);
		
	}
	return 0;
}



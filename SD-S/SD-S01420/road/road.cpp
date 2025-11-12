#include <bits/stdc++.h>
#define pii pair<long long,long long>
#define fi first
#define se second
#define pipii pair<long long,pii>
using namespace std;
const int N=1e4+25;
long long x,f;char ch;
inline long long rd(){
	x=0,f=1;ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return f*x;
}long long _s[20],_t;
void wt(long long x){
	if(x<0)putchar('-'),x=-x;
	do _s[++_t]=x%10,x/=10;
	while(x);while(_t)putchar(_s[_t--]+48);
	return;
}
long long n,m,k,sum,ans1=9e18,i,j,l;
long long c[15],a[15][N],fu,fv,ln,h[N],stk[N],top,mx;
pipii e[1100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(i=1;i<=m;++i)
		e[i].se.fi=rd(),e[i].se.se=rd(),e[i].fi=rd();
	
	for(i=1;i<=k;++i){
		c[i]=rd();
		mx=max(c[i],mx);
		for(j=1;j<=n;++j)
			a[i][j]=rd();
		
	}
	for(l=(1<<k)-1;l>=0;--l){
		for(i=1;i<=n+k;++i)h[i]=i;
		ln=m;
		for(i=0;i<k;++i){
			if(l&(1<<i)){
				sum+=c[i+1];
				for(j=1;j<=n;++j){
					e[++ln]={a[i+1][j],{j,i+n+1}};
				}
			}
		}sort(e+1,e+ln+1);
		for(i=1;i<=ln;++i){
			fu=e[i].se.fi,fv=e[i].se.se;
			while(h[fu]!=fu)stk[++top]=fu,fu=h[fu];
			while(top)h[stk[top--]]=fu;
			while(h[fv]!=fv)stk[++top]=fv,fv=h[fv];
			while(top)h[stk[top--]]=fv;
			if(fu==fv)continue;
			sum+=e[i].fi,h[fu]=fv;
		}
		ans1=min(ans1,sum);
		if(mx==0)break;
	}wt(ans1);
	return 0;
}


#include<bits/stdc++.h>
#define rd read()
#define ll long long
#define lbt(x) ((x)&(-(x)))
#define Cmax(a,b) (a=max(a,(b)))
#define Cmin(a,b) (a=min(a,(b)))
#define for_(a,b,c) for(int a=(b);a<=(c);++a)
#define For_(a,b,c) for(int a=(b);a>=(c);--a)
#define md ((l+r)/2)
using namespace std;
	int n;
	const int N=1e5+10;
	ll a[N][5],mx[N],cimx[N],mxid[N],dlt[N],cnt[N],st[N],tp;
	inline ll read(){ll d=0,f=0;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}while(ch>='0'&&ch<='9'){d=(d<<1)+(d<<3)+ch-'0';ch=getchar();}return f?-d:d;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	For_(TT,rd,1){
		for_(i,1,3)cnt[i]=0;tp=0;
		n=rd;ll sum=0;
		for_(i,1,n){
			mx[i]=-100,cimx[i]=-100,mxid[i]=1;
			for_(j,1,3){
				a[i][j]=rd;
				if(a[i][j]>=mx[i])cimx[i]=mx[i],mx[i]=a[i][j],mxid[i]=j;
				else if(a[i][j]>=cimx[i])cimx[i]=a[i][j];
			}
			++cnt[mxid[i]];
			sum+=mx[i];
			dlt[i]=mx[i]-cimx[i];
//			cout<<mx[i]<<" "<<mxid[i]<<"  "<<cimx[i]<<"\n";
		}
		ll mxcnt=0,mxcntid=1;
		for_(i,1,3){
			if(cnt[i]>mxcnt)mxcnt=cnt[i],mxcntid=i;
		}
		if(mxcnt<=(n/2)){
			cout<<sum<<"\n";continue;
		}
		for_(i,1,n){
			if(mxid[i]==mxcntid)st[++tp]=dlt[i];
		}
		sort(st+1,st+1+tp);
		for_(i,1,mxcnt-(n/2)){
			sum-=st[i];
		}
		cout<<sum<<"\n";
	}
	
	
	
	return 0;
}

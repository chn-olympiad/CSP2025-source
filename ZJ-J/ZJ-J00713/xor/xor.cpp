#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+5;
long long n,k,a[maxn],mxl=-(1<<30),mil=1<<30,ans;
long long read(){
	long long ret=0,f=1;char ch=getchar();
	while('0'>ch||ch>'9')f=(ch=='-')?-f:f,ch=getchar();
	while('0'<=ch&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
struct tree{
	struct note{
		long long l,r,sum,lz;
	}tr[maxn*4];
	void build(long long i,long long l,long long r){
		tr[i].l=l;tr[i].r=r;
		if(l==r){tr[i].sum=a[l];return;}
		long long mid=(l+r)/2;
		build(i*2,l,mid);
		build(i*2+1,mid+1,r);
		tr[i].sum=tr[i*2].sum^tr[i*2+1].sum;
	}
	long long search(long long i,long long l,long long r){
		if(l>tr[i].r||tr[i].l>r)return 0;
		if(l<=tr[i].l&&tr[i].r<=r)return tr[i].sum;
		return search(i*2,l,r)^search(i*2+1,l,r);
	}
}A;
struct node{
	long long l,r;
	bool operator <(const node &x)const{return r<x.r||(r==x.r&&l<x.l);}
}q[maxn*2];
long long m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(long long i=1;i<=n;i++){
		a[i]=read();
		mxl=max(mxl,a[i]);
		mil=min(mil,a[i]);
	}
	A.build(1,1,n);
	if(k==0&&mil==1&&mxl==1){printf("%lld\n",n/2);return 0;}
	if(k==1&&mxl==1){for(long long i=1;i<=n;i++)if(a[i])ans++;printf("%lld\n",ans);return 0;}
	if(k==0&&mxl==1){
		bool f;
		for(long long i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else{
				if(a[i-1])ans++,a[i]=0;
			}
		}
		printf("%lld\n",ans);
	}
	for(long long l=1;l<=n;l++){
		for(long long r=l;r<=n;r++){
			if(A.search(1,l,r)==k)q[++m].l=l,q[m].r=r;
		}
	}
	sort(q+1,q+1+m);
	long long l=0;
	bool f=1;
	while(f){
		for(long long i=1;i<=m;i++){
			if(i==m&&q[m].l<=l){
				f=0;break;
			}
			if(q[i].l>l){
				l=q[i].r;
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
	
	
	return 0;
}

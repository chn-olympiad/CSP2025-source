#include<bits/stdc++.h>
namespace chuazen{
	#define int long long
	#define max(x,y) (x>y?x:y)
	#define min(x,y) (x<y?x:y)
	#define ufor(i,x,y) for(int i=x;i<=y;i++)
	#define dfor(i,x,y) for(int i=x;i>=y;i--)
	#define N 100005
	char out[100];
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
		while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
		return x*f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		int tp=0;
		do{out[++tp]=x%10+'0';x/=10;}while(x);
		while(tp)putchar(out[tp--]);
	}
}
using namespace std;
using namespace chuazen;
int T;
int n,mxn,a[N][4],ans;
int A[N],cnta,B[N],cntb,C[N],cntc;
inline void solve(){
	ufor(i,1,cnta)A[i]=0;cnta=0;
	ufor(i,1,cntb)B[i]=0;cntb=0;
	ufor(i,1,cntc)C[i]=0;cntc=0;
	ans=0;
	
	n=read();mxn=n/2;
	ufor(i,1,n){
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])A[++cnta]=i,ans+=a[i][1];
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])B[++cntb]=i,ans+=a[i][2];
		else C[++cntc]=i,ans+=a[i][3];
	}
	if(cnta<=mxn&&cntb<=mxn&&cntc<=mxn){write(ans),puts("");return;}
	
	if(cnta>mxn){
		sort(A+1,A+cnta+1,[](int x,int y){return (a[x][1]-max(a[x][2],a[x][3]))<(a[y][1]-max(a[y][2],a[y][3]));});
		ufor(i,1,cnta-mxn)ans=ans-a[A[i]][1]+max(a[A[i]][2],a[A[i]][3]);
	}
	else if(cntb>mxn){
		sort(B+1,B+cntb+1,[](int x,int y){return (a[x][2]-max(a[x][1],a[x][3]))<(a[y][2]-max(a[y][1],a[y][3]));});
		ufor(i,1,cntb-mxn)ans=ans-a[B[i]][2]+max(a[B[i]][1],a[B[i]][3]);
	}
	else{
		sort(C+1,C+cntc+1,[](int x,int y){return (a[x][3]-max(a[x][1],a[x][2]))<(a[y][3]-max(a[y][1],a[y][2]));});
		ufor(i,1,cntc-mxn)ans=ans-a[C[i]][3]+max(a[C[i]][1],a[C[i]][2]);
	}
	
	write(ans),puts("");
	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	T=read();
	while(T--)solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
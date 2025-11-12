#include <bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define F(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
const int N=1e5+1;
int t,n,a[N][5],ans,g[5],cha[N],cnt,T;
int read(){
	int X=0,F=1;
	char C=getchar();
	while(C<'0'||C>'9'){if(C=='-') F=-1;C=getchar();}
	while(C>='0'&&C<='9'){X=X*10+C-'0';C=getchar();}
	return X*F;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		g[1]=g[2]=g[3]=0;
		cnt=0,ans=0,T=1;
		n=read();
		f(i,1,n,1){
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{ans+=a[i][1];g[1]++;a[i][0]=1;}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{ans+=a[i][2];g[2]++;a[i][0]=2;}
			else{ans+=a[i][3];g[3]++;a[i][0]=3;}
		}
		if(g[3]>n/2){
			f(i,1,n,1) if(a[i][0]==3)
				cha[++cnt]=a[i][3]-max(a[i][2],a[i][1]);
			sort(cha+1,cha+cnt+1);
			while(g[3]>n/2){ans-=cha[T];T++;g[3]--;}
		}
		if(g[2]>n/2){
			f(i,1,n,1) if(a[i][0]==2)
				cha[++cnt]=a[i][2]-max(a[i][3],a[i][1]);
			sort(cha+1,cha+cnt+1);
			while(g[2]>n/2){ans-=cha[T];T++;g[2]--;}
		}
		if(g[1]>n/2){
			f(i,1,n,1) if(a[i][0]==1)
				cha[++cnt]=a[i][1]-max(a[i][2],a[i][3]);
			sort(cha+1,cha+cnt+1);
			while(g[1]>n/2){ans-=cha[T];T++;g[1]--;}
		}
		printf("%d\n",ans);
	}
	return 0;
}

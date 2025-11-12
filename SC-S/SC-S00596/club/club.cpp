#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fs first
#define sc second
#define il inline
#define re register
using namespace std;
il int read()
{
	re int x=0;
	re int ff=1;
	re char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			ff=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*ff;
}
const int N=1e5+6;
int t,n,a[N][3],cnt[3],awa;
pii b[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();awa=0,cnt[0]=cnt[1]=cnt[2]=0;
		for(re int i=1,x,y;i<=n;i++){
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])cnt[0]++,awa+=a[i][0],b[i].sc=0,x=a[i][0],y=max(a[i][1],a[i][2]);
			else if(a[i][1]>=a[i][2])cnt[1]++,awa+=a[i][1],x=a[i][1],b[i].sc=1,y=max(a[i][0],a[i][2]);
			else cnt[2]++,awa+=a[i][2],x=a[i][2],b[i].sc=2,y=max(a[i][0],a[i][1]);
			b[i].fs=x-y;
		}
		if(cnt[0]>n/2||cnt[1]>n/2||cnt[2]>n/2){
			re int bh=(cnt[0]>n/2?0:(cnt[1]>n/2?1:2));
			sort(b+1,b+1+n,[&](re pii x,re pii y){return x.sc==bh&&y.sc!=bh||x.sc==y.sc&&x.sc==bh&&x.fs<y.fs;});
			for(re int i=1;i<=cnt[bh]-n/2;i++)awa-=b[i].fs;
		}
		printf("%lld\n",awa);
	}
	return 0;
}
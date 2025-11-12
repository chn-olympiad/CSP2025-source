#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
int T,n,c[maxn],sum[3],ans,all[maxn],cnt;
struct DHC{
	int id,v;
	bool operator < (const DHC b) const {return v>b.v;}
}a[maxn][3];
namespace dhcio{
	inline int read(){
		char ch=getchar();int ret=0,f=1;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
		while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
		return ret*f;
	}
	inline void write(int x){
		if(x<0) x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
}
using namespace dhcio;
void solve(){
	n=read();ans=0;
	for(int i=1;i<=n;i++) a[i][0].id=0,a[i][1].id=1,a[i][2].id=2,a[i][0].v=read(),a[i][1].v=read(),a[i][2].v=read();
	for(int i=1;i<=n;i++) sort(a[i],a[i]+3);
	sum[0]=sum[1]=sum[2]=0;
	for(int i=1;i<=n;i++) sum[c[i]=a[i][0].id]++,ans+=a[i][0].v;
	if(sum[0]<=n/2&&sum[1]<=n/2&&sum[2]<=n/2){write(ans);putchar('\n');return;}
	int id=0,k=0;cnt=0;
	if(sum[0]>n/2) id=0,k=sum[0]-n/2;
	if(sum[1]>n/2) id=1,k=sum[1]-n/2;
	if(sum[2]>n/2) id=2,k=sum[2]-n/2;
	for(int i=1;i<=n;i++)
	  if(c[i]==id) all[++cnt]=a[i][0].v-a[i][1].v;
	sort(all+1,all+1+cnt);
	for(int i=1;i<=k;i++) ans-=all[i];
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}

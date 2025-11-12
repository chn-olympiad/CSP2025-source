#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
namespace Super_Ultra_CZS_Office{
	inline int read(){
		int x=0,f=1;
		char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-')f=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
		return x*f;
	}
	inline void write(int x){
		if(x<0){putchar('-');x=-x;}
		if(x>=10)write(x/10);
		putchar(x%10+'0');return;
	}
}
using namespace Super_Ultra_CZS_Office;
int T;
int n,a[maxn][4],cnt[4],ans,b[maxn],tot;
inline void solve(){
	ans=0;cnt[1]=cnt[2]=cnt[3]=0;n=read();
	for(int i=1;i<=n;++i)for(int j=1;j<=3;++j)a[i][j]=read();
	for(int i=1;i<=n;++i){
		int mxid=1;
		for(int j=2;j<=3;++j)
		if(a[i][j]>a[i][mxid])mxid=j;
		++cnt[mxid];ans+=a[i][mxid];
	}
	int czs=1;for(int i=2;i<=3;++i)if(cnt[i]>cnt[czs])czs=i;
	if(czs!=1){swap(cnt[1],cnt[czs]);for(int i=1;i<=n;++i)swap(a[i][1],a[i][czs]);}
	if(cnt[1]>n/2){
		tot=0;cnt[1]=0;ans=0;
		for(int i=1;i<=n;++i){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
				++cnt[1];
			ans+=max({a[i][1],a[i][2],a[i][3]});
		}
		for(int i=1;i<=n;++i){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				if(a[i][2]>=a[i][3])b[++tot]=a[i][1]-a[i][2];
				else b[++tot]=a[i][1]-a[i][3];
			}
		}
		sort(b+1,b+1+tot);int czr=cnt[1]-(n/2);
		for(int i=1;i<=tot&&i<=czr;++i)ans-=b[i];
	}
	write(ans);putchar('\n'); 
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();while(T--)solve();
	return 0;
}

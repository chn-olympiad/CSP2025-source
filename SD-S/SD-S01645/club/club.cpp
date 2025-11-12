#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+9;
int T,n,a1[N],a2[N],a3[N],x[5][N],cnt[5],ans;
ll fr(){
	ll x=0;
	char c=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}
void init(){
	memset(cnt,0,sizeof cnt);
	memset(x,0,sizeof x);
	ans=0;
}
void solve(){
	n=fr();
	for(int i=1;i<=n;i++){
		a1[i]=fr(),a2[i]=fr(),a3[i]=fr();
		if(a1[i]>=a2[i]&&a1[i]>=a3[i]) ans+=a1[i],x[1][++cnt[1]]=min(a1[i]-a2[i],a1[i]-a3[i]);
		else if(a2[i]>=a1[i]&&a2[i]>=a3[i]) ans+=a2[i],x[2][++cnt[2]]=min(a2[i]-a1[i],a2[i]-a3[i]);
		else if(a3[i]>=a1[i]&&a3[i]>=a2[i]) ans+=a3[i],x[3][++cnt[3]]=min(a3[i]-a2[i],a3[i]-a1[i]);
	}
	int flag=0;
	for(int i=1;i<=3;i++) if(cnt[i]>n/2) flag=i;
	if(flag){
		sort(x[flag]+1,x[flag]+cnt[flag]+1);
		for(int i=1;i<=cnt[flag]-n/2;i++) ans-=x[flag][i];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=fr();
	while(T--){
		init();
		solve();
	}
	return 0;
}


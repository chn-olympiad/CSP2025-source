/*我们你所可以自慰的，想来想去，也还是所谓对于将来的希望。

希望是附丽于存在的，有存在，便有希望，有希望，便是光明。*/
// 混蛋 n/2 限制，我连性质 B 都不会了！ 
#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+3;
using ll=long long;
int a[N],b[N],c[N],t,n,tmpb,tmpc,lim;ll ans;
inline void dfs(int p,int A,int B,int C,ll now){
	if(p>n) return ans=max(ans,now),void();
	if(A<lim) dfs(p+1,A+1,B,C,now+a[p]);
	if(B<lim) dfs(p+1,A,B+1,C,now+b[p]);
	if(tmpc&&C<lim) dfs(p+1,A,B,C+1,now+c[p]);
	return;
}
signed main(){
#ifdef __linux__
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;lim=n>>1,ans=tmpb=tmpc=0;
		for(int i=1;i<=n;++i) cin>>a[i]>>b[i]>>c[i],tmpb|=b[i],tmpc|=c[i];
		if(tmpb||tmpc) dfs(1,0,0,0,0);
		else{
			sort(a+1,a+n+1,greater<int>());
			for(int i=1;i<=lim;++i) ans+=a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}

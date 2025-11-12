#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 500005
int T,n,m,ans;
int a[M][3],c[M],d[M],cnt[4];
std::vector<int>vec;
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::cin>>T;
	while(T--) {
		cnt[0]=cnt[1]=cnt[2]=ans=0,vec.clear();
		std::cin>>n;
		for(int i=1;i<=n;i++) {
			std::cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) c[i]=0;
			else if(a[i][1]>=a[i][2]) c[i]=1;
			else c[i]=2;
			cnt[c[i]]++,ans+=a[i][c[i]];
			std::sort(a[i],a[i]+3),d[i]=a[i][2]-a[i][1];
		}
		for(int i=0;i<3;i++) {
			if(cnt[i]<=n/2) continue;
			for(int j=1;j<=n;j++) if(c[j]==i) vec.push_back(d[j]);
			std::sort(vec.begin(),vec.end());
			for(int j=0;j<cnt[i]-n/2;j++) {
				ans-=vec[j];
			}
		}
		std::cout<<ans<<'\n';
	}
	return 0;
}
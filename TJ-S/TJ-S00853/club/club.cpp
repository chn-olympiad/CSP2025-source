#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=110000;
int a[N][4],t,n;
vector<int>v[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		v[1].clear();v[2].clear();v[3].clear();
		for(int i=1;i<=n;++i){
			if(a[i][1]>=a[i][2] and a[i][1]>=a[i][3])v[1].push_back(i);
			else if(a[i][2]>=a[i][3] and a[i][2]>=a[i][1])v[2].push_back(i);
			else if(a[i][3]>=a[i][1] and a[i][3]>=a[i][2])v[3].push_back(i);
		}
		int ans=0;
		int sz1=v[1].size();
		int sz2=v[2].size();
		int sz3=v[3].size();
		if(sz1<=n/2 and sz2<=n/2 and sz3<=n/2){
			for(int i=1;i<=3;++i){
				for(auto A:v[i])ans+=a[A][i];
			}
			printf("%lld\n",ans);
			continue;
		}
		int id=0;
		vector<int>x;
		for(int i=1;i<=3;++i){
			int num=v[i].size();
			if(num>n/2)id=i;
		}
		for(auto A:v[id]){
			int max1=0;
			for(int j=1;j<=3;++j)if(j!=id)max1=max(max1,a[A][j]);
			x.push_back(a[A][id]-max1);
		}
		sort(x.begin(),x.end());
		int num=v[id].size()-n/2;
		for(int i=1;i<=3;++i){
			for(auto A:v[i])ans+=a[A][i];
		}
		for(int i=0;i<num;++i)ans-=x[i];
		printf("%lld\n",ans);
	}
}

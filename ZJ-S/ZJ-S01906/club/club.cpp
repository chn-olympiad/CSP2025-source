#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int t,n;
struct node{
	int mx,addans;
}e[100005];
vector<int>sum[15];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		int ans=0;
		for(int i=1;i<=3;i++) sum[i].clear();
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%lld %lld %lld",&x,&y,&z);
			if(x>=y&&x>=z){
				e[i].mx=x;
				e[i].addans=x-max(y,z);
				sum[1].push_back(e[i].addans);
				ans+=x;
			}else if(y>=x&&y>=z){
				e[i].mx=y;
				e[i].addans=y-max(x,z);
				sum[2].push_back(e[i].addans);
				ans+=y;
			}else{
				e[i].mx=z;
				e[i].addans=z-max(x,y);
				sum[3].push_back(e[i].addans);
				ans+=z;
			}
		}
		int siz1=sum[1].size(),siz2=sum[2].size(),siz3=sum[3].size();
		int j=0;
		sort(sum[1].begin(),sum[1].end());
		sort(sum[2].begin(),sum[2].end());
		sort(sum[3].begin(),sum[3].end());
		while(siz1>n/2) ans-=sum[1][j],j++,siz1--;
		while(siz2>n/2) ans-=sum[2][j],j++,siz2--;
		while(siz3>n/2) ans-=sum[3][j],j++,siz3--;
		printf("%lld\n",ans);
	}
	return 0;
}

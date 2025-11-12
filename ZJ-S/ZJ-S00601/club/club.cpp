#include<bits/stdc++.h>
#define Maxn 100007
using namespace std;
long long k[Maxn][4];
int n;
int n2;
long long dfs(long long deep,int _1,int _2,int _3){
	if(deep>n)return 0;
	long long maxx=INT_MIN;
	for(int i=1;i<=3;i++){
		long long now=0;
		if(i==1&&_1<n2){
			now+=k[deep][1];
			now+=dfs(deep+1,_1+1,_2,_3);
		}
		if(i==2&&_2<n2){
			now+=k[deep][2];
			now+=dfs(deep+1,_1,_2+1,_3);
		}
		if(i==3&&_3<n2){
			now+=k[deep][3];
			now+=dfs(deep+1,_1,_2,_3+1);
		}
		maxx=max(maxx,now);
	}
	return maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		n2=n/2;
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&k[i][1],&k[i][2],&k[i][3]);
		printf("%lld\n",dfs(1,0,0,0));
	}
	return 0;
}

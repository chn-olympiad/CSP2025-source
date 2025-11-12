#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=510;
int DP[N/2][N/2][N/2];
int a[N][10];
int is_a[100010];
int n;
void A(){
	for(int i=1;i<=n;i++){
		is_a[i]=a[i][1];
	}
	sort(is_a+1,is_a+1+n,greater<int>());
	int sum=0;
	for(int i=1;i<=n/2;i++){
		sum+=is_a[i];
	}
	cout<<sum<<"\n";
}
void work(){
	
	bool is_A=1;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][2]||a[i][3]){
			is_A=0;
		}
	}
	if(is_A){
		A();
		return;
	}
	memset(DP,0,sizeof DP);
	for(int i=1;i<=n;i++){
		for(int j=n/2;j>=0;j--){
			for(int k=n/2;k>=0;k--){
				if(j+k>i)continue;
				int l=i-j-k;
				if(l+j+k!=i)continue;
				if(j)DP[j][k][l]=max(DP[j][k][l],DP[j-1][k][l]+a[i][1]);
				if(k)DP[j][k][l]=max(DP[j][k][l],DP[j][k-1][l]+a[i][2]);
				if(l)DP[j][k][l]=max(DP[j][k][l],DP[j][k][l-1]+a[i][3]);
				
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n/2;j++){
		for(int k=0;k<=n/2;k++){
			int l=n-j-k;
			if(l>n/2)continue;
			ans=max(ans,DP[j][k][l]);
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--){
		work();
	}
	return 0;
}

/*
一个小小的背包
由O(n^4)可优化到O(n^3)
但观察值域很小
DP[i]代表价值为i,体积为DP[i]
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/

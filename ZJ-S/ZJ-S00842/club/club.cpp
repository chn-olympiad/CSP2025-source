#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t_;
int n;
int kai[100009];
int kbi[100009];
int kci[100009];
int f[3][5009][5009];
ll dp[3][50009];

int solve1(){
	sort(kai+1,kai+1+n);
	int gans1=0;
	for(int i=n;i>n/2;i--){
		gans1+=kai[i];
	}
	cout<<gans1<<'\n';
	return 0;
}

int solve2(){
	ll gans1=0;
	int Max=n/2;
	for(int i=1;i<=n;i++){
		for(int ai=0;ai<=Max;ai++){
			int bi=i-ai;
			dp[1][ai]=0;
			if(ai-1>=0){
				dp[1][ai]=max(dp[0][ai-1]+kai[i],dp[1][ai]);
			}
			if(bi-1>=0){
				dp[1][ai]=max(dp[0][ai]+kbi[i],dp[1][ai]);
			}
			gans1=max(gans1,dp[1][ai]);
		}
		for(int ai=0;ai<=Max;ai++){
			dp[0][ai]=dp[1][ai];
			dp[1][ai]=0;
		}
	}
	cout<<gans1<<'\n'; 
	return 0;
}

int solve3(){
	int gans1=0;
	for(int i=1;i<=n;i++){
		gans1+=kai[i];
	}
	cout<<gans1<<'\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t_;
	while(t_){
		t_--;
		cin>>n;
		int ans1=0;
		int sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			cin>>kai[i]>>kbi[i]>>kci[i];
			if(kbi[i]==0 && kci[i]==0){
				sum1++;
			}
			if(kci[i]==0){
				sum2++;
			}
		}
		int Max=n/2;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=Max;j++){
				for(int ij=0;ij<=Max;ij++){
					f[i][j][ij]=0;
				}
			}
		}
		if(n>=9997){
			if(sum1==n){
				solve1();//性质A 
			}
			else{
				if(sum2==n){
					solve2();//性质B 
				}
				else{
					solve3();//性质C 
				}
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int ai=0;ai<=Max;ai++){
				for(int bi=0;bi<=min(Max,i-ai);bi++){
					int ci=i-ai-bi;
					if(ci<0 || ci>Max){
						continue;
					}
					f[1][ai][bi]=0;
					if(ai-1>=0){
						f[1][ai][bi]=max(f[0][ai-1][bi]+kai[i],f[1][ai][bi]);
					} 
					if(bi-1>=0){
						f[1][ai][bi]=max(f[0][ai][bi-1]+kbi[i],f[1][ai][bi]);
					}
					if(ci-1>=0){
						f[1][ai][bi]=max(f[0][ai][bi]+kci[i],f[1][ai][bi]);
					}
					ans1=max(ans1,f[1][ai][bi]);
				}
			}
			for(int ai=0;ai<=Max;ai++){
				for(int bi=0;bi<=Max;bi++){
					f[0][ai][bi]=f[1][ai][bi];
					f[1][ai][bi]=0;
				}
			}
		}
		cout<<ans1<<'\n';
	}
	return 0;
}

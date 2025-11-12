#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 5*1e5+10;
long long n,k;
long long a[N],sum[N]; 
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	long long cnt1=0,cnt0=0;//性质A 
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1){
			cnt1++;
		}
			
		if(a[i]==0)
			cnt0++;
	}
	//性质A特殊判断--k=0 并且a1全为1 
	if(cnt1==n&&k==0){
		if(n%2==0){
			printf("%lld",n/2);
			return 0;
		}	
		else{
			printf("%lld",(n-1)/2);
			return 0;
		}	
	} 
	//k=0 并且ai全为0时 
	if(k==0&&cnt0==n){
		printf("%lld",n);
		return 0;
	} 
	//k=1 并且ai全为0时 
	if(k==1&&cnt0==n){
		printf("0");
		return 0;
	}
	long long ans=0;
	//k=0 ai中有0有1 
	if(k==0&&cnt1+cnt0==n){
		long long l=1;
		ans=cnt0;
		while(l<=n){
			if(a[l+1]==a[l]&&a[l]==1){
				ans++;
				l+=2;
			}else{
				l++;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	//k=1 ai中有0有1
	long long ans1=0,ans2=0; 
	if(k==1&&cnt1+cnt0==n){
		//第一种方案，直接01匹配 
		 long long r = 1;
		 while(r<=n){
		 	if((a[r]==0&&a[r+1]==1)||(a[r]==1&&a[r+1]==0)){
		 		ans1++;
		 		r+=2;
			}else
				r++;
		 }
		 //第二种方案计算1的个数
		 ans2=cnt1;
		 printf("%lld",max(ans1,ans2));
		 return 0;
	} 
	//其余情况
//	long long ans3=0,cnt=0;
//	for(int i=1;i<=n;i++){
//		if(a[i]==k){
//			cnt++;
//			vis[i]++;
//		}
//			
//	}
//	//前缀和
//	for(int i=1;i<=n;i++){
//		sum[i]=sum[i-1]^a[i];
//	}
//	for(int x=1;x<=n;){
//		for(int y=x;y<=n;){
//			if(vis[y]==0&&vis[x]==0){
//				if(sum[y]-sum[x-1]==k){
//					ans3++;
//					x=y+1;
//					y=x;
//				}else{
//					x++;
//				}
//			}
//			y++;
//		}
//		x++;
//	}
//	printf("%lld",ans3);
	return 0;
}

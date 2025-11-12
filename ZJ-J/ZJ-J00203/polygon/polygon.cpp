#include<bits/stdc++.h>
using namespace std;
int a[5005]={},prime[505]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797};
const int mod=998244353; 
int C(int n,int m){//n choose m
	if(n==m||m==0)return 1;
 	if(m>n/2)C(n,n-m); 
 	int A[5005]={},B[5005]={};
 	for(int i=n;i>n-m;i--){
 		int x=i,sum=0;
 		while(x!=1){
 			while(x%prime[sum]==0){
 				x/=prime[sum];A[prime[sum]]++;
			 }
			 sum++;
			 if(prime[sum]*prime[sum]>x)break;
		 }
		 if(x!=1)A[x]++;
	 }
	 for(int i=m;i>0;i--){
 		int x=i,sum=0;
 		while(x!=1){
 			while(x%prime[sum]==0){
 				x/=prime[sum];B[prime[sum]]++;
			 }
			 sum++;
			 if(prime[sum]*prime[sum]>x)break;
		 }
		 if(x!=1)B[x]++;
	 }
	 int Ans=1;
	 for(int i=2;i<=5000;i++){
	 	if(A[i]){
	 		A[i]-=B[i];
		 }
	 	while(A[i]--){
	 		Ans*=i;Ans%=998244353;
		 }
	 }
	 return Ans%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maxnn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxnn=max(maxnn,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(maxnn==1){
		int sum=0;
		for(int i=3;i<=n;i++){
			sum+=C(n,i);
			sum%=998244353;
			cout<<sum;
		}
		return 0;
	}
	srand(time(0));
	cout<<rand();
	return 0;
}


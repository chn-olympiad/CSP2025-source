#include<bits/stdc++.h>
using namespace std;
int n,lens[5001];
long long ans=0;
/*
int sum(vector<int> a,int n){
	int result=0;
	for(int i=0;i<n;i++)result+=a[i];
	return result;
}
int poly(int begin,int end,int depth,vector<int> nums,int lens[5001],int maxn,int n){
	int ans=0;
	for(int i=begin;i<end;i++){
		
	    if(sum(nums,n)>lens[i]>max(maxn,lens[i])*2){
	    	ans++;
		}
		if(depth){
			vector<int> nums1 = nums;
			nums1.push_back(i);
			ans+=poly(i+1,end,depth-1,nums1,lens,max(maxn,lens[i]),n-depth);
		}
		else return ans;
	}
	return ans;
}
*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>lens[i];
//	cout<<poly(0,n,n,vector<int>(),lens,-1,n)<<'\n';
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int l=j+1;l<n;l++){
				if(lens[i]+lens[j]+lens[l]>max(lens[i],max(lens[j],lens[l]))*2){
					ans++;
				}
			}
		}
	}
	cout<<ans*3%998244353<<'\n';
	return 0;
}


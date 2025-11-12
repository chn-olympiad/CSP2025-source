#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long arr[5010];
bool vis[5010];
long long ans=0;
int n;
int search(int l,int r,long long num){
	int sum=l-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(arr[mid]<num){
			sum=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return sum;
}
void dfs(int len,int l,long long num){
	if(len==1){
		ans+=search(l,n,num)-l+1;
		ans%=mod;
		return ;
	}
	if(len>n-l+1){
		return ;
	}
	for(int i=l;i<=n;i++){
		dfs(len-1,i+1,num+arr[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	if(n<=2){
		cout<<"0\n";
		return 0;
	}
	if(n==3){
		if(arr[1]+arr[2]>arr[3]){
			cout<<"1\n";
			return 0;
		}else{
			cout<<"0\n";
			return 0;
		}
	}
	for(int len=3;len<=n;len++){
		dfs(len,1,0);
	}
	cout<<ans;
	return 0;
}
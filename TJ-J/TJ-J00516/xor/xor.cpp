#include<bits/stdc++.h>
using namespace std;

struct area{
	int l;
	int r;
};

bool ___(area a,area b);

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int arr[n+10];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	vector<area> dp;
	int a=0;
	for(int i=1;i<=n;i++){
		a=0;
		for(int j=i;j<=n;j++){
			a=a^arr[j];
			if(a==k){
				dp.push_back({i,j});
			}
		}
	}
	sort(dp.begin(),dp.end(),___); 
	int cnt=0,l1=dp[0].r+1,r1;
	for(int i=0;i<dp.size();i++){
		if(dp[i].r<l1){
			cnt++;
			r1=dp[i].r;
			l1=dp[i].l;
		}
		else if(dp[i].r<=r1&&dp[i].r-dp[i].l<r1-l1){
			r1=dp[i].r;
			l1=dp[i].l;
		}
	}
	cout<<cnt;
	return 0;
} 

bool ___(area a,area b){
	return a.r>b.r;
}

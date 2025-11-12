#include<bits/stdc++.h>
using namespace std;
vector<int>path;
vector<pair<vector<int>,int>>result;
int a[5002];
void backtracking(int n,int startIndex,int sum){
	if(path.size()>=3)result.push_back({path,sum});
	for(int i=startIndex;i<=n;i++){
		path.push_back(a[i]);
		sum+=a[i];
		backtracking(n,i+1,sum);
		sum-=a[i];
		path.pop_back();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	backtracking(n,1,0);
	int sum=0;
	for(int i=0;i<result.size();i++){
		auto nums=result[i].first;
		if(nums[nums.size()-1]*2 < result[i].second){
			sum++;
			sum=sum%998244353;
		}
	}
	cout<<sum;
	return 0;
}
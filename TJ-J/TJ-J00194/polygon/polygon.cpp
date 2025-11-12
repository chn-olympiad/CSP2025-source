#include <iostream>
#include <vector>
using namespace std;
long long ans;vector<int>cho;
int a[5050],n;
void dfs(int i,long long sum,int max){
	if(i==n){
		if(cho.size()<3)return;
		if(sum>max*2)ans=(ans+1)%998244353;
		return;
	}
	cho.push_back(a[i]);
	dfs(i+1,sum+a[i],(max<a[i]?a[i]:max));
	cho.pop_back();
	dfs(i+1,sum,max);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int max=-1;
	for(int i=0;i<n;i++)cin >> a[i],max=(max>a[i]?max:a[i]);
	if(max==1){
		for(int i=3;i<=n;i++){
			ans=ans+(n-(i-1));
			ans=ans%998244353; 
		}
	}
	else dfs(0,0,-1);
	cout << ans;
	return 0;
}

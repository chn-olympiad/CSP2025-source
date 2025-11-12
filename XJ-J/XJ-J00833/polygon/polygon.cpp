#include<iostream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int a[5005];
int vis[5005];
long long cnt;
int n;
void dfs(int edge,int maxi,int sum){
	if(edge>=3){
		if(sum>2*a[maxi]){
			cnt++;
			cnt%=998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&i>maxi){
			vis[i]=1;
			if(a[maxi]<a[i]) maxi=i;
			dfs(edge+1,maxi,sum+a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}

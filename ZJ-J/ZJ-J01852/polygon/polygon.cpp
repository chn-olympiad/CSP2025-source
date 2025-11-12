#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int x[5005];
int ans;
/**
5
1 2 3 4 5

5
2 2 3 8 10
*/
bool judge(int p){
	int sum=0;
	for(int i=0;i<p;i++){
		sum+=x[i];
		if(sum>x[p-1]*2){
			return true;
		}
	}
	return false;
}

void dfs(int now,int t){
	if(now>=3){
		if(judge(now)){
			ans=(ans+1)%998244353;
		}
	}
	if(now==n){
		return;
	}
	for(int i=t+1;i<n;i++){
		x[now]=a[i];
		dfs(now+1,i);
	}
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(0,-1);
	cout<<ans;
	return 0;
}

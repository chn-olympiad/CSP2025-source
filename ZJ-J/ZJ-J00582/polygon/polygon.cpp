#include<bits/stdc++.h>

using namespace std;
int n,a[5010];
long long ans=0;
int sum=0,biao=0;
void dfs(int st,int maxi){
	if(st>n){
		if(sum-a[maxi]>a[maxi]&&biao>2){
			ans+=1;
		}
		return;
	}
	sum+=a[st];
	biao+=1;
	dfs(st+1,st);
	sum-=a[st];
	biao-=1;
	dfs(st+1,maxi);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	dfs(1,0);
	cout<<ans;
	return 0;
}


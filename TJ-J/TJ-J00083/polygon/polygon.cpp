#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int k,long long sum,int maxx){
	if(k==n){
		if(sum>maxx*2){
			ans++;
		}
		return;
	}
	dfs(k+1,sum,maxx);
	dfs(k+1,sum+a[k+1],a[k+1]);
}
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,a[1],a[1]);
	dfs(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout); 
} 

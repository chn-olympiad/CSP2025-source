#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005],ans,vis[5005];
void dfs(int x,int s){
	if(x==n+1) return;
	s++;
	for(int i=x+1;i<=n;i++){
		vis[s]=a[i];
		dfs(i,s);
		int sum=0;
		for(int j=1;j<=s;j++) {
			sum+=vis[j];
//			cout<<vis[j]<<' ';
		}
		if(s>=3&&sum>vis[s]*2){
			ans++;
			ans%=N;
//			cout<<"yes "<<ans;
		} 
//		cout<<endl;	
	}
	return;
}
int main(){
	freopen("polygon4.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<ans;
	return 0;
}

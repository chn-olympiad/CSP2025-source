#include<bits/stdc++.h>
using namespace std;
int n,max=0,cnt=0;
int ans[5010];
void bfs(int k,int start,int end){
	if(k=n+1){
		return;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]>max)ans[i]=max;
	}
	for(int i=start;i<=end;i++){
		if(ans[++i]>2*max)cnt++;
	}
	cout<<cnt%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon,out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ans[i];
	bfs(3,1,1);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int stick[5001];
int ans,n;
void DFS(int now,int sum,int mx){
	if(now>n){
		if(sum>mx*2)ans++;
		return ;
	}
	DFS(now+1,sum+stick[now],stick[now]);
	DFS(now+1,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stick[i];
	}
	sort(stick+1,stick+n+1);
	DFS(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
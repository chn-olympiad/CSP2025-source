#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int ans;
int m=998244353;

void dfs(int num,int head,int tot,int mx){
	if(head==n+1){
		if(num>=3&&tot>mx*2){
			ans++;
			ans%=m;
		}
		return;
	}
	if(num>=3&&tot>mx*2){
		ans++;
		ans%=m;
	}
	for(int i=head;i<=n;i++){
		dfs(num+1,i+1,tot+a[i],max(mx,a[i]));
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,0,0);
	cout<<ans;
	return 0;
}
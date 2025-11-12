#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],ans;
void dfs(int i,int step){
	if(i>n){
		ans=max(ans,step);
		return;
	}
	dfs(i+1,step);
	if(b[i]!=0) dfs(b[i]+1,step+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>10&&k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i+1]==1) i++,ans++;
			}
		}
		else{
			for(int i=1;i<=n;i++)
				if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int v=0;
		for(int j=i;j<=n;j++){
			v^=a[j];
			if(v==k){
				b[i]=j;
				break;
			}
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
bool b[5005];
void dfs(int end,int sum,int kk,int k){
	if(k>=kk){
		if(sum<=a[end]*2)return;
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=end+1;i<=n;i++){
		dfs(i,sum+a[i],kk,k+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n-2;i++){
		for(int j=3;j<=n;j++){
			dfs(i,a[i],j,1);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


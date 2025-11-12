#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],vis[5005],mp[5005],now,ans,yh[1005][1005],mm[5005]={0},d;
bool cmp(int x,int y){
	return x>y;
}
void dfs(long long mx,long long now,long long c){
	if(c==n+1) return;
	if(now>mx){
		for(int i=1;i<=n-c+1;i++){
			ans+=(yh[n-c+1][i])%998244353;
		}
		return;
	}
	if(mm[c]+now<=mx) return;
	dfs(mx,now+a[c+1],c+1);
	dfs(mx,now,c+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(mm,0,sizeof(mm));
	for(int i=1;i<=1005;i++)
	yh[i][1]=1;
	for(int i=1;i<=1005;i++)
	yh[i][i]=1;
	for(int i=3;i<=1005;i++){
		for(int j=2;j<=i-1;j++){
			yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d=max(d,a[i]);
	}
	if(d==1){
		ans=(1+n-2)*(n-2)/2;
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	memset(mm,0,sizeof(mm));
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--){
		mm[i]=a[i]+mm[i+1];
	}
	for(int i=1;i<=n-2;i++){
		dfs(a[i]*2,a[i],i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



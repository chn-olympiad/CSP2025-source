#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum,f[5010][5010];
int vis[100010],p=998244353;
void dfs(int now,int maxx,int ant){
	if(now>maxx*2){
		sum++;
		sum%=p;
	}
	for(int i=ant+1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		dfs(now+a[i],max(maxx,a[i]),i);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		long long summ=0;
		for(int i=3;i<=n;i++){
			int l=1,r=n;
			long long sum1=1,sum2=1;
			for(int j=0;j<i;j++){
				sum1=sum1*(r-j);
				sum1%=p;
			}
			for(int j=0;j<i;j++){
				sum2=sum2*(l+j);
				sum2%=p;
			}
			summ=summ+sum1/sum2;
			summ%=p;
		}	
		cout<<summ;
	}
	else{
		sort(a+1,a+n+1);
		dfs(0,0,0);
		cout<<sum;	
	}
	return 0;
}

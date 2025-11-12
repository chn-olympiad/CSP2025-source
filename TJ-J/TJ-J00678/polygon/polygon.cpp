#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int vis[5010];
long long ans=0;
void dfs(int s,int m1,int m,int maxx,int sum){
	if(m1==0){
		if(sum>2*maxx){
			ans++;
			//cout<<s<<' '<<m1<<' '<<m<<' '<<maxx<<' '<<sum<<' '<<"Yes"<<endl;
		}else{
			//cout<<s<<' '<<m1<<' '<<m<<' '<<maxx<<' '<<sum<<' '<<"No"<<endl;
		}
		return;
	}
	for(int i=s+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			int maxxx=max(maxx,a[i]);
			int summ=sum+a[i];
			int m2=m1-1;
			//cout<<i<<' '<<m2<<' '<<m<<' '<<maxxx<<' '<<summ<<endl;
			if(m2+i-1<=n) dfs(i,m2,m,maxxx,summ);
			vis[i]=0;
		}
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<j<<' '<<i<<' '<<i<<' '<<0<<' '<<0<<endl;
			vis[j]=1;
			if(j+i-1<=n) dfs(j,i-1,i,a[j],a[j]);
			vis[j]=0;
		}
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
5
1 2 3 4 5
*/
/*
5
2 2 3 8 10
*/
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

1042392
*/
/*

*/

#include<bits/stdc++.h> 
using namespace std;
const int N=5e3+5;
long long int n,a[N],sum,maxx,tot;
void dfs(int i,int k,int x,long long int sum1,long long int maxx1){
//	cout<<i<<' '<<k<<' '<<x<<' '<<sum1<<' '<<maxx1<<'\n';
	if(k==x){
//		cout<<sum<<' '<<maxx<<'\n';
		sum=sum1,maxx=maxx1;
		if(sum>maxx*2)tot=(tot+1)%998244353;
		return;
	}	
	if(i>n)return;
	int maxxx=max(a[i],maxx1);
	dfs(i+1,k,x,sum1,maxx1);
	dfs(i+1,k+1,x,sum1+a[i],maxxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			sum=0,maxx=0;
			dfs(j,0,i,0,0);
		}
	} 
	cout<<tot;
	return 0;
}

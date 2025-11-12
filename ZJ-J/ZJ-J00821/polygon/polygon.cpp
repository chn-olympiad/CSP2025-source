#include<bits/stdc++.h>
using namespace std;
int a[5005],ans,n;
void dfs(int f,int x,int sum,int maxx,int x2,int sum2,int maxx2){
	if(x>=3&&sum>2*maxx){
		if(x2==x&&sum2==sum&&maxx2==maxx){
			return ;
		}
		//cout<<f<<" "<<x<<" "<<sum<<" "<<maxx<<endl;
		ans++;
		ans%=998244353;
		
	}
	if(f>n){
		return ;
	}
	for(int i=0;i<=1;i++){
		maxx=max(maxx,a[f]*i);
		dfs(f+1,x+(1*i),sum+(a[f]*i),maxx,x,sum,maxx);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0,0,0,0);
	cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long anss;
int n;
void dfs(long long sum,int sheng,int r,long long maxx){
	if(sum>maxx*2&&sheng==0){
		anss++;
		//cout<<sum<<" "<<maxx<<" "<<r<<endl;
		return;
	}
	if(r>n) return;
	if(sheng==0) return;
	dfs(sum+a[r],sheng-1,r+1,max(maxx,a[r]));
	dfs(sum,sheng,r+1,maxx);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(maxx==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			long long sum=0;
			if(i>n/2) sum=n-i;
			else sum=i;
			long long cheng=1;
			long long chu=1;
			for(int j=i;j>=1;j--){
				cheng*=(n-j+1);
				chu*=j;
			}
			ans+=cheng/chu;           		
		}cout<<ans<<endl;
		return 0;
	}
	
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,1,0);
	}
	cout<<anss<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],anss;
void dfs(int q,int w,int e,int r,int t){
	if(q == 0&&w>e*2){
		anss++;
	}
	for(int i = t;i<n;i++){
		if(a[i]>=0){
			a[i]*=-1;
			if(a[i]*-1>e) dfs(q-1,w+a[i]*-1,a[i]*-1,r*10+a[i]*-1,i);
			else dfs(q-1,w+a[i]*-1,e,r*10+a[i]*-1,i);
			a[i]*=-1;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	} 
	for(int i = 0;i<n;i++){
		cin>>a[i];
		m = max(a[i],m);
	} 
	if(n == 3){
		if(2*m>a[0]+a[1]+a[2]) cout<<1;
		else cout<<0;
		return 0;
	} 
	if(m == 1){
		int anss = 0;
		for(int i = 3;i<=n;i++){
			int ans = 1;
			for(int j = n;j>=n-i;j--){
				ans*=j;
			}
			anss+=ans;
		}
		cout<<anss;
		return 0;
	}
	for(int i = 3;i<=n;i++){
		dfs(i,0,0,0,0);
	}
	cout<<anss;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010][3],ans,num;
bool cmp(int x,int y){
	return x<y;
}
void dfs(int x,int y,int k,int dnum){
	if(k==0){
		if(dnum>2*a[y]){
			ans++;
		}
	}
	else {
		for(int i=x-1;i>=k;i--){
			dfs(i,y,k-1,dnum+a[i]);
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
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=3;i--){
		for(int j=1;j<=i-2;j++){
			dfs(i,i,i-j,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
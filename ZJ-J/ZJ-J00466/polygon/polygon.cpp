#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
void dfs(int x,int w,int h,int g){
	if(w==3){
		if(h>a[g]*2){
			ans+=pow(2,max(0,x-1));
		}
		return;
	}
	for(int i=x-1;i>=1;i--){
		dfs(i,w+1,h+a[i],g);
		
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=5;i>=3;i--){
		dfs(i,1,a[i],i);
	}
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


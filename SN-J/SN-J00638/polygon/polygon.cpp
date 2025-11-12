#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cc,b[5005];
int dfs(int f,int ans,int maxx,int s){
	if(ans>maxx*2){
		cc++;
		//cout<<ans<<" "<<maxx<<endl;
	}
	if(s>n){
		return 0;
	}
	for(int i=s;i<=n;i++){
		//if(!b[i]){
		//	b[i]=1;
			dfs(f+1,ans+a[i],max(maxx,a[i]),i+1);
		//	b[i]=0;
	//	}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,1);
	cout<<cc;
	return 0;
}

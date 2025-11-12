#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ret[5005],ans;
void q(int y,int o){
	if(y>o){
		return;
	}
	for(int i=y;i<=n;i++){
		ret[y]=i;
		q(y+1,o);
	}
	int sum=0,c=ret[1];
	for(int i=1;i<o;i++){
		sum+=ret[i];
		c-=ret[i];
	}
	if(sum>ret[o]&&ret[o]>c){
		ans++;
	}
	memset(ret+0,0,5005);
}
void dfs(int x){
	if(x>n){
		return;
	}
	q(1,x);
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(3);
	cout<<ans;
	return 0;
}


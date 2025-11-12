#include<bits/stdc++.h>
using namespace std;
int n,o,p=0;
int a[5005];
long long j=0;
void dfs(int x,long long y){
	if(y>a[x-1]*2&&x!=1){
		p++;
	}
	if(x==n+1){
		return;
	}
	x=x+1;
	dfs(x,y+a[x-1]);
	dfs(x,y);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	cout<<p;
	return 0;
}
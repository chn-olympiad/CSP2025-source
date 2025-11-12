#include<bits/stdc++.h>
using namespace std;
const int Md=998244353;
int n,a[5001],cnt;
void dfs(int x,int y,int z,int sum,int maxl){
	if(y==z) for(int i=x;i<=n;i++){
		int summ=sum+a[i],maxll=max(maxl,a[i]);
		if(summ>2*maxll) cnt=(cnt+1)%Md;
	}
	else for(int i=x;i<=n-z+y;i++){
		int summ=sum+a[i],maxll=max(maxl,a[i]);
		dfs(i+1,y+1,z,summ,maxll);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(1,1,i,0,0);
	}
	cout<<cnt;
	return 0;
}

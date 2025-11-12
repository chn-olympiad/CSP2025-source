#include <bits/stdc++.h>
using namespace std;
int n,l,sum;
int a[5005];
/*bool vis[5005];
int d[5005];
int b[5005];
int lr(int r){
	for(int i=1;i<=r;i++){
		b[i]=b[i-1]+a[i];
	}
	return b[r];
}
void dfs(,n,m){
	if(m>n) return ;
	for(int i=1;i<=n;i++){
		int nw=a[i];
		if()
	}
}*/
int main(){
	freopen(polygon.in,"r",stdin);
	freopen(polygon.out,"w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>l) l=a[i];
		sum+=a[i];
	}
	if(n==3&&sum>l*2) cout<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

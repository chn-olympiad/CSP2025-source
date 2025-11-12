#include<bits/stdc++.h>
using namespace std;
long long n,p=998244353,maxn,a[10010],ans;
long long dfs(int x,int y,int z,int g,int s){
	if(z==g&&y>s)ans++;
	if(x>n)return 0;
	if(z>=g)return 0;
	dfs(x+1,y+a[x],z+1,g,s);
	dfs(x+1,y,z,g,s);
	return 0;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n-i;j++)
			dfs(i+1,0,0,j,a[i]);
	}
	cout<<ans%p;
	return 0;
}

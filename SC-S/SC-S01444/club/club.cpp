#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,a[100005],b[100005],c[100005],ans,aa,bb,cc;
int dfs(int x,int sum){
	if(x==n+1)return sum;
	int s=0;
	aa++;
	if(aa*2<=n)s=max(s,dfs(x+1,sum+a[x]));
	aa--,bb++;
	if(bb*2<=n)s=max(s,dfs(x+1,sum+b[x]));
	bb--,cc++;
	if(cc*2<=n)s=max(s,dfs(x+1,sum+c[x]));
	cc--;
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		aa=0,bb=0,cc=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		cout<<dfs(1,0)<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n;
int a[10101];
int ret=0;
void dfs(int x,int mx,int sum,int ge){
	
	
	if(sum>mx*2&&ge>=3){
//		cout<<x<<" "<<sum<<" "<<mx<<" "<<ge<<"\n";
		ret++;
		ret%=N;
		if(x>n)return;
		dfs(x+1,a[x],sum+a[x],ge+1);
		return;
	}
	if(x>n)return;
	dfs(x+1,a[x],sum+a[x],ge+1);
	dfs(x+1,mx,sum,ge);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(2,1,a[1],1);
	dfs(2,0,0,0);
	cout<<ret;
	return 0;
}
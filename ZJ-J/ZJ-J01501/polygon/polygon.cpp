#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,k,ans;
int a[100005];
int b[100005];
int pd(){
	int sum=0;
	for(int i=2;i<=k;i++){
		sum+=a[b[i]];
	}
	if(sum<=a[b[1]])return 0;
	return 1;
}
void dfs(int x,int step){
	if(step==k){
		if(pd()){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=x+1;i<=n;i++){
		b[step+1]=i;
		dfs(i,step+1);
		b[step+1]=0;
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=3;i<=n;i++){
		k=i;
		dfs(0,0);
	}
	cout<<ans<<endl;
	return 0;
}
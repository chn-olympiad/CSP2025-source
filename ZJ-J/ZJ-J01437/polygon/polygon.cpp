#include <bits/stdc++.h>
using namespace std;
int n;long long sum2=0;
int a[5005];
bool b[5005];
bool ca(int p){
	int sum=0,ma=0,i=1;
	for(int i=1;i<=p;i++){
		if(b[i]==true){
			sum+=a[i];
			ma=max(ma,a[i]);
		}
	}
	if(ma*2<sum){
		return true;
	}else{
		return false;
	}
}
void dfs(int p){
	if(p>n){
		return ;
	}
	b[p]=false;
	dfs(p+1);
	b[p]=true;
	if(ca(p)){
		sum2++;
		sum2%=998244353;
	}
	dfs(p+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<sum2;
	return 0;
}

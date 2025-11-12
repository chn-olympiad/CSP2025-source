#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
long long ans;
void dfs(int step,int num,int add,int maxm){
	if(num>=3){
		if(add>maxm*2){
			ans++;
			ans%=998244353;
		}
	}
	for(int i=step+1;i<n;i++){
		dfs(i,num+1,add+a[i],max(maxm,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3&&max(a[0],max(a[1],a[2]))*2<a[0]+a[1]+a[2]){
		cout<<1;
	}else if(n==3&&max(a[0],max(a[1],a[2]))*2>=a[0]+a[1]+a[2]){
		cout<<0;
	}else {
		for(int i=0;i<n;i++){
			dfs(i,1,a[i],a[i]);
		}
		cout<<ans;
	}
	return 0;
}
/*5
1 2 3 4 5*/

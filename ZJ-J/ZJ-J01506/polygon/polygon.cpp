#include<bits/stdc++.h>
using namespace std;
long long ans,a[5005],n;
long long t[10];
void dfs(int m,int cnt,int sum,int mo){
	if(m>n) return;
	if(cnt>1){
		if(t[m]){
			if(sum+a[m]>a[m]*2){
				ans++;
				ans%=998244353;
			}
		} 
		else{
			if(sum>a[mo]*2){
				ans++;
				ans%=998244353;
			}
		}
	}
	t[m]=0;
	dfs(m+1,cnt,sum,mo);
	t[m]=1;
	dfs(m+1,cnt+1,sum+a[m],m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

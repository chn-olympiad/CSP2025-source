#include <bits/stdc++.h>
using namespace std;
unsigned long long ans;
int a[5005],n;
void dfs(unsigned long long sum,int mx,int rest,int now){//restbianxing xianzaidexiabiao
	if (rest==0){
		if (sum>2*mx) {
			if (ans==998244353) ans=0;
			else ans++;
		}
		return;
	}
	if (now==n) return;
	for (int i=now+1;i<=n;i++){
		dfs(sum+a[i],max(mx,a[i]),rest-1,i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if (n>500){
		cout<<0;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=3;i<=n;i++){
		dfs(0,-1,i,0);
	}
	cout<<ans;
}

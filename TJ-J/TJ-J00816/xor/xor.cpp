#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5;
ll n,a[N],cnt=0,k;
bool flag[N]={0};
int dfs(int x){
	for(int i=x;i<=n;i++){
		if(flag[i]==1){
			return i-1;
		}
	}
	return n-x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k&&flag[i]==0){
			cnt++;
			flag[i]==1;
		}
	}
	for(int i=1;i<=n;i++){
		if(flag[i]!=1){
			ll ans;
			for(int j=i;j<=dfs(j);j++){
				ans=a[i]|a[j];
				if(ans==k){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

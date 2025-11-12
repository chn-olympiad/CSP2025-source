#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[5005];
bool f=true;
int ans1;
void dfs(int x,int sum,int maxn,int c){
	if (x > n){
		if (c >= 3){
			if (sum > 2*maxn){
				ans1++;
				ans1%=Mod;
			}
		}
		return;
	}
	dfs(x+1,sum+a[x],max(maxn,a[x]),c+1);
	dfs(x+1,sum,maxn,c);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i] > 1) f=false;
	} 
	sort(a+1,a+1+n);
	if (n <= 20){
		dfs(1,0,0,0);
		cout<<ans1%Mod;
		return 0;
	}
	if (f){
		cout<<((n-1)*(n-2)/2)%Mod;
		return 0;
	}
	return 0;
}

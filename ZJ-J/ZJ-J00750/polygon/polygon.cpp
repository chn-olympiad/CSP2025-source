#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5001],ans,sum;
bool f[5001];
void dfs(int x,int s){
	s -= a[x];
	f[x] = 1;
	int maxx;
	for(int i = n;i >= 1;i--){
		if(f[i] == 0){
			maxx = a[i];
			break;
		}
	}
	if(s > 2*maxx){
		ans++;
	}
	for(int i = x+1;i <= n;i++){
		if(f[i])
			continue;
		dfs(i,s);
		f[i] = 0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i =1;i <= n;i++){
		cin>>a[i];
		sum += a[i];
	}
	sort(a+1,a+n+1);
	if(sum > a[n]*2)
		ans++;
	for(int i = 1;i <= n;i++){
		memset(f,0,sizeof(f));
		dfs(i,sum);
	}
	cout<<ans;
	return 0;
}
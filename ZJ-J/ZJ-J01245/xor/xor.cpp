#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans;
void solve(int begin){
	int minn=n,flag=0;
	for(int i=begin;i<=minn;i++){
		long long xr=0;
		for(int j=i;j<=minn;j++){
			xr^=a[j];
			if(xr==k){
				minn=j;
				flag=1;
				break;
			}
		}
	}
	if(flag){
		ans++;
		solve(minn+1);
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	solve(1);
	cout<<ans;
	return 0;
}

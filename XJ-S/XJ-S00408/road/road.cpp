#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x;
	int a[100005];
	for(int i=1;i<=m;i++){
		cin>>x>>x>>a[i];
	}
	sort(a+1,a+m+1);
	int sum=0;
	for(int i=1;i<=n-1;i++){
		sum+=a[i];
	}
	cout<<sum;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	swap(n,m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		sum+=(a[i]>a[1]);
	}
	cout<<sum/m+1<<" "<<(((sum/m+1)&1)?(sum%m+1):(m-sum%m));
	return 0;
}

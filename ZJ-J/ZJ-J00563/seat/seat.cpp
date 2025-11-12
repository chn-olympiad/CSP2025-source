#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[1010];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int j=a[1];
//	cout<<j<<"\n";
	sort(a+1,a+1+n*m);
//	for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
//	cout<<"\n";
	int k=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==j) k=n*m-i+1;
	}
//	cout<<k<<"\n";
	int ans1,ans2;
	ans1=(k+n-1)/n;
	if(ans1%2==1){
		if(k%n) ans2=k%n;
		else ans2=n;
	}else{
		ans2=m-k%n+1;
	}cout<<ans1<<" "<<ans2;
	return 0;
}

